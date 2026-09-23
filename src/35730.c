#include "35730.h"

#include <psx/libgpu.h>

#include "file_buf.h"
#include "memory.h"

extern class_35730_vtable_t **D_8006F514;

class_35730_t *func_80044F30(u32 Unk1) {
    class_35730_t *allocated = (class_35730_t *) memory_allocate_mem(0x38);

    if (allocated) {
        func_800451A8()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80044F90(class_35730_t *This, s32 Unk) {
    void *unk_class;
    s8 pad[0x20];

    unk_class = get_file_driver();
    (*(void (**)(class_35730_t *))(unk_class + 8))(This);
    This->vtable = func_800451A8();
    This->m_Unk12 = 0;
    This->m_Unk11_2 = 0;
    if (Unk == 0) {
        This->m_Unk11_1 = 1;
        This->m_Unk9_2 = 0;
        This->vtable->Unk24(This);
    }
}

void func_8004500C(class_35730_t *This) {
    memory_free_mem(This->m_Unk12);
  memory_free_mem(This->m_Unk10);
  (*(void ( **)(class_35730_t *))((s32) get_file_driver() + 12))(This);
}

void func_80045060(class_35730_t *This) {
    s8 pad[0x20];
    
    if ( !This->m_Unk9_2 )
  {
    This->vtable->Unk29(This);
    This->m_Unk11_2 = 1;
  }
}

typedef struct {
    /* 0x0 */ u8 u;
    /* 0x1 */ u8 v;
    /* 0x2 */ u16 clut;
    /* 0x4 */ u16 pad;
    /* 0x6 */ u16 tpage;
} atlas_cell_t;

void func_800450B4(class_35730_t *This) {
    atlas_cell_t *cell;
    void *mem;
    s32 x;
    s32 u;
    s32 v;
    s32 tpage;
    s32 limit;
    s32 i;

    if (This->m_Unk11_1 == 0) {
        return;
    }
    x = 0x280;
    v = 0;
    u = 0;
    tpage = GetTPage(2, 0, 0x280, 0) & 0xFFFF;
    mem = memory_allocate_mem(0x960);
    This->m_Unk10 = (s32)mem;
    if (mem == NULL) {
        return;
    }
    i = 0;
    cell = (atlas_cell_t *)mem;
    limit = 0x12C;
    do {
        cell->u = u;
        u += 0x10;
        x += 0x10;
        cell->tpage = tpage;
        cell->v = v;
        cell->clut = 0;
        cell->pad = 0;
        if (x >= 0x3C0) {
            u = 0;
            x = 0x280;
            v += 0x10;
        }
        if ((x & 0x3F) == 0) {
            tpage = x >> 6;
            if (v >= 0x100) {
                tpage += 0x10;
            }
            u = 0;
        }
        i++;
        cell++;
    } while (i < limit);
}

class_35730_vtable_t *func_800451A8(void) {
    return &D_8006F514;
}
