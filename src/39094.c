#include "39094.h"

extern class_39094_vtable_t D_80081940;

class_39094_t *func_80048894() {
    class_39094_t *allocated = (class_39094_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_80048CE0()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_800488E4(class_39094_t *This) {
    (*(void (**)(class_39094_t *))((s32)func_80026CAC() + 8))(This);
    This->vtable = func_80048CE0();
    This->m_Unk11_1 = -1;
    This->m_Unk10_1 = 0;
    This->m_Unk10_2 = 0;
    This->m_Unk11_2 = 0;
    This->m_Unk12 = 0;
    This->m_Unk13 = 1;
    This->m_Unk3 = memory_allocate_mem(0xB358);
    if (This->m_Unk3 != 0) {
        This->m_Unk4 = 0xB358;
    }
}

void func_80048960(class_39094_t *This) {
    This->vtable->Unk32(This);
  (*(void ( **)(class_39094_t *))((s32) func_80026CAC() + 12))(This);
}

void func_800489B4(class_39094_t *This) {
    u16 state;

    state = *(u16 *)((u8 *)This + 0x2A);
    if (state == 9) {
        if (This->m_Unk8 & 0x80) {
            *(u16 *)((u8 *)This + 0x2A) = 0;
            This->m_Unk10_1 = 1;
            if (This->m_Unk13 != 0) {
                ((void (*)(void))This->vtable->Unk31)();
            }
        }
    } else if (state == 0xA) {
        if (This->m_Unk8 & 0x80) {
            This->m_Unk10_2 = 1;
            *(u16 *)((u8 *)This + 0x2A) = 0;
        }
    }
    (*(void (**)(class_39094_t *))((s32)func_80026CAC() + 0x64))(This);
}

void func_80048A68(class_39094_t *This) {
    (*(void ( **)(class_39094_t *))((s32) func_80026CAC() + 116))(This);
    This->m_Unk10_1 = 0;
    This->m_Unk10_2 = 0;
    This->m_Unk9_2 = 0;
}

void func_80048AAC(class_39094_t *This, s32 Unk1) {
    if ((This->m_Unk3 != 0) && (Unk1 != 0)) {
        if (*(u16 *)((u8 *)This + 0x2A) == 0) {
            This->m_Unk10_1 = 0;
        } else {
            This->vtable->Unk28(This);
        }
        *(u16 *)((u8 *)This + 0x2A) = 9;
        This->vtable->Unk17(This);
        ((void (*)(void *, s32, s32, s32))This->vtable->Unk16)(This, Unk1, 1, 0);
        ((void (*)(void *, s32, s32))This->vtable->Unk20)(This, This->m_Unk3, 0xB358);
    }
}

void func_80048B78(class_39094_t *This) {
    This->vtable->Unk22(This);
  This->m_Unk10_1 = 0;
  This->m_Unk11_1 = -1;
}

s32 func_80048BC0(class_39094_t *This) {
    s32 size;
    s32 mem;

    if ((*(u16 *)((u8 *)This->m_Unk3 + 2) != 0) && (*(u16 *)((u8 *)This + 0x2A) == 0)) {
        ((void (*)(void))This->vtable->Unk32)();
        size = *(s32 *)((u8 *)This->m_Unk3 + 0x14);
        mem = memory_allocate_mem(size);
        This->m_Unk12 = mem;
        if (mem != 0) {
            *(u16 *)((u8 *)This + 0x2A) = 0xA;
            ((void (*)(void *, s32, s32))This->vtable->Unk18)(
                This, *(s32 *)((u8 *)This->m_Unk3 + 0x10), 0);
            ((void (*)(void *, s32, s32))This->vtable->Unk20)(This, This->m_Unk12, size);
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_80048C98(class_39094_t *This) {
    This->m_Unk10_2 = 0;

    if (This->m_Unk12) {
        This->m_Unk12 = memory_free_mem(This->m_Unk12);
    }
}

void func_80048CD8(class_39094_t *This, s32 Unk) {
    This->m_Unk13 = Unk;
}

class_39094_vtable_t *func_80048CE0(void) {
    return &D_80081940;
}
