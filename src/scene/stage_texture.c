#include "scene/stage_texture.h"

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

INCLUDE_ASM("asm/nonmatchings/scene/stage_texture", func_80043068);

void func_800431A8(class_stage_texture_t *This) {
    destroy_list(This->m_Unk11, This->m_Unk10);
  memory_free_mem(This->m_Unk11);
  (*(void ( **)(class_stage_texture_t *))((s32) get_file_driver() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/scene/stage_texture", func_80043200);

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
INCLUDE_ASM("asm/nonmatchings/scene/stage_texture", func_800434DC);

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

/*
 * Best attempt (not matching: 122 insns, byte-identical except a register
 * allocation tie-break in the outer-loop setup. Target keeps step `row+1` in
 * v0 and shifts into t0 (`sllv t0,v0,s6`), reserving v0 for the 0x1000
 * constant; gcc 2.6.3 coalesces step and the shift result into v0
 * (`sllv v0,v0,s6`) and materializes 0x1000 in v1, which cascades into the
 * inner-loop register assignment. Tried separate step/temp variables, u32
 * types, inline shift counts, returned s32, reordered products/inv, and
 * function-scope temps; all coalesce. struct rgb must be u8 for the lbu.)
 *
 * typedef struct { s16 x; u16 y; s16 w; u16 h; } stage_texture_rect_t;
 * void StoreImage(stage_texture_rect_t *, u16 *);
 * void LoadImage(stage_texture_rect_t *, u16 *);
 * void DrawSync(s32);
 *
 * void func_80043648(class_stage_texture_slot_t *slot, s32 arg1) {
 *     stage_texture_rect_t dst;
 *     stage_texture_rect_t src;
 *     u16 buf[0x100];
 *     u16 pixels[0x108];
 *     u8 r, g, b;
 *     s32 shift, row, i, t0, inv, roff, goff, boff;
 *
 *     src.x = 0;
 *     src.w = 0x100;
 *     src.h = 1;
 *     src.y = (arg1 << D_8008A92C) + 0x1E0;
 *     StoreImage(&src, pixels);
 *     DrawSync(0);
 *     dst.h = 1;
 *     row = 0;
 *     dst.x = 0;
 *     dst.y = 0;
 *     dst.w = 0x100;
 *     r = slot->rgb[0];
 *     g = slot->rgb[1];
 *     b = slot->rgb[2];
 *     slot->unkA = slot->unk1;
 *     shift = 0xC - slot->unk0;
 *     if (slot->unk1 - 1 > 0) {
 *         do {
 *             t0 = (row + 1) << shift;
 *             roff = r * t0;
 *             goff = g * t0;
 *             boff = b * t0;
 *             inv = 0x1000 - t0;
 *             i = 0;
 *             if (src.w > 0) {
 *                 do {
 *                     if (pixels[i] == 0) {
 *                         buf[i] = pixels[i];
 *                     } else {
 *                         buf[i] = (pixels[i] & 0x8000)
 *                             | (((((pixels[i] & 0x1F) << 3) * inv) + roff) >> 0xF)
 *                             | ((((((pixels[i] >> 2) & 0xF8) * inv) + goff) >> 0xF) << 5)
 *                             | ((((((pixels[i] >> 7) & 0xF8) * inv) + boff) >> 0xF) << 0xA);
 *                     }
 *                     i++;
 *                 } while (i < src.w);
 *             }
 *             dst.y = src.y + row + src.h;
 *             DrawSync(0);
 *             LoadImage(&dst, buf);
 *             row++;
 *         } while (row < slot->unk1 - 1);
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/scene/stage_texture", func_80043648);

class_stage_texture_vtable_t *func_80043830(void) {
    return &D_8006F0B8;
}
