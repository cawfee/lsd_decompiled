#include "stage_texture.h"

extern class_stage_texture_vtable_t D_8006F0B8;

void file_driver_lock(void);
void file_driver_unlock(void);
void func_80043648(class_stage_texture_slot_t *slot, s32 arg1);

class_stage_texture_t *func_80043008(s32 Unk1, s32 Unk2) {
    class_stage_texture_t *allocated = (class_stage_texture_t *) memory_allocate_mem(0x84);

    if (allocated) {
        func_80043830()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/stage_texture", func_80043068);

void func_800431A8(class_stage_texture_t *This) {
    destroy_list(This->m_Unk11, This->m_Unk10);
  memory_free_mem(This->m_Unk11);
  (*(void ( **)(class_stage_texture_t *))((s32) get_file_driver() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/stage_texture", func_80043200);

/*
 * Best attempt (not matching: target has a 23-instruction body with a real
 * stack frame (`addiu sp,sp,-8` / `sw $ra`); compiled version is 21 insns with
 * no frame. First difference is insn 1: target `addiu sp,sp,-8` vs compiled
 * `lw v1,16(a0)`.)
 *
u32 func_800434DC(class_stage_texture_t *This) {
    u32 *table;
    u32 counter;
    u32 count;
    u32 max;
    u32 limit;
    u32 *walk;
    u32 value;

    table = (u32 *)This->m_Unk3;
    count = *(u32 *)This->m_Unk3;
    max = 0;
    counter = 0;
    if (count != 0) {
        walk = table;
        limit = count;
        counter = 0;
        do {
            value = *(u32 *)((u8 *)walk + 0x14);
            walk = (u32 *)((u8 *)walk + 4);
            if (max < value) {
                max = value;
            }
            counter += 1;
        } while (counter < limit);
    }
    return max;
}
*/
INCLUDE_ASM("asm/nonmatchings/stage_texture", func_800434DC);

void func_80043538(class_stage_texture_t *This, s32 a2, s16 a3) {
    class_stage_texture_slot_t *slot;

    slot = &This->m_Slots[a2];
    slot->unk0 = a3;
    slot->unk1 = 1 << slot->unk0;
}

void func_8004355C(class_stage_texture_t *This, s32 arg1) {
    s32 i;

    file_driver_lock();
    i = 0;
    do {
        ((void (*)(void *, s32, s32))This->vtable->Unk31)(This, i, arg1);
        i += 1;
    } while (i < 4);
    file_driver_unlock();
}

void func_800435D0(class_stage_texture_t *This, s32 arg1, s8 *arg2) {
    class_stage_texture_slot_t *slot;

    file_driver_lock();
    slot = &This->m_Slots[arg1];
    __builtin_memcpy(slot->rgb, arg2, 3);
    func_80043648(slot, arg1);
    file_driver_unlock();
}

INCLUDE_ASM("asm/nonmatchings/stage_texture", func_80043648);

class_stage_texture_vtable_t *func_80043830(void) {
    return &D_8006F0B8;
}
