#ifndef LSD_MEMORY_H
#define LSD_MEMORY_H

#include <common.h>

/* Block header used by the pool allocator.  `m_Header` packs the block size in
 * the low 28 bits and status flags in the top nibble (0x40000000 free,
 * 0x80000000 previous-free). */
typedef struct memory_block {
    /* 0x0 */ u32 m_Header;
    /* 0x4 */ struct memory_block *m_Next;
    /* 0x8 */ struct memory_block *m_Prev;
} memory_block_t;

/* Pool manager placed at the head of a psyq_malloc_malloc()'d arena.  `m_Pool`
 * points at the first block header; the block area follows the struct inline. */
typedef struct memory_manager {
    /* 0x00 */ void *m_Pool;
    /* 0x04 */ s32 m_PoolSize;
    /* 0x08 */ memory_block_t *m_Head;
    /* 0x0C */ memory_block_t *m_Tail;
    /* 0x10 */ s32 m_Ready;
    /* 0x14 */ s32 m_Unk5;
    /* 0x18 */ s32 m_Unk6;
    /* 0x1C */ u8 m_Blocks[0];
} memory_manager_t;

memory_manager_t *memory_create_manager(u32 Size, s32 Unused);
void memory_set_manager(memory_manager_t *Manager);

/* The retail allocate/free routines really do read a second argument: a
 * fallback manager consulted only when g_MemoryManager is NULL.  No game call
 * site supplies it -- main() installs the global manager before any allocation,
 * and the retail callers leave $a1 untouched -- so callers stay one-argument.
 * memory.c defines MEMORY_INTERNAL and sees the true two-argument prototypes,
 * while every other translation unit gets a typed one-argument interface. */
#ifdef MEMORY_INTERNAL
void *memory_allocate_mem(u32 Size, void *FallbackManager);
void *memory_free_mem(void *Ptr, void *FallbackManager);
#else
void *memory_allocate_mem(u32 Size);
void *memory_free_mem(void *Ptr);
#endif
void memory_free_raw(void *Ptr);
void memory_setup_manager(memory_manager_t *ManagerParam);
void memory_set_lock(s32 Value);
s32 memory_is_locked(void);
void memory_nullsub3(void);

#endif // LSD_MEMORY_H
