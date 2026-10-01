#include "common.h"

typedef struct memory_block {
    u32 header;
    struct memory_block *next;
    struct memory_block *prev;
} memory_block_t;

typedef struct memory_manager {
    void *pool;
    s32 pool_size;
    memory_block_t *head;
    memory_block_t *tail;
    s32 ready;
} memory_manager_t;

static memory_manager_t *g_MEMORY_MANAGER = NULL;
static void *g_PAD = NULL;

void *psyq_malloc_malloc(u32 size);
int printf(char *fmt, ...);
void memory_setup_manager(s32 *arg0);
void func_8001844C(s32 value);

void *memory_create_manager(u32 arg0, s32 unused) {
    u32 var_s1;
    s32 *temp_s0;

    var_s1 = arg0;
    if (var_s1 < 0x400U) {
        var_s1 = 0x400;
    }
    temp_s0 = (s32 *)psyq_malloc_malloc(var_s1 + 0x20);
    if (temp_s0 != NULL) {
        temp_s0[0] = (s32)((u8 *)temp_s0 + 0x1C);
        temp_s0[1] = var_s1;
        memory_setup_manager(temp_s0);
    } else {
        printf("bMemPMgr = %p, poolSize = %ld in BMemPMgrInit\n", 0, var_s1);
    }
    return temp_s0;
}

void memory_set_manager(void *Manager) {
    g_MEMORY_MANAGER = (memory_manager_t *)Manager;
}

void memory_free_buffer(void *Buffer) {
    psyq_malloc_free(Buffer);
}

void memory_setup_manager(s32 *arg0) {
    s32 *var_a1;
    s32 *temp_a0;
    s32 *temp_v0;

    var_a1 = (s32 *)g_MEMORY_MANAGER;
    if (var_a1 == NULL) {
        var_a1 = arg0;
    }
    var_a1[4] = 1;
    temp_a0 = (s32 *)var_a1[0];
    var_a1[2] = (s32)temp_a0;
    var_a1[3] = (s32)temp_a0;
    *temp_a0 = var_a1[1] | 0x40000000;
    ((s32 *)var_a1[2])[1] = 0;
    ((s32 *)var_a1[3])[2] = 0;
    temp_v0 = (s32 *)((s32)temp_a0 + (*temp_a0 & 0x0FFFFFFF));
    temp_v0[-1] = (s32)temp_a0;
    temp_v0[0] = 0x80000000;
}

INCLUDE_ASM("asm/nonmatchings/base/memory", memory_allocate_mem);

/*
 * Best-known C (105/107 insns, all relocations correct, structure matches):
 * gcc 2.6.3 hoists the block->next / block->prev loads above the merged-header
 * store and branches before it, while the target loads the header, stores it,
 * then loads next/prev. Swept: inline vs cached link/tmp, s32 vs u32 header,
 * memory_block_t* vs raw offsets, declaration order. No ordering reproduces the
 * target scheduler tie; target also keeps an extra nop after `lw a2,-8(s0)`.
 *
 * s32 memory_free_mem(void *arg0, void *arg1) {
 *     memory_manager_t *manager;
 *     memory_block_t *block;
 *     memory_block_t *next;
 *     memory_block_t *prev;
 *     memory_block_t *link;
 *     s32 header;
 *     s32 size;
 *     u32 next_free;
 *
 *     func_8001844C(1);
 *     manager = g_MEMORY_MANAGER;
 *     if (manager == NULL) {
 *         manager = (memory_manager_t *)arg1;
 *     }
 *     if (arg0 != NULL) {
 *         block = (memory_block_t *)((u8 *)arg0 - 4);
 *         header = block->header;
 *         size = header & 0x0FFFFFFF;
 *         next = (memory_block_t *)((u8 *)block + size);
 *         next_free = next->header & 0x40000000;
 *         if (header < 0) {
 *             block = *(memory_block_t **)((u8 *)block - 4);
 *             block->header = (block->header & 0xF0000000) |
 *                             (size + (block->header & 0x0FFFFFFF));
 *             prev = block->next;
 *             link = block->prev;
 *             if (prev != NULL) prev->prev = link; else manager->tail = link;
 *             prev = block->prev;
 *             link = block->next;
 *             if (prev != NULL) prev->next = link; else manager->head = link;
 *         }
 *         if (next_free != 0) {
 *             block->header = (block->header & 0xF0000000) |
 *                 ((next->header & 0x0FFFFFFF) + (block->header & 0x0FFFFFFF));
 *             prev = next->next;
 *             link = next->prev;
 *             if (prev != NULL) prev->prev = link; else manager->tail = link;
 *             prev = next->prev;
 *             link = next->next;
 *             if (prev != NULL) prev->next = link; else manager->head = link;
 *             next = (memory_block_t *)((u8 *)block + (block->header & 0x0FFFFFFF));
 *         }
 *         block->next = manager->head;
 *         manager->head = block;
 *         block->prev = NULL;
 *         if (block->next != NULL) block->next->prev = block; else manager->tail = block;
 *         *(memory_block_t **)((u8 *)next - 4) = block;
 *         block->header |= 0x40000000;
 *         next->header |= 0x80000000;
 *     }
 *     func_8001844C(0);
 *     return 0;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/base/memory", memory_free_mem);

void nullsub3(void) {
}
