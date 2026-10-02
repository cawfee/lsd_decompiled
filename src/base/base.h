#ifndef LSD_BASE_CLASS_H
#define LSD_BASE_CLASS_H

#include <common.h>

typedef struct base_class base_class_t;
typedef struct base_class_vtable base_class_vtable_t;

typedef struct memory_block {
    /* 0x0 */ u32 m_Header;
    /* 0x4 */ struct memory_block *m_Next;
    /* 0x8 */ struct memory_block *m_Prev;
} memory_block_t;

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

struct base_class_vtable {
    /* 0x000 8006b58c */ u32 type_id;
    /* 0x004 8006b590 */ base_class_t *(*Destroy)(base_class_t *This);
    /* 0x008 8006b594 */ void (*Construct)(base_class_t *This);
    /* 0x00C 8006b598 */ void (*Cleanup)(base_class_t *This);
    /* 0x010 8006b59c */ void (*Attach)(base_class_t *This, base_class_t *Child);
    /* 0x014 8006b5a0 */ void (*Detach)(base_class_t *This, base_class_t *Child);
    /* 0x018 8006b5a4 */ void (*DetachAll)(base_class_t *This);
    /* 0x01C 8006b5a8 */ void (*IterChildren)(base_class_t *This, void **OutValue, void **Cursor);
    /* 0x020 8006b5ac */ void (*AddParent)(base_class_t *This, base_class_t *Parent);
    /* 0x024 8006b5b0 */ void (*RemoveParent)(base_class_t *This, base_class_t *Parent);
    /* 0x028 8006b5b4 */ void (*ClearParents)(base_class_t *This);
    /* 0x02C 8006b5b8 */ void (*IterParents)(base_class_t *This, void **OutValue, void **Cursor);
    /* 0x030 8006b5bc */ void (*Notify)(base_class_t *This, s32 Code);
    /* 0x034 8006b5c0 */ void (*Nop)(base_class_t *This);
    /* 0x038 8006b5c4 */ void (*OnNotify)(base_class_t *This, base_class_t *Sender, s32 Code);
    /* 0x03C 8006b5c8 */ void (*Unk14)(base_class_t *This);
};

typedef struct linked_list_node {
    /* 0x0 */ struct linked_list_node *m_Next;
    /* 0x4 */ void *m_Value;
} linked_list_node_t;

struct base_class {
    /* 0x00 */ base_class_vtable_t *vtable;
    /* 0x04 */ linked_list_node_t *m_Children;
    /* 0x08 */ linked_list_node_t *m_Parents;
};

//
// Memory related functions
//

memory_manager_t *memory_create_manager(u32 Size, s32 Unused);
void memory_set_manager(memory_manager_t *Manager);

// Alloc/free methods dont expose FallbackManager arg.
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

//
// Base related
//

base_class_vtable_t *base_class_get_vtable(void);

base_class_t *base_class_destructor(base_class_t *This);
void base_class_construct(base_class_t *This);
void base_class_cleanup(base_class_t *This);
void base_class_attach(base_class_t *This, base_class_t *Child);
void base_class_detach(base_class_t *This, base_class_t *Child);
void base_class_detach_all(base_class_t *This);
void base_class_iter_children(base_class_t *This, void **OutValue, void **Cursor);
void base_class_add_parent(base_class_t *This, base_class_t *Parent);
void base_class_remove_parent(base_class_t *This, base_class_t *Parent);
void base_class_clear_parents(base_class_t *This);
void base_class_iter_parents(base_class_t *This, void **OutValue, void **Cursor);
void base_class_notify(base_class_t *This, s32 Code);
void base_class_nop(base_class_t *This);
void base_class_on_notify(base_class_t *This, base_class_t *Sender, s32 Code);

s32 linked_list_prepend(linked_list_node_t **List, void *Value);
void linked_list_remove(linked_list_node_t **List, void *Target);
void linked_list_clear(linked_list_node_t **ListHead);
void linked_list_next(void **OutValue, void **Cursor);
s32 destroy_list(base_class_t **Array, s32 Count);

#endif
