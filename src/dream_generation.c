#include "common.h"
#include "effect_base.h"

extern u8 D_800872C4[];
extern s32 D_8008730C[];

extern s32 g_GenerationOwner;
extern s32 g_GenerationLocation;
extern s32 *g_GenerationEntityContext;
extern s32 g_LocationTimer;
extern s32 g_CurrentDay;
extern s32 D_8008AC78;
extern s32 g_GenerationType;
extern s32 D_8008ACA0[];

s32 dream_generation_load();

s32 dream_generation_start(void *a0, s32 a1, s32 *a2, s32 a3, s32 a4) {
    s32 *p;
    s32 i;

    if (g_GenerationOwner == 0) {
        i = 1;
        p = D_8008ACA0;
        g_GenerationOwner = (s32)a0;
        g_GenerationLocation = a1;
        g_GenerationEntityContext = a2;
        g_GenerationType = -1;
        g_CurrentDay = a3;
        D_8008AC78 = a4;
        g_LocationTimer = 0;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        return dream_generation_load();
    }
    return 0;
}

extern s8 *D_800873EC[];
extern u8 D_80087424[];
extern s32 D_8008AB54;
void dream_generation_apply_entry(u8 *, s8 *);
s8 *dream_generation_pick_entry(void);

u8 *dream_generation_load(void) {
    s8 *s0 = D_800873EC[g_GenerationLocation];

    if (s0 == NULL) {
        s0 = dream_generation_pick_entry();
    }
    dream_generation_apply_entry(D_80087424, s0);
    if (s0[1] >= 4) {
        D_8008AB54 = (s32)(D_800872C4 + s0[2] * 3);
    }
    return D_80087424;
}

void dream_generation_apply_entry(u8 *arg0, s8 *arg1) {
    *(void **)(arg0 + 0xC) = (u8 *)&D_800872C4 + arg1[3] * 3;
    *(void **)(arg0 + 0x18) = (u8 *)&D_800872C4 + arg1[2] * 3;
    *(s32 *)(arg0 + 0x1C) = D_8008730C[arg1[1]];
    *(s32 *)(arg0 + 0x14) = arg1[0];
}

extern s32 D_8008AB54;
extern s32 D_8008AB58[];
extern s32 D_8008AB60[];
extern s32 *g_GenerationEntityContext;
extern effect_base_t *D_8008AC94;

void func_80054660(void) {
    void **ctx;
    s32 result;

    if (D_8008AB54 != 0) {
        D_8008AC94 = func_800404D0((u32)D_8008AB60, (u32)D_8008AB54, 0);
        D_8008AC94->vtable->Unk24(D_8008AC94, 1);
        D_8008AC94->vtable->Unk25(D_8008AC94, 0);
        ctx = *(void ***)((u8 *)g_GenerationEntityContext + 0xC);
        result = (*(s32 (**)(void *))((u8 *)*ctx + 0xAC))(ctx);
        D_8008AC94->vtable->Unk18(D_8008AC94, result, D_8008AB58);
    }
}

extern s32 D_8008AB54;
extern effect_base_t *D_8008AC94;

void func_80054714(void) {
    if (D_8008AB54 != 0) {
        D_8008AC94->vtable->Destroy(D_8008AC94);
        D_8008AB54 = 0;
    }
}

extern s8 D_800873DC[];
extern s8 D_800873D8[];
extern u8 *D_800873C8[];
extern u8 D_80087234[];
extern u8 D_8008726C[];
extern s32 g_GenerationFlags;
extern s32 g_GenerationIndex;
extern s32 g_GenerationTablePtr;
extern s32 g_GenerationDataPtr;

s8 *dream_generation_pick_entry(void) {
    s32 temp_v1;
    s8 temp_a0;
    s32 idx;
    s8 *entry;
    u8 *p;

    temp_v1 = g_CurrentDay + g_GenerationLocation;
    temp_a0 = D_800873DC[temp_v1 & 0xF];
    g_GenerationType = temp_a0;
    idx = temp_v1 % D_800873D8[temp_a0];
    g_GenerationIndex = idx;
    entry = (s8 *)(D_800873C8[temp_a0] + idx * 4);
    if (temp_a0 == 0) {
        p = D_8008726C;
        g_GenerationDataPtr = (s32)(D_800872C4 + entry[3] * 3);
        if (entry[2] != 0x12) {
            p = D_80087234;
        }
        g_GenerationTablePtr = (s32)p;
        if (idx < 4) {
            g_GenerationFlags = 1;
        } else if (idx < 6) {
            g_GenerationFlags = 2;
        }
    }
    return entry;
}

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80054850);

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_800549A8);

void func_80054B1C(u8 *arg0, u8 *arg1, s32 arg2) {
    arg0[0] = arg1[0] - arg2;
    arg0[1] = arg1[1] - arg2;
    arg0[2] = arg1[2] + arg2;
}

extern s32 g_GenerationFlags;
extern base_class_t *D_8008E10C[];

void func_80054B50(void) {
    if (g_GenerationFlags != 0) {
        destroy_list(D_8008E10C, 0x12);
        g_GenerationFlags = 0;
    }
}

/*
 * Near match (semantics exact, 59/60 insns, same opcode stream). Only residual:
 * gcc 2.6.3 CSEs the two `g_GenerationType == 2` constants into one pseudolive across
 * the calls, keeping 2 in $s2 and saving/restoring it; the target rematerializes
 * `ori a0,zero,2` / `ori v0,zero,2` at each test and so has no $s2 save. Tried
 * if/else, else-if, switch, do{break;}while, `!= 2u`, 2/0x2 spellings, inverted
 * comparisons: gcc always hoists 2 into $s2 (59 or 61 insns). Best C:
 *
 * void func_80054B84(s32 arg0) {
 *     s32 byte, pad, temp_v0;
 *     if (g_GenerationType >= 0) {
 *         func_80056F5C(g_GenerationType, (void *)g_GenerationEntityContext[1], g_GenerationEntityContext[2], g_GenerationEntityContext[3]);
 *         byte = D_80087324[rand() & 3];
 *         pad = 0;
 *         if (g_GenerationType == 2) { pad = 0x10 - byte; }
 *         D_8008AC88 = byte + pad;
 *         temp_v0 = (s32)func_80054F30((s32 *)func_80054DA4(D_8008E0C8, byte, arg0), pad, arg0);
 *         if (g_GenerationType == 0) {
 *             func_80054FD8(temp_v0, arg0);
 *         } else if (g_GenerationType != 2) {
 *             return;
 *         } else {
 *             func_8005511C(temp_v0, arg0);
 *         }
 *         D_8008AC88 += 1;
 *     }
 * }
 */

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80054B84);

#if 0
/* Best match: 34/34 insns, identical loop/call shape.  Residual is GCC 2.6.3
 * frame/regalloc: target frame is 0x28 and keeps the loop index in $s0 / the
 * cursor in $s1; gcc emits a 0x20 frame with index in $s1 / cursor in $s0.
 * (The earlier "empty function" was a real bug in the attempt: D_8008AC88 and
 * D_8008E0C8 are declared below this function, so the first drafts used
 * implicit declarations.)  Tried void**/u8*/base_class_t** cursor forms,
 * declaration order, named obj/vtable temps. */
void func_80054C74(s32 arg0) {
    s32 i;
    base_class_t **p;

    if (g_GenerationType >= 0) {
        i = 0;
        if (D_8008AC88 > 0) {
            p = D_8008E0C8;
            do {
                base_class_t *obj = *p;

                ((void (*)(base_class_t *, s32))(*(u32 *)((u8 *)obj->vtable + 0xEC)))(obj, arg0);
                p++;
                i++;
            } while (i < D_8008AC88);
        }
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80054C74);

extern s32 g_GenerationType;
extern s32 D_8008AC88;
extern base_class_t *D_8008E0C8[];

void func_80054CFC(void) {
    if (g_GenerationType >= 0) {
        destroy_list(D_8008E0C8, D_8008AC88);
    }
}

extern s32 *D_8008AC9C[];
s32 func_800557DC(s32 *);

void func_80054D30(void) {
    s32 **p;
    s32 i;

    func_80054714();
    i = 0;
    func_80054B50();
    func_80054CFC();
    p = D_8008AC9C;
    do {
        *p = (s32 *)func_800557DC(*p);
        i++;
        p++;
    } while (i < 2);
    if (g_GenerationOwner != 0) {
        g_GenerationOwner = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80054DA4);

extern s32 D_80087330[];
extern s32 D_80087204[];
extern void *D_8008E0B4[];
extern s32 D_8008E0A4[];
void func_80055258(s32, s32);
s32 func_80056320(s32, void *, s32, s32);

s32 *func_80054F30(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s4;
    s32 var_s0;

    temp_s4 = D_80087330[0];
    D_8008E0B4[0] = D_80087204;
    for (var_s0 = 0; var_s0 < arg1; var_s0++) {
        func_80055258(arg2, temp_s4);
        *arg0 = func_80056320(1, D_8008E0A4, g_GenerationOwner, arg2);
        arg0 += 1;
    }
    return arg0;
}

/*
 * Best attempt (not matching): 81 target insns, and 81 compiled. The entire
 * body matches instruction-for-instruction; the only difference is GCC 2.6.3
 * callee-saved allocation: target arg0->s0 / arg1->s1, compiled always
 * arg0->s1 / arg1->s0 (the second long-lived parameter wins the lower
 * register). Reproduced in isolation and stable across gcc257/260/263/272.
 *
extern s32 D_8008E0A4[];
extern s32 D_8008E0A8[];
extern s32 D_8008E0AC[];
extern s32 D_8008E0C0[];
extern u8 D_80087174[];
extern u8 D_8008721C[];

s32 *func_80054FD8(s32 *arg0, s32 arg1) {
    func_80055258(arg1, D_80087330[0]);
    if (g_GenerationFlags != 0 && g_GenerationTablePtr == (s32)D_8008726C) {
        D_8008E0A4[0] = 0xFFFF5000;
        D_8008E0A8[0] = -0x2000;
        D_8008E0AC[0] = 0;
        D_8008E0C0[0] = (s32)D_8008721C + 3;
    } else {
        if (D_8008E0AC[0] > 0) {
            D_8008E0AC[0] = -D_8008E0AC[0];
        }
        if (D_8008E0AC[0] < -0x7800) {
            D_8008E0AC[0] = -0x7800;
        }
        D_8008E0C0[0] = (s32)D_8008721C + ((u32)rand() % 3) * 3;
    }
    D_8008E0A4[3] = (s32)D_80087174;
    *arg0 = func_80056320(3, D_8008E0A4, g_GenerationOwner, arg1);
    return arg0 + 1;
}
*/
INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80054FD8);

/*
 * Best attempt (not matching): 79 target insns. Structure, absolute
 * D_80087430 load, base a2 with `addiu a2,a2,4` in the beq delay, and the
 * `j` merge layout all match. Two residual GCC 2.6.3 ties:
 *   1. target arg0->s1 / arg1->s2; compiled always arg0->s2 / arg1->s1.
 *   2. target keeps a single store at the merge (`j .L; nop`); our delay-slot
 *      filler duplicates the store into the `j` delay and the zero block.
 *
s32 *func_8005511C(s32 *arg0, s32 arg1) {
    s32 temp;
    s32 *p;

    temp = ((u32)rand() % 3) * 3;
    p = D_8008E0C0;
    *p++ = (s32)D_80087228 + temp;
    *p = (g_CurrentDay != (g_CurrentDay / 20) * 20) ? D_80087430[0] : 0;
    func_80055258(arg1, D_80087330[0]);
    D_8008E0A4[3] = (s32)D_80087174;
    D_8008E0BC[0] = rand() % 6;
    *arg0 = func_80056320(2, D_8008E0A4, g_GenerationOwner, arg1);
    return arg0 + 1;
}
*/
INCLUDE_ASM("asm/nonmatchings/dream_generation", func_8005511C);

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80055258);

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80055410);

extern s32 *g_GenerationEntityContext;
extern s32 D_800874B0[];

void *func_80055620(s32 *, s32 *, s32);
void sound_entity_init(s32, s32 *, s32, s32, s32);

s32 *func_8005556C(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 *temp_v0;
    u8 *temp_v1;
    s8 temp_a2;
    s8 temp_v2;

    temp_v0 = func_80055620(arg0 + 1, arg0 + 4, arg2);
    if (temp_v0 != NULL) {
        arg0[0] = (s32)temp_v0;
        temp_a2 = *(s8 *)((u8 *)temp_v0 + 6);
        sound_entity_init(*g_GenerationEntityContext, arg0 + 5, temp_a2, (s32)arg0, D_800874B0[temp_a2]);
        temp_v2 = *(s8 *)((u8 *)temp_v0 + 6);
        if (temp_v2 == *arg1) {
            *arg1 = -temp_v2;
        }
        temp_v1 = (u8 *)temp_v0;
        temp_v1[6] = -temp_v1[6];
        return arg0;
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/dream_generation", func_80055620);

extern s32 *g_GenerationEntityContext;

void sound_entity_stop(s32, s32 *);

s32 func_800557DC(s32 *arg0) {
    u8 *temp_v1;

    sound_entity_stop(*g_GenerationEntityContext, (s32 *)arg0 + 5);
    temp_v1 = (u8 *)*arg0;
    temp_v1[6] = -temp_v1[6];
    return 0;
}

void sound_entity_update(s32, s32 *);
s32 func_80055874();

s32 func_8005582C(s32 arg0) {
    if (func_80055874() != 0) {
        sound_entity_update(*g_GenerationEntityContext, (s32 *)(arg0 + 0x14));
        return 1;
    }

    return 0;
}

extern s32 D_80087474[];

s32 func_80055874(s32 *arg0, s32 *arg1) {
    s32 diff;
    s32 temp;
    s32 dist;
    s32 result = 0;
    if (arg1 != NULL) {
        diff = arg0[1] - arg1[0];
        if (diff < 0) diff = ~diff + 1;
        temp = arg0[3] - arg1[2];
        if (temp < 0) dist = diff - temp; else dist = diff + temp;
        arg0[4] = dist;
        if (dist < D_80087474[-((s8 *)*arg0)[6]]) { result = 1; return result; }
    }
    return result;
}

/*
 * Best-known C (77/77 insns; frame, calls, loop, offsets, relocations all
 * correct). Only difference is register allocation of the saved locals: target
 * gives var_s3=$s3, var_s2=$s2, var_s1=$s1, var_s0=$s0, gcc 2.6.3 gives
 * var_s3=$s1, var_s2=$s3, var_s1=$s2, var_s0=$s0 for every declaration order,
 * type (s32 pointer / void pointer / s32), initializer form and temp set tried.
 *
 * s32 func_800558F0(s32 arg0, s32 arg1, s32 arg2) {
 *     s32 sp10[4];
 *     s32 *var_s3 = NULL;
 *     s32 **var_s0;
 *     s32 temp_a0;
 *     s32 temp_v1;
 *     s32 var_s1;
 *     s32 var_s2;
 *
 *     if (arg0 != 0) {
 *         var_s3 = &sp10;
 *         (*(void (**)(s32, s32 *, s32))(*(u32 *)g_GenerationOwner + 0xE8))(
 *             g_GenerationOwner, var_s3, arg0);
 *     }
 *     temp_v1 = g_LocationTimer;
 *     g_LocationTimer = temp_v1 + 1;
 *     if (temp_v1 == 0) {
 *         func_80054660();
 *         func_80054850();
 *         func_80054B84(var_s3);
 *     }
 *     var_s2 = 0;
 *     func_800549A8();
 *     func_80054C74(var_s3);
 *     var_s1 = 0;
 *     func_80055A24();
 *     D_8008AC98 = 0;
 *     var_s0 = D_8008AC9C;
 *     do {
 *         temp_a0 = *var_s0;
 *         if (temp_a0 != 0) {
 *             if (func_8005582C(temp_a0, var_s3, arg1) == 0) {
 *                 *var_s0 = (s32 *)func_800557DC(*var_s0);
 *             }
 *         } else {
 *             *var_s0 = (s32 *)func_8005556C(
 *                 (s32 *)(var_s1 + (s32)D_8008E154), &arg2, (s32)var_s3, arg1);
 *         }
 *         var_s1 += 0x68;
 *         var_s2 += 1;
 *         var_s0 += 1;
 *     } while (var_s2 < 2);
 *     return arg2;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream_generation", func_800558F0);

extern s32 D_80087444[];
extern s32 D_80087450[];
extern s32 D_8008745C[];
extern s32 D_80087468[];
extern s32 g_GenerationLocation;

void func_8003B624(void *, s32, void *);

void func_80055A24(void) {
    if (g_GenerationLocation == 2) {
        func_8003B624(&D_80087444, 1, &D_80087450);
    } else if ((u32)(g_GenerationLocation - 3) < 3) {
        func_8003B624(&D_8008745C, 1, &D_80087468);
    }
}

void func_80055A88(void *arg0, s32 *arg1) {
    s32 value;

    arg1[4] = func_8005627C();
    value = arg1[1];
    if (value == 0) {
        arg1[7] = 7;
        arg1[8] = 0;
        return;
    }
    if (value == 2) {
        arg1[12] = 7;
        arg1[13] = 0;
        return;
    }
    if (value == 5) {
        arg1[17] = 7;
        arg1[18] = 0;
        return;
    }
    if (value >= 8) {
        arg1[1] = -1;
    }
}

s32 func_8005627C();

void func_80055B10(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 0x18;
        arg1[8] = -2;
        return;
    }
    if (arg1[1] >= 0x401) {
        arg1[1] = -1;
    }
}

void func_80055B6C(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 0xC;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 5) {
        arg1[1] = -1;
    }
}

void func_80055BC8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 0x1E;
        arg1[9] = 0x20;
        arg1[8] = 0;
        arg1[10] = 0xA;
    }
    if (arg1[1] % 400 == 0) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
    }
    arg1[17] = 6;
    arg1[19] = 0x20;
    arg1[18] = 0;
    arg1[20] = 0xA;
}

void func_80055CA8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 3 == 0) {
        arg1[7] = 0x1E;
        arg1[8] = 0;
    }
    if (arg1[1] % 5 == 0) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
        arg1[14] = 0x18;
        arg1[15] = 0x18;
    }
    if (arg1[1] % 7 == 0) {
        arg1[7] = 0x1E;
        arg1[8] = 0;
    }
    arg1[17] = 6;
    arg1[18] = 1;
    arg1[19] = 0x2A;
    arg1[20] = 0xA;
}

void func_80055DB4(void *arg0, s32 *arg1) {
    s32 temp;
    s32 v;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x1E;
        arg1[8] = -1;
        return;
    }
    if (temp < 0x32 && (temp / 5) * 5 == temp - 4) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
        v = arg1[14] - arg1[1] * 2;
        arg1[14] = v;
        arg1[15] = v;
        return;
    }
    v = arg1[1];
    if ((u32)(v - 0x65) < 9U) {
        arg1[17] = 0xD;
        arg1[18] = 1;
        return;
    }
    if (v >= 0xC9) {
        arg1[1] = -1;
    }
}

void func_80055E94(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 7;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 0x1B) {
        arg1[1] = -1;
    }
}

void func_80055EF0(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x14;
        arg1[8] = 1;
        return;
    }
    if (temp == 3) {
        arg1[8] = 2;
        arg1[9] = 0x18;
        arg1[7] = temp;
        arg1[10] = 0x14;
        return;
    }
    if (temp >= 0x33) {
        arg1[1] = -1;
    }
}

void func_80055F74(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = 0;
        arg1[9] = 0x40;
        arg1[10] = 0x40;
    }
}

void func_80055FE8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = -2;
    }
}

void func_80056054(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1] % 20;
    if (temp == 1) {
        arg1[7] = 9;
        arg1[8] = -2;
        return;
    }
    if (temp == 0x10) {
        arg1[12] = 9;
        arg1[13] = -2;
    }
}

void func_800560E4(void *arg0, s32 *arg1) {
    s32 temp;

    func_80056054();
    temp = arg1[1] % 70;
    if (temp == 0x32) {
        arg1[17] = 0x14;
        arg1[18] = 1;
    } else if ((u32)(temp - 0x36) < 5U) {
        arg1[17] = 0xD;
        arg1[18] = 1;
    } else if (temp == 0x3D) {
        arg1[17] = 9;
        arg1[18] = -1;
    }
}

void func_80056194(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x14;
        arg1[8] = -2;
        arg1[12] = 0x14;
        arg1[13] = -2;
        return;
    }
    if (temp == 4) {
        arg1[12] = 0x14;
        arg1[13] = -2;
        return;
    }
    if (temp == 0x14) {
        arg1[7] = 0x10;
        arg1[8] = -2;
        arg1[12] = 0x12;
        arg1[13] = -2;
        return;
    }
    if (temp >= 0xC9) {
        arg1[1] = -1;
    }
}

void func_80056238(void *arg0, void *arg1) {
    s32 *p = (s32 *)arg1;

    p[4] = func_8005627C();
    if (p[1] == 0) {
        p[7] = 0x18;
        p[8] = 0;
    }
}

s32 func_8005627C(void *arg0) {
    s32 value;
    s32 divisor;

    value = D_80087474[-(*(s8 **)arg0)[6]];
    divisor = value / *(s32 *)((u8 *)arg0 + 0x28);
    return *(s32 *)((u8 *)arg0 + 0x10) / divisor;
}

extern s32 g_GenerationType;

s32 func_8005630C(void) {
    return (g_GenerationType & 1) ^ 1;
}
