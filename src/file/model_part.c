#include "file/model_part.h"

extern model_part_vtable_t D_8006F240;

model_part_t *func_80043E84(s32 Unk1) {
    model_part_t *allocated = (model_part_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        func_800441A4()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80043EE4(model_part_t *This, s32 *Unk) {
    void *unk_class = get_file_driver();
    (*(void (**)(model_part_t *))(unk_class + 8))(This);

    This->vtable = func_800441A4();

    if (*Unk) {
        This->m_Unk3 = *Unk;
        This->m_Unk4 = 0;
        This->vtable->Unk24(This);
    } else {
        This->vtable->Unk26(This, Unk[1]);
    }
}

void func_80043F78(model_part_t *This) {
    void *unk = get_file_driver();
    (*(void (**)(model_part_t *))(unk + 12))(This);
}

u8 func_80043FB0(model_part_t *This, s32 Unk1, s32 Unk2) {
    return This->vtable->Unk30(This, Unk1, Unk2, This->m_Unk3 + 8);
}

// Best attempt: same record walk (u16 count at +2, records advance by sp1B*4),
// same func_8004416C 6-arg call shape and same branch structure. Target frame
// is 0x58 with s0-s7 saved from 0x30; GCC uses a 0x48 frame with the saves from
// 0x20 (0x10 less local/outgoing space) and reschedules the arg copies.  Tried
// out/src/pointer locals and a single search loop.
// s32 func_80043FE4(s32 arg0, u8 *arg1, s32 *arg2, u8 *arg3) {
//     u8 sp18, sp19, sp1A, sp1B;
//     u16 count; u8 *out; u8 *src;
//     s32 i, written, found, k, n;
//     out = arg1; src = arg3;
//     count = *(u16 *)(src + 2); src += 8;
//     i = 0; written = 0; found = 0;
//     if (count != 0) {
//         do {
//             func_8004416C((model_part_t *)arg0, (u32 *)src, &sp18, &sp19, &sp1A, &sp1B);
//             if (sp19 == 8) {
//                 if (sp1A == 0) { written++; if (out != NULL) { *out = sp18; out++; } }
//             } else if (sp19 == 2) {
//                 if (out == NULL) { if (arg2 != NULL) found++; }
//                 else if (arg2 != NULL) {
//                     if (*(u16 *)(src + 4) == *arg2) {
//                         n = written & 0xFF; out -= n;
//                         if (n > 0) { k = 0;
//                             do { if (*out == sp18) { out++; found = k; break; } out++; k++; } while (k < n);
//                         }
//                     }
//                 }
//             }
//             i++; src += sp1B * 4;
//         } while (i < count);
//     }
//     if (arg2 != NULL) *arg2 = found;
//     return written & 0xFF;
// }

INCLUDE_ASM("asm/nonmatchings/file/model_part", func_80043FE4);

u32 *func_8004416C(model_part_t *This, u32 *Src, u8 *dst1, u8 *dst2, u8 *dst3, u8 *dst4) {
    u32 val;

    val = *Src;
    *dst1 = val;
    *dst2 = (val >> 16) & 0xF;
    *dst3 = (val >> 20) & 0xF;
    *dst4 = val >> 24;
    return Src + 1;
}

model_part_vtable_t *func_800441A4(void) {
    return &D_8006F240;
}
