#ifndef LSD_MEMORY_H
#define LSD_MEMORY_H

#include <common.h>

/* Block header used by the pool allocator.  `header` packs the block size in
 * the low 28 bits and status flags in the top nibble (0x40000000 free,
 * 0x80000000 previous-free). */
typedef struct memory_block {
    /* 0x0 */ u32 header;
    /* 0x4 */ struct memory_block *next;
    /* 0x8 */ struct memory_block *prev;
} memory_block_t;

/* Pool manager placed at the head of a psyq_malloc_malloc()'d arena.  `pool`
 * points at the first block header; the block area follows the struct inline. */
typedef struct memory_manager {
    /* 0x00 */ void *pool;
    /* 0x04 */ s32 pool_size;
    /* 0x08 */ memory_block_t *head;
    /* 0x0C */ memory_block_t *tail;
    /* 0x10 */ s32 ready;
    /* 0x14 */ s32 m_Unk5;
    /* 0x18 */ s32 m_Unk6;
    /* 0x1C */ u8 blocks[0];
} memory_manager_t;

memory_manager_t *memory_create_manager(u32 size, s32 unused);
void memory_set_manager(memory_manager_t *manager);
void *memory_allocate_mem(); /* u32 size, void *pool */
void *memory_free_mem();     /* void *ptr, void *pool */
void memory_free_raw(void *ptr);
void memory_setup_manager(memory_manager_t *managerParam);
void memory_set_lock(s32 value);
s32 memory_is_locked(void);
void memory_nullsub3(void);

#endif // LSD_MEMORY_H
