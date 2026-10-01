#include "base/memory.h"

#include <psx/malloc.h>
#include <psx/stdio.h>

static memory_manager_t *g_MemoryManager = NULL;

/* Reserved .sbss slot directly after the manager pointer.  It is never
 * referenced, but old gcc still allocates storage for it, so it must stay to
 * keep the gp-relative data layout identical to the original. */
static void *g_MemoryManagerPad = NULL;

/* Block header layout: the low 28 bits of `header` hold the byte size, the top
 * nibble holds the free / previous-free flags.  The footer is the back-pointer
 * written in the last word of every block. */
#define BLOCK_SIZE(block)          ((block)->header & 0x0FFFFFFF)
#define BLOCK_NEXT(block)          ((memory_block_t *)((u8 *)(block) + BLOCK_SIZE(block)))
#define BLOCK_FOOTER(block)        (*(memory_block_t **)((u8 *)(block) - 4))
#define BLOCK_FROM_PAYLOAD(payload) ((memory_block_t *)((u8 *)(payload) - 4))

memory_manager_t *memory_create_manager(u32 size, s32 unused) {
    long poolSize;
    memory_manager_t *manager;

    poolSize = size;
    if (poolSize < 0x400U) {
        poolSize = 0x400;
    }
    manager = psyq_malloc_malloc(poolSize + 0x20);
    if (manager != NULL) {
        manager->pool = manager->blocks;
        manager->pool_size = poolSize;
        memory_setup_manager(manager);
    } else {
        printf("bMemPMgr = %p, poolSize = %ld in BMemPMgrInit\n", manager, poolSize);
    }
    return manager;
}

void memory_set_manager(memory_manager_t *manager) {
    g_MemoryManager = manager;
}

void memory_free_raw(void *ptr) {
    psyq_malloc_free(ptr);
}

void memory_setup_manager(memory_manager_t *managerParam) {
    memory_manager_t *manager;
    memory_block_t *block;
    memory_block_t *endBlock;

    manager = g_MemoryManager;
    if (manager == NULL) {
        manager = managerParam;
    }
    manager->ready = 1;
    block = manager->pool;
    manager->head = block;
    manager->tail = block;
    block->header = manager->pool_size | 0x40000000;
    manager->head->next = NULL;
    manager->tail->prev = NULL;
    endBlock = BLOCK_NEXT(block);
    BLOCK_FOOTER(endBlock) = block;
    endBlock->header = 0x80000000;
}

/*
 * First-fit scan of the free list starting at the head. A block big enough is
 * unlinked and carved into the trailing remainder when that remainder is at
 * least one minimum block (0x10 bytes including footer). The first/last links
 * of the manager are repaired per unlink half, so the target reloads
 * block->next / block->prev in each half instead of caching them.
 */
void *memory_allocate_mem(u32 size, void *pool) {
    memory_manager_t *manager;
    memory_block_t *block;
    void *payload;
    memory_block_t *nextBlock;
    memory_block_t *unusedNext;
    u32 blockSize;
    u32 padded;

    memory_set_lock(1);
    payload = NULL;
    manager = g_MemoryManager;
    if (manager == NULL) {
        manager = pool;
    }
    if (size != 0) {
        if (size & 0x3) {
            padded = size + 4;
            size = padded - (size & 0x3);
        }
        if (size < 0xC) {
            size = 0xC;
        }
        block = manager->head;
        size += 4;
        while (block != NULL) {
            blockSize = block->header & 0x0FFFFFFF;
            if (blockSize >= size) {
                block->header &= 0xBFFFFFFF;
                payload = &block->next;
                if (blockSize < size + 0x10) {
                    nextBlock = BLOCK_NEXT(block);
                    nextBlock->header &= 0x7FFFFFFF;
                    {
                        memory_block_t *prevLink;
                        memory_block_t *nextLink;

                        prevLink = block->prev;
                        nextLink = block->next;
                        if (nextLink != NULL) {
                            nextLink->prev = prevLink;
                        } else {
                            manager->tail = prevLink;
                        }
                    }
                    {
                        memory_block_t *prevLink;
                        memory_block_t *nextLink;

                        prevLink = block->prev;
                        nextLink = unusedNext = block->next;
                        if (prevLink != NULL) {
                            prevLink->next = nextLink;
                        } else {
                            manager->head = nextLink;
                        }
                    }
                } else {
                    block->header = (block->header & 0xF0000000) | size;
                    nextBlock = BLOCK_NEXT(block);
                    nextBlock->header = (blockSize - size) | 0x40000000;
                    nextBlock->next = block->next;
                    nextBlock->prev = block->prev;
                    {
                        memory_block_t *nextLink = block->next;

                        if (nextLink != NULL) {
                            nextLink->prev = nextBlock;
                        } else {
                            manager->tail = nextBlock;
                        }
                    }
                    {
                        memory_block_t *prevLink = block->prev;

                        if (prevLink != NULL) {
                            prevLink->next = nextBlock;
                        } else {
                            manager->head = nextBlock;
                        }
                    }
                    BLOCK_FOOTER(BLOCK_NEXT(nextBlock)) = nextBlock;
                }
                break;
            }
            block = block->next;
        }
    }
    memory_set_lock(0);
    return payload;
}

/*
 * Returns a block to the pool. A free lower neighbour is found through the
 * footer stored just before the payload, and a free upper neighbour through
 * the next block header; both are coalesced in. The merged block is pushed on
 * the head of the free list and its follower gets the PREV_FREE flag.
 * Note the target reloads next/prev inside each unlink half, and the upper
 * unlink reuses the now-dead `nextSize` slot for its NULL test.
 */
void *memory_free_mem(void *ptr, void *pool) {
    memory_manager_t *manager;
    memory_block_t *block;
    memory_block_t *next;
    u32 nextFree;

    memory_set_lock(1);
    manager = g_MemoryManager;
    if (manager == NULL) {
        manager = pool;
    }
    if (ptr != NULL) {
        block = BLOCK_FROM_PAYLOAD(ptr);
        next = BLOCK_NEXT(block);
        nextFree = next->header & 0x40000000;
        if (block->header & 0x80000000) {
            u32 freedSize = block->header & 0x0FFFFFFF;

            block = BLOCK_FOOTER(block);
            block->header = (block->header & 0xF0000000) |
                            (freedSize + (block->header & 0x0FFFFFFF));
            {
                memory_block_t *prevLink = block->prev;
                memory_block_t *nextLink = block->next;

                if (nextLink != NULL) {
                    nextLink->prev = prevLink;
                } else {
                    manager->tail = prevLink;
                }
            }
            {
                memory_block_t *nextLink = block->next;
                memory_block_t *prevLink = block->prev;

                if (prevLink != NULL) {
                    prevLink->next = nextLink;
                } else {
                    manager->head = nextLink;
                }
            }
        }
        if (nextFree) {
            u32 nextSize = next->header & 0x0FFFFFFF;

            block->header = (block->header & 0xF0000000) |
                            (nextSize + (block->header & 0x0FFFFFFF));
            {
                memory_block_t *prevLink = next->prev;
                memory_block_t *nextLink = next->next;

                if (nextLink != NULL) {
                    nextLink->prev = prevLink;
                } else {
                    manager->tail = prevLink;
                }
            }
            {
                memory_block_t *nextLink = next->next;
                memory_block_t *prevLink = next->prev;

                nextSize = prevLink != NULL;
                if (nextSize) {
                    prevLink->next = nextLink;
                } else {
                    manager->head = nextLink;
                }
            }
            next = BLOCK_NEXT(block);
        }
        block->next = manager->head;
        manager->head = block;
        block->prev = NULL;
        if (block->next != NULL) {
            block->next->prev = block;
        } else {
            manager->tail = block;
        }
        BLOCK_FOOTER(next) = block;
        block->header |= 0x40000000;
        next->header |= 0x80000000;
    }
    memory_set_lock(0);
    return NULL;
}

void memory_nullsub3(void) {
    (void)sizeof(g_MemoryManagerPad);
}
