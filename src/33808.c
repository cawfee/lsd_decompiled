#include "33808.h"

extern class_33808_vtable_t D_8006F0B8;

void func_80026E0C(void);
void func_80026E38(void);
void func_80043648(class_33808_slot_t *slot, s32 arg1);

class_33808_t *func_80043008(s32 Unk1, s32 Unk2) {
    class_33808_t *allocated = (class_33808_t *) memory_allocate_mem(0x84);

    if (allocated) {
        func_80043830()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043068);

void func_800431A8(class_33808_t *This) {
    destroy_list(This->m_Unk11, This->m_Unk10);
  memory_free_mem(This->m_Unk11);
  (*(void ( **)(class_33808_t *))((s32) get_file_driver() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043200);

/*
u32 func_800434DC(class_33808_t *This) {
    u32 *table;
    u32 counter;
    u32 count;
    u32 max;
    u32 limit;
    u32 *walk;
    u32 value;
    u32 result;
    char pad[8];

    table = (u32 *)This->m_Unk3;
    counter = 0;
    count = table[0];
    max = 0;
    if (count != 0) {
        limit = count;
        walk = table;
        do {
            value = *(u32 *)((u8 *)walk + 0x14);
            walk = (u32 *)((u8 *)walk + 4);
            if (max < value) {
                max = value;
            }
            counter += 1;
        } while (counter < limit);
    }
    result = max;
    return result;
}
*/
INCLUDE_ASM("asm/nonmatchings/33808", func_800434DC);

void func_80043538(class_33808_t *This, s32 a2, s16 a3) {
    class_33808_slot_t *slot;

    slot = &This->m_Slots[a2];
    slot->unk0 = a3;
    slot->unk1 = 1 << slot->unk0;
}

void func_8004355C(class_33808_t *This, s32 arg1) {
    s32 i;

    func_80026E0C();
    i = 0;
    do {
        ((void (*)(void *, s32, s32))This->vtable->Unk31)(This, i, arg1);
        i += 1;
    } while (i < 4);
    func_80026E38();
}

void func_800435D0(class_33808_t *This, s32 arg1, s8 *arg2) {
    class_33808_slot_t *slot;

    func_80026E0C();
    slot = &This->m_Slots[arg1];
    __builtin_memcpy(slot->rgb, arg2, 3);
    func_80043648(slot, arg1);
    func_80026E38();
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043648);

class_33808_vtable_t *func_80043830(void) {
    return &D_8006F0B8;
}
