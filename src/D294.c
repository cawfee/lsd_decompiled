#include "D294.h"

#include "base_class.h"

// Maybe pad handling? unchecked

extern class_D294_vtable_t **D_8006B5CC;
extern s32 *D_8006B684;
extern s32 *D_8006B690;

class_D294_t *func_8001CA94() {
    class_D294_t *allocated = (class_D294_t *) memory_allocate_mem(0x44);

    if (allocated) {
        if (func_8001E57C()->Construct(allocated)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_8001CAF4(class_D294_t *This) {
    void *buffer;
    This->m_Unk4 = memory_allocate_mem(0x50);

    if (This->m_Unk4) {
        buffer = memory_allocate_mem(0x28);
        *((u32 *) This->m_Unk4 + 17) = buffer;

        if (buffer) {
            base_class_get_vtable()->Construct(This);
            This->vtable = func_8001E57C();
            This->m_Unk7 = 0;
            This->m_Unk5 = 0;
            This->m_Unk2 = 0;
            *((u32 *) This->m_Unk4 + 18) = 0;
            This->vtable->Unk15(This);
            return This;
        }

        memory_free_mem(This->m_Unk4);
    }

    return NULL;
}

void func_8001CBA4(class_D294_t *This) {
    This->vtable->Unk19(This);
    This->vtable->Unk20(This);
    This->vtable->Unk22(This, 0);
    memory_free_mem(*((void **) This->m_Unk4 + 17));
    memory_free_mem(This->m_Unk4);
    base_class_get_vtable()->Cleanup(This);
}

void func_8001CC48(class_D294_t *This, void **Unk) {
    base_class_get_vtable()->Unk3(This, Unk);

    if ((*(u32 *) *Unk & 0xF) == 9) {
        func_8001E770(This, Unk);
    }
}

void func_8001CCB4(class_D294_t *This, void **Unk) {
    if ((*(u32 *) *Unk & 0xF) == 9) {
        func_8001E7B0(This);
    }

    base_class_get_vtable()->Unk4(This, Unk);
}

void func_8001CD20(class_D294_t *This) {
    func_8001E7B0(This);
    base_class_get_vtable()->Unk5(This);
}

void func_8001CD60(class_D294_t *This, void **Unk2, s32 Unk3) {
    u32 value;
    base_class_get_vtable()->Unk13(This, Unk2, Unk3);

    value = *(u32 *) *Unk2 & 0xF;

    if (value == 2) {
        // Update buttons?
        This->vtable->Unk36(This, Unk2, Unk3);
    } else if (value == 5) {
        This->vtable->Unk37(This, Unk2, Unk3);
    } else if (value == 4) {
        This->vtable->Unk38(This, Unk2, Unk3);
    }
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001CE30);
// void func_8001CE30(class_D294_t *This) {
//     This->m_Unk8 = 0;
//     This->m_Unk3 = 0;

//     GsInitCoordinate2(0, This->m_Unk4);
//     This->vtable->Unk16(This, 1, D_8006B684);
//     This->vtable->Unk17(This, 1, D_8006B690);
//     *(u32 *)This->m_Unk4 = 1;
// }

INCLUDE_ASM("asm/nonmatchings/D294", func_8001CEB4);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D008);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D0EC);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D1A4);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D204);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D280);

void func_8001D33C(void) {
}

s32 func_8001D344(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 31, 1, Unk == 0) == 0;
}

void func_8001D374(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 30, 1, Unk != 0);
}

void func_8001D3A0(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 28, 2, Unk);
}

void func_8001D3CC(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 6, 1, Unk == 0);
}

void func_8001D3F8(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 3, 3, Unk);
}

void func_8001D424(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 0, 3, Unk);
}

s32 func_8001D450(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 7, 1, Unk == 0) == 0;
}

void func_8001D480(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 9, 3, Unk);
}

s32 func_8001D4AC(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 8, 1, Unk == 0) == 0;
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D4DC);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D568);

void func_8001D600(class_D294_t *This, s32 Unk) {
    func_8001F51C(This->m_Unk7, Unk);
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D624);

void func_8001D6A4(void) {
}

void func_8001D6AC(void) {
}

void func_8001D6B4(class_D294_t *This, s32 Unk1, s32 Unk2) {
    switch (Unk2) {
        case 2:
        case 3:
            This->vtable->Unk39(This, Unk1);
            break;
        
        case 4:
            This->m_Unk9 = Unk1;
            break;
        
        default:
            break;
    }
}


INCLUDE_ASM("asm/nonmatchings/D294", func_8001D714);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001D950);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001DA28);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001DDF4);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001E110);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001E2E8);

void func_8001E49C(void) {
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001E4A4);

class_D294_vtable_t *func_8001E57C(void) {
    return &D_8006B5CC;
}
