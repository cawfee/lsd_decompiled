#include "common.h"
#include "gfx/effect_base.h"

extern u8 g_GenerationColorPalette[];
extern s32 g_GenerationHeightTable[];

extern s32 g_GenerationOwner;
extern s32 g_GenerationLocation;
extern s32 *g_GenerationEntityContext;
extern s32 g_LocationTimer;
extern s32 g_CurrentDay;
extern s32 g_GenerationSubMode;
extern s32 g_GenerationType;
extern s32 g_GenerationEntitySlot1[];

s32 dream_generation_load();

s32 dream_generation_start(void *a0, s32 a1, s32 *a2, s32 a3, s32 a4) {
    s32 *p;
    s32 i;

    if (g_GenerationOwner == 0) {
        i = 1;
        p = g_GenerationEntitySlot1;
        g_GenerationOwner = (s32)a0;
        g_GenerationLocation = a1;
        g_GenerationEntityContext = a2;
        g_GenerationType = -1;
        g_CurrentDay = a3;
        g_GenerationSubMode = a4;
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

extern s8 *g_GenerationLocationEntries[];
extern u8 *g_GenerationInfo[];
extern s32 g_GenerationEffectColor;
void dream_generation_apply_entry(u8 *, s8 *);
s8 *dream_generation_pick_entry(void);

u8 *dream_generation_load(void) {
    s8 *s0 = g_GenerationLocationEntries[g_GenerationLocation];

    if (s0 == NULL) {
        s0 = dream_generation_pick_entry();
    }
    dream_generation_apply_entry((u8 *)g_GenerationInfo, s0);
    if (s0[1] >= 4) {
        g_GenerationEffectColor = (s32)(g_GenerationColorPalette + s0[2] * 3);
    }
    return (u8 *)g_GenerationInfo;
}

void dream_generation_apply_entry(u8 *arg0, s8 *arg1) {
    *(void **)(arg0 + 0xC) = (u8 *)&g_GenerationColorPalette + arg1[3] * 3;
    *(void **)(arg0 + 0x18) = (u8 *)&g_GenerationColorPalette + arg1[2] * 3;
    *(s32 *)(arg0 + 0x1C) = g_GenerationHeightTable[arg1[1]];
    *(s32 *)(arg0 + 0x14) = arg1[0];
}

extern s32 g_GenerationEffectColor;
extern s32 g_GenerationEffectOrigin[];
extern s32 g_GenerationEffectScreen[];
extern s32 *g_GenerationEntityContext;
extern effect_base_t *g_GenerationEffect;

void dream_generation_create_effect(void) {
    void **ctx;
    s32 result;

    if (g_GenerationEffectColor != 0) {
        g_GenerationEffect = effect_base_create((u32)g_GenerationEffectScreen, (u32)g_GenerationEffectColor, 0);
        g_GenerationEffect->vtable->set_enabled(g_GenerationEffect, 1);
        g_GenerationEffect->vtable->set_mode(g_GenerationEffect, 0);
        ctx = *(void ***)((u8 *)g_GenerationEntityContext + 0xC);
        result = (*(s32 (**)(void *))((u8 *)*ctx + 0xAC))(ctx);
        g_GenerationEffect->vtable->attach_to(g_GenerationEffect, result, g_GenerationEffectOrigin);
    }
}

extern s32 g_GenerationEffectColor;
extern effect_base_t *g_GenerationEffect;

void dream_generation_destroy_effect(void) {
    if (g_GenerationEffectColor != 0) {
        g_GenerationEffect->vtable->Destroy(g_GenerationEffect);
        g_GenerationEffectColor = 0;
    }
}

extern s8 g_GenerationEntryCounts[];
extern u8 *g_GenerationEntryTables[];
extern u8 g_GenerationEffectDataAlt[];
extern u8 g_GenerationEffectData[];
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
    temp_a0 = g_GenerationEntryCounts[4 + (temp_v1 & 0xF)];
    g_GenerationType = temp_a0;
    idx = temp_v1 % g_GenerationEntryCounts[temp_a0];
    g_GenerationIndex = idx;
    entry = (s8 *)(g_GenerationEntryTables[temp_a0] + idx * 4);
    if (temp_a0 == 0) {
        p = g_GenerationEffectData;
        g_GenerationDataPtr = (s32)(g_GenerationColorPalette + entry[3] * 3);
        if (entry[2] != 0x12) {
            p = g_GenerationEffectDataAlt;
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

extern s32 g_GenerationEffectX;
extern s32 g_GenerationEffectY;
extern s32 g_GenerationEffectW;
extern s32 g_GenerationEffectH;
extern effect_base_t *g_GenerationEffects[];

effect_base_t *effect_base_create(u32, u32, u32);

/*
 * Near match (83/86 insns): only three instructions differ, all GCC 2.6.3
 * register allocation. Target reloads g_GenerationFlags for the ==2 test (the
 * value in $v0 was clobbered by the g_GenerationEffectX load) and keeps g_GenerationEffectY in
 * $v1, so it must reload coords[1] from the stack before +0x1E; here gcc keeps
 * g_GenerationEffectY in $a0 and adds directly. Target also computes &g_GenerationEffects into
 * $v1 then copies to $s3 (extra `addu`); gcc materialises $s3 directly. Tried
 * plain and volatile re-reads, local flags copy, &g_GenerationEffects/&g_GenerationEffects[0],
 * and both base[0]/g_GenerationEffects[0] epilogue forms.
 *
 * void dream_generation_create_effects(void) {
 *     s32 coords[4];
 *     s32 i;
 *     s32 offset;
 *     effect_base_t **base;
 *     effect_base_t **cursor;
 *     effect_base_t *obj;
 *     void **ctx;
 *     s32 result;
 *
 *     if (g_GenerationFlags != 0) {
 *         coords[0] = g_GenerationEffectX;
 *         coords[1] = g_GenerationEffectY;
 *         if (*(volatile s32 *)&g_GenerationFlags == 2) {
 *             coords[1] += 0x1E;
 *         }
 *         coords[2] = g_GenerationEffectW;
 *         coords[3] = g_GenerationEffectH;
 *         i = 1;
 *         offset = 3;
 *         base = &g_GenerationEffects[0];
 *         cursor = &g_GenerationEffects[1];
 *         base[0] = effect_base_create((u32)&coords[2], g_GenerationTablePtr, 0x1FFF);
 *         do {
 *             i++;
 *             obj = effect_base_create((u32)&coords[2], offset + g_GenerationTablePtr, 0x1FFF);
 *             *cursor = obj;
 *             cursor++;
 *             obj->vtable->attach_to(obj, (s32)base[0], coords);
 *             offset += 3;
 *             coords[1] += 3;
 *             coords[3] -= 7;
 *         } while (i < 0x12);
 *         ctx = *(void ***)((u8 *)g_GenerationEntityContext + 0xC);
 *         result = (*(s32 (**)(void *))((u8 *)*ctx + 0xAC))(ctx);
 *         g_GenerationEffects[0]->vtable->attach_to(g_GenerationEffects[0], result, coords);
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_create_effects);

void dream_generation_shift_color(u8 *, u8 *, s32);

/*
 * Near match (91/93 insns): the divide-by-600, the two allocations of
 * g_GenerationEffectX/g_GenerationEffectY, the 18-iteration loop and both vtable calls are exact.
 * The only difference is the same GCC 2.6.3 register tie as dream_generation_create_effects:
 * target stores g_GenerationEffectY to the stack, reloads g_GenerationFlags into $v1
 * (clobbering it) and must reload g_GenerationEffectY before +0x1E; gcc keeps g_GenerationEffectY
 * in $a0 and adds directly, and places s2=0 differently in the bne delay.
 * data[2] must be an address-taken array or gcc keeps the +0x1C word in a
 * register. `volatile` on the second g_GenerationFlags read reproduces the
 * target's double load but not the g_GenerationEffectY reload.
 *
 * void dream_generation_update_effects(void) {
 *     u8 color[8];
 *     s32 data[2];
 *     s32 temp;
 *     s32 step;
 *     s32 i;
 *     s32 offset;
 *     effect_base_t **obj;
 *     effect_base_t *item;
 *     void *ctx;
 *
 *     if (g_GenerationFlags != 0) {
 *         ctx = *(void **)((u8 *)g_GenerationEntityContext + 0xC);
 *         temp = (*(s32 *)((u8 *)ctx + 0x18) - *(s32 *)((u8 *)ctx + 0x24)) / 600;
 *         step = temp * 3;
 *         if (step > 0) {
 *             data[0] = g_GenerationEffectX;
 *             data[1] = g_GenerationEffectY;
 *             if (*(volatile s32 *)&g_GenerationFlags == 2) {
 *                 data[1] += 0x1E;
 *             }
 *             i = 0;
 *             offset = 0;
 *             obj = g_GenerationEffects;
 *             data[1] += step * 3;
 *             do {
 *                 dream_generation_shift_color(color, offset + g_GenerationTablePtr, step);
 *                 item = *obj;
 *                 item->vtable->set_color(item, 1, color);
 *                 item = *obj;
 *                 i++;
 *                 offset += 3;
 *                 item->vtable->set_offset(item, (s32)data);
 *                 data[1] += 3;
 *                 obj++;
 *             } while (i < 0x12);
 *             dream_generation_shift_color(color, g_GenerationDataPtr, step);
 *             (*(void (**)(void *, void *))((u8 *)*(void **)ctx + 0x64))(ctx, color);
 *         }
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_update_effects);

void dream_generation_shift_color(u8 *arg0, u8 *arg1, s32 arg2) {
    arg0[0] = arg1[0] - arg2;
    arg0[1] = arg1[1] - arg2;
    arg0[2] = arg1[2] + arg2;
}

extern s32 g_GenerationFlags;
extern base_class_t *g_GenerationEffects[];

void dream_generation_destroy_effects(void) {
    if (g_GenerationFlags != 0) {
        destroy_list(g_GenerationEffects, 0x12);
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
 * void dream_generation_build_entities(s32 arg0) {
 *     s32 byte, pad, temp_v0;
 *     if (g_GenerationType >= 0) {
 *         generation_apply_context(g_GenerationType, (void *)g_GenerationEntityContext[1], g_GenerationEntityContext[2], g_GenerationEntityContext[3]);
 *         byte = ((s8 *)g_GenerationHeightTable)[0x18 + (rand() & 3)];
 *         pad = 0;
 *         if (g_GenerationType == 2) { pad = 0x10 - byte; }
 *         g_GenerationStructureCount = byte + pad;
 *         temp_v0 = (s32)dream_generation_create_structures_type1((s32 *)dream_generation_create_structures_random(g_GenerationStructures, byte, arg0), pad, arg0);
 *         if (g_GenerationType == 0) {
 *             dream_generation_create_structures_type0(temp_v0, arg0);
 *         } else if (g_GenerationType != 2) {
 *             return;
 *         } else {
 *             dream_generation_create_structures_type2(temp_v0, arg0);
 *         }
 *         g_GenerationStructureCount += 1;
 *     }
 * }
 */

INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_build_entities);

#if 0
/* Best match: 34/34 insns, identical loop/call shape.  Residual is GCC 2.6.3
 * frame/regalloc: target frame is 0x28 and keeps the loop index in $s0 / the
 * cursor in $s1; gcc emits a 0x20 frame with index in $s1 / cursor in $s0.
 * (The earlier "empty function" was a real bug in the attempt: g_GenerationStructureCount and
 * g_GenerationStructures are declared below this function, so the first drafts used
 * implicit declarations.)  Tried void**/u8*/base_class_t** cursor forms,
 * declaration order, named obj/vtable temps. */
void dream_generation_update_structure_entities(s32 arg0) {
    s32 i;
    base_class_t **p;

    if (g_GenerationType >= 0) {
        i = 0;
        if (g_GenerationStructureCount > 0) {
            p = g_GenerationStructures;
            do {
                base_class_t *obj = *p;

                ((void (*)(base_class_t *, s32))(*(u32 *)((u8 *)obj->vtable + 0xEC)))(obj, arg0);
                p++;
                i++;
            } while (i < g_GenerationStructureCount);
        }
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_update_structure_entities);

extern s32 g_GenerationType;
extern s32 g_GenerationStructureCount;
extern base_class_t *g_GenerationStructures[];

void dream_generation_destroy_structures(void) {
    if (g_GenerationType >= 0) {
        destroy_list(g_GenerationStructures, g_GenerationStructureCount);
    }
}

extern s32 *g_GenerationEntities[];
s32 dream_generation_stop_entity(s32 *);

void dream_generation_stop(void) {
    s32 **p;
    s32 i;

    dream_generation_destroy_effect();
    i = 0;
    dream_generation_destroy_effects();
    dream_generation_destroy_structures();
    p = g_GenerationEntities;
    do {
        *p = (s32 *)dream_generation_stop_entity(*p);
        i++;
        p++;
    } while (i < 2);
    if (g_GenerationOwner != 0) {
        g_GenerationOwner = 0;
    }
}

extern s32 g_GenerationSampleOffsets[];
extern s32 g_GenerationStructureSprite[];
extern void *g_GenerationSpawnSpriteSet[];
extern s32 g_GenerationSpawnParams[];
extern s32 g_GenerationSpawnRandom[];
extern u8 g_GenerationStructureSpriteData[];
void dream_generation_seed_palette_daily(void);
void dream_generation_seed_palette_random(s32, s32);
s32 generation_structure_create(s32, void *, s32, s32);

s32 *dream_generation_create_structures_random(s32 *arg0, s32 arg1, s32 arg2) {
    void (*seed)(s32, s32);
    s32 i;
    s32 index;

    g_GenerationSpawnRandom[0] = rand() % 7;
    g_GenerationSpawnSpriteSet[0] =
        (void *)(((u32)rand() % 5) * 12 + (s32)g_GenerationStructureSpriteData);
    index = (u32)rand() % 5;
    if (index != 0) {
        index = g_GenerationSampleOffsets[index];
    }
    seed = dream_generation_seed_palette_daily;
    if (g_CurrentDay != (g_CurrentDay / 7) * 7) {
        seed = dream_generation_seed_palette_random;
    }
    for (i = 0; i < arg1; i++) {
        seed(arg2, index);
        *arg0 = generation_structure_create(0, g_GenerationSpawnParams, g_GenerationOwner, arg2);
        arg0 += 1;
    }
    return arg0;
}

s32 *dream_generation_create_structures_type1(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s4;
    s32 var_s0;

    temp_s4 = g_GenerationSampleOffsets[2];
    g_GenerationSpawnSpriteSet[0] = g_GenerationStructureSprite;
    for (var_s0 = 0; var_s0 < arg1; var_s0++) {
        dream_generation_seed_palette_random(arg2, temp_s4);
        *arg0 = generation_structure_create(1, g_GenerationSpawnParams, g_GenerationOwner, arg2);
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
extern s32 g_GenerationSpawnParams[];
extern s32 g_GenerationSpawnSample[];
extern s32 g_GenerationSpawnRoll[];
extern s32 g_GenerationSpawnColor[];
extern u8 g_GenerationSpriteData[];
extern u8 g_GenerationEntityColorsA[];

s32 *dream_generation_create_structures_type0(s32 *arg0, s32 arg1) {
    dream_generation_seed_palette_random(arg1, g_GenerationSampleOffsets[2]);
    if (g_GenerationFlags != 0 && g_GenerationTablePtr == (s32)g_GenerationEffectData) {
        g_GenerationSpawnParams[0] = 0xFFFF5000;
        g_GenerationSpawnSample[0] = -0x2000;
        g_GenerationSpawnRoll[0] = 0;
        g_GenerationSpawnColor[0] = (s32)g_GenerationEntityColorsA + 3;
    } else {
        if (g_GenerationSpawnRoll[0] > 0) {
            g_GenerationSpawnRoll[0] = -g_GenerationSpawnRoll[0];
        }
        if (g_GenerationSpawnRoll[0] < -0x7800) {
            g_GenerationSpawnRoll[0] = -0x7800;
        }
        g_GenerationSpawnColor[0] = (s32)g_GenerationEntityColorsA + ((u32)rand() % 3) * 3;
    }
    g_GenerationSpawnParams[3] = (s32)g_GenerationSpriteData;
    *arg0 = generation_structure_create(3, g_GenerationSpawnParams, g_GenerationOwner, arg1);
    return arg0 + 1;
}
*/
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_create_structures_type0);

/*
 * Best attempt (not matching): 79 target insns. Structure, absolute
 * g_GenerationEntityParamsAlt load, base a2 with `addiu a2,a2,4` in the beq delay, and the
 * `j` merge layout all match. Two residual GCC 2.6.3 ties:
 *   1. target arg0->s1 / arg1->s2; compiled always arg0->s2 / arg1->s1.
 *   2. target keeps a single store at the merge (`j .L; nop`); our delay-slot
 *      filler duplicates the store into the `j` delay and the zero block.
 *
s32 *dream_generation_create_structures_type2(s32 *arg0, s32 arg1) {
    s32 temp;
    s32 *p;

    temp = ((u32)rand() % 3) * 3;
    p = g_GenerationSpawnColor;
    *p++ = (s32)g_GenerationEntityColorsB + temp;
    *p = (g_CurrentDay != (g_CurrentDay / 20) * 20) ? g_GenerationEntityParamsAlt[0] : 0;
    dream_generation_seed_palette_random(arg1, g_GenerationSampleOffsets[2]);
    g_GenerationSpawnParams[3] = (s32)g_GenerationSpriteData;
    g_GenerationSpawnRandom[0] = rand() % 6;
    *arg0 = generation_structure_create(2, g_GenerationSpawnParams, g_GenerationOwner, arg1);
    return arg0 + 1;
}
*/
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_create_structures_type2);

/*
 * Best attempt (not matching: target 110 insns, compiled 108). Structure,
 * signed /23 magic 0xB21642C9, unsigned /7, rand()-based table pick and the
 * negate-if-odd pattern all match. Sole blocker: GCC 2.6.3 CSEs the absolute
 * address of g_GenerationSpawnParams/g_GenerationSpawnRoll across the intervening rand() call and
 * keeps it in a callee-saved register (adds sw s0/sw s1 and a lui/addiu),
 * whereas the target recomputes `lui`/`lw` + `lui`/`sw` each time. Reproduced
 * standalone: `A[0]=1; if(g()&1) A[0]=-A[0];` keeps &A in s0 across g()
 * regardless of volatile. This is a compiler revision difference, not source.
 *
 * void dream_generation_seed_palette_random(s32 unused, s32 arg1) {
 *     if (arg1 == 0) {
 *         arg1 = g_GenerationSampleOffsets[rand() & 3];
 *     }
 *     g_GenerationSpawnSample[0] = arg1;
 *     g_GenerationSpawnParams[0] = (rand() % 23) << 11;
 *     if (rand() & 1) {
 *         g_GenerationSpawnParams[0] = -g_GenerationSpawnParams[0];
 *     }
 *     g_GenerationSpawnRoll[0] = (rand() % 23) << 11;
 *     if (rand() & 1) {
 *         g_GenerationSpawnRoll[0] = -g_GenerationSpawnRoll[0];
 *     }
 *     g_GenerationSpawnSprite[0] = ((u32)rand() % 7) * 12 + (s32)g_GenerationSpriteData;
 *     g_GenerationSpawnIndex[0] = rand() % 5;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_seed_palette_random);

extern s32 g_GenerationSpawnParams[];
extern s32 g_GenerationSpawnSample[];
extern s32 g_GenerationSpawnRoll[];
extern s32 g_GenerationSpawnSprite[];
extern u8 g_GenerationSpriteData[];
extern s32 g_GenerationSpawnIndex[];

void dream_generation_seed_palette_daily(void) {
    s32 d;

    rand();
    g_GenerationSpawnSample[0] = g_GenerationSampleOffsets[1];
    g_GenerationSpawnParams[0] = (rand() % 20) << 11;
    g_GenerationSpawnParams[2] = 0xA000;
    d = g_CurrentDay % 3;
    if (d == 1) {
        g_GenerationSpawnRoll[0] = 0xFFFF6000;
    } else if (d == 2) {
        g_GenerationSpawnRoll[0] = 0x800;
    }
    g_GenerationSpawnSprite[0] = ((u32)rand() % 7) * 12 + (s32)g_GenerationSpriteData;
    g_GenerationSpawnIndex[0] = rand() % 5;
}

extern s32 *g_GenerationEntityContext;
extern s32 g_GenerationEntityEffects[];

void *dream_generation_find_entry(s32 *, s32 *, s32);
void sound_entity_init(s32, s32 *, s32, s32, s32);

s32 *dream_generation_spawn_entity(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 *temp_v0;
    u8 *temp_v1;
    s8 temp_a2;
    s8 temp_v2;

    temp_v0 = dream_generation_find_entry(arg0 + 1, arg0 + 4, arg2);
    if (temp_v0 != NULL) {
        arg0[0] = (s32)temp_v0;
        temp_a2 = *(s8 *)((u8 *)temp_v0 + 6);
        sound_entity_init(*g_GenerationEntityContext, arg0 + 5, temp_a2, (s32)arg0, g_GenerationEntityEffects[temp_a2]);
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

/*
 * Best attempt (not matching: 106/111 insns; prologue/epilogue and body shape
 * correct, residual gcc 2.6.3 register allocation. Target: arg0=$s3,
 * arg1=$s6, arg2=$s4, effect_base=$s7 (hoisted), range base recomputed with
 * $at. gcc: arg0=$s6, arg1=$s7, arg2=$s4, range base hoisted into $s8,
 * diff kept in $s3; frame 0x48 vs 0x50. The entry pointer must be u8* so the
 * two 4-byte copies use lwl/lwr/swl/swr; effect_base explicit hoist did not
 * change the remaining allocation.)
 *
 * extern s32 *g_GenerationStageEntries[];
 * extern s8 g_GenerationStageEntryCounts[];
 * extern s32 g_GenerationEntryIndex;
 * extern s32 g_GenerationEntityRange[];
 * extern s32 g_GenerationEntityEffects[];
 * typedef struct { s32 m_Unk0; s32 m_Unk1; s16 m_Unk2; } generation_entry_out_t;
 *
 * void *dream_generation_find_entry(s32 *arg0, s32 *arg1, s32 arg2) {
 *     generation_entry_out_t out;
 *     s32 count, remaining, i, diff, temp, dist;
 *     u8 *entry, *effect, *effect_base;
 *
 *     if (arg2 == 0) return NULL;
 *     i = 0;
 *     count = *(u8 *)&g_GenerationStageEntryCounts[g_GenerationLocation];
 *     remaining = count - g_GenerationEntryIndex;
 *     entry = (u8 *)g_GenerationStageEntries[g_GenerationLocation] + g_GenerationEntryIndex * 8;
 *     effect_base = (u8 *)g_GenerationEntityEffects + 0x3C;
 *     if (remaining > 0) {
 *         do {
 *             g_GenerationEntryIndex += 1;
 *             if (*(s8 *)(entry + 6) > 0) {
 *                 __builtin_memcpy(&out.m_Unk0, entry, 4);
 *                 effect = effect_base + *(u8 *)(entry + 4) * 6;
 *                 __builtin_memcpy(&out.m_Unk1, effect, 4);
 *                 out.m_Unk2 = *(s16 *)(effect + 4);
 *                 (*(void (**)(s32, s32 *, generation_entry_out_t *))(*(u32 *)g_GenerationOwner + 0xE8))(g_GenerationOwner, arg0, &out);
 *                 diff = arg0[0] - arg2[0];
 *                 if (diff < 0) diff = ~diff + 1;
 *                 temp = arg0[2] - arg2[2];
 *                 if (temp < 0) dist = diff - temp; else dist = diff + temp;
 *                 *arg1 = dist;
 *                 i += 1;
 *                 if (dist < g_GenerationEntityRange[*(s8 *)(entry + 6)]) return entry;
 *             } else {
 *                 i += 1;
 *             }
 *             entry = entry + 8;
 *         } while (i < remaining);
 *     }
 *     return NULL;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_find_entry);

extern s32 *g_GenerationEntityContext;

void sound_entity_stop(s32, s32 *);

s32 dream_generation_stop_entity(s32 *arg0) {
    u8 *temp_v1;

    sound_entity_stop(*g_GenerationEntityContext, (s32 *)arg0 + 5);
    temp_v1 = (u8 *)*arg0;
    temp_v1[6] = -temp_v1[6];
    return 0;
}

void sound_entity_update(s32, s32 *);
s32 dream_generation_entity_in_range();

s32 dream_generation_update_entity(s32 arg0) {
    if (dream_generation_entity_in_range() != 0) {
        sound_entity_update(*g_GenerationEntityContext, (s32 *)(arg0 + 0x14));
        return 1;
    }

    return 0;
}

extern s32 g_GenerationEntityRange[];

s32 dream_generation_entity_in_range(s32 *arg0, s32 *arg1) {
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
        if (dist < g_GenerationEntityRange[-((s8 *)*arg0)[6]]) { result = 1; return result; }
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
 * s32 dream_generation_update(s32 arg0, s32 arg1, s32 arg2) {
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
 *         dream_generation_create_effect();
 *         dream_generation_create_effects();
 *         dream_generation_build_entities(var_s3);
 *     }
 *     var_s2 = 0;
 *     dream_generation_update_effects();
 *     dream_generation_update_structure_entities(var_s3);
 *     var_s1 = 0;
 *     dream_generation_update_border();
 *     g_GenerationEntryIndex = 0;
 *     var_s0 = g_GenerationEntities;
 *     do {
 *         temp_a0 = *var_s0;
 *         if (temp_a0 != 0) {
 *             if (dream_generation_update_entity(temp_a0, var_s3, arg1) == 0) {
 *                 *var_s0 = (s32 *)dream_generation_stop_entity(*var_s0);
 *             }
 *         } else {
 *             *var_s0 = (s32 *)dream_generation_spawn_entity(
 *                 (s32 *)(var_s1 + (s32)g_GenerationEntitySlotData), &arg2, (s32)var_s3, arg1);
 *         }
 *         var_s1 += 0x68;
 *         var_s2 += 1;
 *         var_s0 += 1;
 *     } while (var_s2 < 2);
 *     return arg2;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_generation", dream_generation_update);

extern s32 g_GenerationBorderRect0[];
extern s32 g_GenerationBorderRect1[];
extern s32 g_GenerationBorderRect2[];
extern s32 g_GenerationBorderRect3[];
extern s32 g_GenerationLocation;

void display_draw_border(void *, s32, void *);

void dream_generation_update_border(void) {
    if (g_GenerationLocation == 2) {
        display_draw_border(&g_GenerationBorderRect0, 1, &g_GenerationBorderRect1);
    } else if ((u32)(g_GenerationLocation - 3) < 3) {
        display_draw_border(&g_GenerationBorderRect2, 1, &g_GenerationBorderRect3);
    }
}

/*
 * The 14 callbacks below are g_GenerationEntityEffects[1..14] (0x800874B0),
 * installed as the sound_entity_init effect driver for a spawned generation
 * entry.  arg1 is the entity_context_t (see entity.h) reached as s32 slots:
 *   [0] state  [1] tick  [2] owner  [3] callback  [4] motion  [5] divisor
 *   slots[0] [6..10] and slots[1] [11..15] and slots[2] [16..20], each
 *   { handle, id, param, period, counter }.
 * Each handler records generation_entity_get_motion() in [4] and then writes
 * effect ids/params into the three slots according to the entity's tick.
 */
void generation_entity_effect_01(void *arg0, s32 *arg1) {
    s32 value;

    arg1[4] = generation_entity_get_motion();
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

s32 generation_entity_get_motion();

void generation_entity_effect_02(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
    if (arg1[1] == 0) {
        arg1[7] = 0x18;
        arg1[8] = -2;
        return;
    }
    if (arg1[1] >= 0x401) {
        arg1[1] = -1;
    }
}

void generation_entity_effect_03(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
    if (arg1[1] == 0) {
        arg1[7] = 0xC;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 5) {
        arg1[1] = -1;
    }
}

void generation_entity_effect_04(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_05(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_06(void *arg0, s32 *arg1) {
    s32 temp;
    s32 v;

    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_07(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
    if (arg1[1] == 0) {
        arg1[7] = 7;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 0x1B) {
        arg1[1] = -1;
    }
}

void generation_entity_effect_08(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_09(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = 0;
        arg1[9] = 0x40;
        arg1[10] = 0x40;
    }
}

void generation_entity_effect_10(void *arg0, s32 *arg1) {
    arg1[4] = generation_entity_get_motion();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = -2;
    }
}

void generation_entity_effect_11(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_12(void *arg0, s32 *arg1) {
    s32 temp;

    generation_entity_effect_11();
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

void generation_entity_effect_13(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = generation_entity_get_motion();
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

void generation_entity_effect_14(void *arg0, void *arg1) {
    s32 *p = (s32 *)arg1;

    p[4] = generation_entity_get_motion();
    if (p[1] == 0) {
        p[7] = 0x18;
        p[8] = 0;
    }
}

s32 generation_entity_get_motion(void *arg0) {
    s32 value;
    s32 divisor;

    value = g_GenerationEntityRange[-(*(s8 **)arg0)[6]];
    divisor = value / *(s32 *)((u8 *)arg0 + 0x28);
    return *(s32 *)((u8 *)arg0 + 0x10) / divisor;
}

extern s32 g_GenerationType;

s32 dream_generation_type_is_even(void) {
    return (g_GenerationType & 1) ^ 1;
}

/* .sdata companions (defined in dream_generation_sdata.c). */
extern u8 g_GenerationInfoColor[];
extern u8 g_GenerationEntityColorDefault[];
extern s8 g_GenerationEntryDefault[];
extern s8 g_GenerationEntryA[];
extern s8 g_GenerationEntryB[];
extern s8 g_GenerationEntryC[];

/*
 * Dream generation .data tables.  All objects are kept larger than 8
 * bytes so GCC's -G8 small-data rule keeps them in .data; the few
 * original <=8-byte tables are folded into the neighbouring tables
 * (see the size comments in config/symbols.txt) and are referenced
 * through their base symbol plus a constant offset.
 */

u8 g_GenerationSpriteData[84] = {
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x78, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0xB4, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0xE6, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0xFB, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0xFD, 0xFF, 0x01, 0x00, 0xB4, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
};

u8 g_GenerationStructureSpriteData[60] = {
    0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0x00, 0x01, 0x00,
    0x06, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0x00, 0x01, 0x00,
    0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x06, 0x00, 0x01, 0x00,
    0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x02, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0x00, 0x01, 0x00,
};

s32 g_GenerationStructureSprite[6] = {
    0x00010001, 0x00010001, 0x00010001, 0x00010002, 0x00010001, 0x00010002,
};

u8 g_GenerationEntityColorsA[12] = {
    0xFF, 0xE6, 0xB4, 0xFF, 0xB4, 0xB4, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 g_GenerationEntityColorsB[12] = {
    0xFF, 0x80, 0x00, 0xC8, 0xC8, 0xFF, 0x80, 0x80, 0xFF, 0x00, 0x00, 0x00,
};

u8 g_GenerationEffectDataAlt[56] = {
    0x37, 0x77, 0x94, 0x3C, 0x79, 0x97, 0x41, 0x7B, 0x9A, 0x46, 0x7D, 0x9D,
    0x4B, 0x7F, 0xA0, 0x50, 0x81, 0xA3, 0x55, 0x83, 0xA6, 0x5A, 0x85, 0xA9,
    0x5F, 0x87, 0xAC, 0x64, 0x89, 0xAF, 0x69, 0x8B, 0xB2, 0x6E, 0x8D, 0xB5,
    0x73, 0x8F, 0xB8, 0x78, 0x96, 0xBB, 0x7B, 0x98, 0xBE, 0x7E, 0x99, 0xC0,
    0x80, 0x9A, 0xC1, 0x82, 0x9B, 0xC2, 0x00, 0x00,
};

u8 g_GenerationEffectData[56] = {
    0x37, 0x77, 0x94, 0x3C, 0x79, 0x97, 0x41, 0x7B, 0x9A, 0x46, 0x7D, 0x9D,
    0x4B, 0x7F, 0xA0, 0x50, 0x81, 0xA3, 0x5A, 0x83, 0xA6, 0x6E, 0x85, 0xA9,
    0x82, 0x87, 0xAC, 0x96, 0x89, 0xAF, 0xAA, 0x8B, 0xB2, 0xBE, 0x8D, 0xB5,
    0xD2, 0x8F, 0xB8, 0xE6, 0x96, 0xBB, 0xEB, 0x98, 0xBE, 0xF0, 0x99, 0xC0,
    0xF5, 0x9A, 0xC1, 0xFA, 0x9B, 0xC2, 0x00, 0x00,
};

u8 g_GenerationInfoDefaultA[20] = {
    0x32, 0x00, 0x2C, 0x01, 0x3C, 0x00, 0x00, 0x00, 0xF4, 0x01, 0xC4, 0xFF,
    0xD4, 0xFE, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00,
};

u8 g_GenerationInfoDefaultB[12] = {
    0xC8, 0xC8, 0xC8, 0xC8, 0xF0, 0xF0, 0xFF, 0xE6, 0xE6, 0x00, 0x00, 0x00,
};

u8 g_GenerationColorPalette[72] = {
    0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF,
    0x40, 0x00, 0x00, 0x08, 0x20, 0x08, 0x20, 0x20, 0x08, 0x18, 0x08, 0x08,
    0x18, 0x18, 0x08, 0x18, 0x18, 0x80, 0x08, 0x08, 0x18, 0xFF, 0x00, 0x00,
    0x64, 0x8C, 0xB4, 0x32, 0x77, 0x91, 0x82, 0x9B, 0xC2, 0x00, 0x64, 0xBE,
    0x00, 0x32, 0x1E, 0x46, 0x32, 0x00, 0xFA, 0x9B, 0xC2, 0x00, 0xFF, 0x00,
    0x78, 0x8C, 0xB4, 0x78, 0x00, 0xB4, 0xB4, 0x00, 0x78, 0x00, 0x00, 0x00,
};

s32 g_GenerationHeightTable[7] = {
    0x00006800, 0x00005000, 0x00003800, 0x00002000, 0x00001000, 0x00000800,
    0x10080300,
};

s32 g_GenerationSampleOffsets[4] = {
    0xFFFFE800, 0xFFFFD800, 0xFFFFC800, 0xFFFFB000,
};

s8 g_GenerationEntryTableData[144] = {
    0x00, 0x02, 0x0A, 0x0A, 0x00, 0x01, 0x0E, 0x0D, 0x00, 0x01, 0x0E, 0x0D, 0x00, 0x02, 0x0E, 0x0D,
    0x00, 0x01, 0x12, 0x0D, 0x00, 0x02, 0x12, 0x0D, 0x00, 0x01, 0x0E, 0x0D, 0x00, 0x02, 0x0E, 0x0D,
    0x00, 0x02, 0x14, 0x0C, 0x00, 0x03, 0x03, 0x03, 0x00, 0x02, 0x03, 0x03, 0x00, 0x01, 0x03, 0x03,
    0x00, 0x00, 0x15, 0x15, 0x00, 0x01, 0x13, 0x13, 0x00, 0x02, 0x02, 0x02, 0x00, 0x03, 0x02, 0x02,
    0x00, 0x04, 0x02, 0x02, 0x00, 0x03, 0x15, 0x16, 0x00, 0x04, 0x01, 0x01, 0x00, 0x02, 0x03, 0x00,
    0x01, 0x02, 0x03, 0x00, 0x02, 0x02, 0x03, 0x00, 0x00, 0x02, 0x07, 0x0A, 0x01, 0x02, 0x07, 0x0A,
    0x02, 0x02, 0x07, 0x0A, 0x00, 0x02, 0x08, 0x0A, 0x01, 0x02, 0x08, 0x0A, 0x02, 0x02, 0x08, 0x0A,
    0x00, 0x02, 0x06, 0x06, 0x00, 0x02, 0x05, 0x05, 0x00, 0x01, 0x04, 0x04, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x03, 0x09, 0x09, 0x00, 0x03, 0x16, 0x11, 0x00, 0x03, 0x10, 0x10, 0x00, 0x03, 0x11, 0x11,
};

u8 *g_GenerationEntryTables[4] = {
    (u8 *)(g_GenerationEntryTableData + 0x08),
    (u8 *)(g_GenerationEntryTableData + 0x24),
    (u8 *)(g_GenerationEntryTableData + 0x4C),
    (u8 *)(g_GenerationEntryTableData + 0x7C),
};

s8 g_GenerationEntryCounts[20] = {
    0x07, 0x0A, 0x0C, 0x05, 0x00, 0x01, 0x02, 0x03, 0x01, 0x02, 0x03, 0x00,
    0x00, 0x00, 0x02, 0x02, 0x01, 0x03, 0x01, 0x00,
};

s8 *g_GenerationLocationEntries[14] = {
    NULL, NULL, NULL, NULL, NULL, (s8 *)(g_GenerationEntryTableData + 0x00),
    g_GenerationEntryDefault, g_GenerationEntryDefault, g_GenerationEntryB,
    g_GenerationEntryDefault, g_GenerationEntryC, g_GenerationEntryA,
    g_GenerationEntryA, NULL,
};

u8 *g_GenerationInfo[3] = {
    g_GenerationInfoDefaultA, g_GenerationInfoDefaultB, g_GenerationInfoColor,
};

s32 g_GenerationEntityParamsAlt[5] = {
    0, (s32)g_GenerationEntityColorDefault, -1, 0, 0,
};

s32 g_GenerationBorderRect0[3] = {
    0x01F00000, 0x000000F8, 0x00000008,
};

s32 g_GenerationBorderRect1[3] = {
    0x01F00100, 0x00000001, 0x00000008,
};

s32 g_GenerationBorderRect2[3] = {
    0x01F80000, 0x000000F8, 0x00000008,
};

s32 g_GenerationBorderRect3[3] = {
    0x01F80100, 0x00000001, 0x00000008,
};

s32 g_GenerationEntityRange[15] = {
    0x00000000, 0x00014000, 0x0000A000, 0x00004000, 0x0000A000, 0x0000F000,
    0x00014000, 0x00014000, 0x0000A000, 0x0000A000, 0x00005000, 0x0000A000,
    0x0000F000, 0x0000A000, 0x00001000,
};

s32 g_GenerationEntityEffects[17] = {
    0,
    (s32)generation_entity_effect_01, (s32)generation_entity_effect_02,
    (s32)generation_entity_effect_03, (s32)generation_entity_effect_04,
    (s32)generation_entity_effect_05, (s32)generation_entity_effect_06,
    (s32)generation_entity_effect_07, (s32)generation_entity_effect_08,
    (s32)generation_entity_effect_09, (s32)generation_entity_effect_10,
    (s32)generation_entity_effect_11, (s32)generation_entity_effect_12,
    (s32)generation_entity_effect_13, (s32)generation_entity_effect_14,
    0, 0,
};

s8 g_GenerationStageEntryData[448] = {
    0x00, 0x02, 0x06, 0x08, 0x00, 0x00, 0x0E, 0x00, 0x04, 0x03, 0x0B, 0x04, 0x00, 0x00, 0x09, 0x00,
    0x03, 0x00, 0x10, 0x09, 0x00, 0x00, 0x04, 0x00, 0x04, 0x01, 0x06, 0x02, 0x00, 0x00, 0x04, 0x00,
    0x04, 0x01, 0x05, 0x0E, 0x00, 0x00, 0x04, 0x00, 0x03, 0x02, 0x0F, 0x05, 0x00, 0x00, 0x04, 0x00,
    0x03, 0x02, 0x0F, 0x11, 0x00, 0x00, 0x04, 0x00, 0x04, 0x03, 0x05, 0x09, 0x00, 0x00, 0x04, 0x00,
    0x03, 0x04, 0x10, 0x01, 0x00, 0x00, 0x04, 0x00, 0x03, 0x04, 0x10, 0x0D, 0x00, 0x00, 0x04, 0x00,
    0x07, 0x04, 0x07, 0x06, 0x00, 0x00, 0x01, 0x00, 0x0A, 0x04, 0x0E, 0x0B, 0x00, 0x00, 0x01, 0x00,
    0x05, 0x01, 0x03, 0x0A, 0x00, 0x00, 0x02, 0x00, 0x09, 0x03, 0x00, 0x06, 0x00, 0x00, 0x05, 0x00,
    0x0A, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x05, 0x00, 0x0A, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x05, 0x00,
    0x0A, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x05, 0x00, 0x02, 0x00, 0x09, 0x09, 0x00, 0x00, 0x0C, 0x00,
    0x0A, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x0C, 0x00,
    0x04, 0x01, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x01, 0x08, 0x13, 0x00, 0x00, 0x01, 0x00,
    0x08, 0x02, 0x0A, 0x0C, 0x00, 0x00, 0x01, 0x00, 0x07, 0x04, 0x07, 0x05, 0x00, 0x00, 0x01, 0x00,
    0x0A, 0x04, 0x0E, 0x0C, 0x00, 0x00, 0x01, 0x00, 0x02, 0x05, 0x02, 0x0B, 0x00, 0x00, 0x01, 0x00,
    0x05, 0x07, 0x13, 0x07, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x03, 0x0A, 0x00, 0x00, 0x0C, 0x00,
    0x0A, 0x00, 0x01, 0x13, 0x00, 0x00, 0x0C, 0x00, 0x05, 0x01, 0x13, 0x07, 0x00, 0x00, 0x0C, 0x00,
    0x0C, 0x01, 0x00, 0x0C, 0x00, 0x00, 0x0C, 0x00, 0x07, 0x02, 0x04, 0x03, 0x00, 0x00, 0x0C, 0x00,
    0x09, 0x02, 0x11, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x07, 0x05, 0x0F, 0x08, 0x00, 0x00, 0x0C, 0x00,
    0x06, 0x07, 0x05, 0x08, 0x00, 0x00, 0x0C, 0x00, 0x05, 0x08, 0x07, 0x0B, 0x00, 0x00, 0x0C, 0x00,
    0x0D, 0x0D, 0x0F, 0x0F, 0x00, 0x00, 0x0C, 0x00, 0x01, 0x0E, 0x01, 0x0F, 0x00, 0x00, 0x0C, 0x00,
    0x0D, 0x0E, 0x09, 0x09, 0x00, 0x00, 0x0C, 0x00, 0x05, 0x03, 0x02, 0x09, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x02, 0x10, 0x11, 0x00, 0x00, 0x08, 0x00, 0x01, 0x04, 0x10, 0x0D, 0x00, 0x00, 0x06, 0x00,
    0x01, 0x04, 0x11, 0x00, 0x00, 0x00, 0x06, 0x00, 0x02, 0x04, 0x0E, 0x02, 0x00, 0x00, 0x06, 0x00,
    0x04, 0x05, 0x00, 0x06, 0x00, 0x00, 0x0B, 0x00, 0x04, 0x05, 0x00, 0x06, 0x00, 0x00, 0x07, 0x00,
    0x02, 0x05, 0x02, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x04, 0x12, 0x0F, 0x00, 0x00, 0x07, 0x00,
    0x01, 0x03, 0x08, 0x0D, 0x00, 0x00, 0x07, 0x00, 0x00, 0x02, 0x12, 0x11, 0x00, 0x00, 0x07, 0x00,
    0x01, 0x01, 0x07, 0x13, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x12, 0x12, 0x00, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x12, 0x05, 0x00, 0x00, 0x07, 0x00, 0x02, 0x00, 0x08, 0x0A, 0x00, 0x00, 0x0A, 0x00,
    0x01, 0x01, 0x0C, 0x08, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x09, 0x00, 0x00, 0x0D, 0x00,
};

s32 *g_GenerationStageEntries[14] = {
    (s32 *)(g_GenerationStageEntryData + 0x000), NULL,
    (s32 *)(g_GenerationStageEntryData + 0x008), (s32 *)(g_GenerationStageEntryData + 0x050),
    (s32 *)(g_GenerationStageEntryData + 0x138), (s32 *)(g_GenerationStageEntryData + 0x160),
    NULL, NULL, NULL, NULL,
    (s32 *)(g_GenerationStageEntryData + 0x1A8), (s32 *)(g_GenerationStageEntryData + 0x1B0),
    NULL, (s32 *)(g_GenerationStageEntryData + 0x1B8),
};

s8 g_GenerationStageEntryCounts[16] = {
    0x01, 0x00, 0x09, 0x1D, 0x05, 0x09, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x00, 0x00,
};

