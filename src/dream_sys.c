\#include <psx/rand.h>
#include "dream_sys.h"


#include "477E4.h"
#include "base_class.h"
#include "stage_grid.h"

extern dream_sys_vtable_t g_DREAM_SYS_VTABLE;

extern s32 STAGE_PERMALINK_SPAWNS[];
extern s32 STAGE_PERMALINK_TRIGGERS[];
extern s32 LEN_STAGE_PERMALINK_TRIGGERS[];
extern s32 D_80088820[];
extern s32 D_80088980[];
extern s32 D_800889F0[];
extern s32 D_80088A80[];
extern s32 D_80088B24[];
extern s32 D_80088B5C[];
extern s32 D_80088BA4[];
extern s32 D_80088C4C[];
extern s32 D_80088CBC[];
extern s16 STAGE_TIME_LIMITS[];
extern s16 *STAGE_SPAWNPOINTS[];
extern u8 LEN_STAGE_SPAWNPOINTS[];
extern s32 D_8008ABE4;
extern s32 D_8008ABF0[];
extern s32 gpNavChallengesComplete;
extern s32 gpDinamicLinkPenalty;
extern s32 D_8008ACBC;
extern s32 D_8008ACC0;
extern s32 D_8008ACC4;
extern s32 D_8008ACC8;
extern u8 *D_80088C84[];
extern u8 *D_80088BDC[];
extern u8 *D_800889B8[];
extern u8 *D_80088858[];
extern u8 D_80088758[];
extern s16 SPAWN_POS_ADJUST[];
extern s32 D_80087E50[];
extern s32 D_80087E5C[];
extern s32 D_80087E68[];
extern s32 D_80087E74[];
extern s32 D_80087E80[];
extern s16 D_80087E84[];
extern s32 D_80087EA4[];
extern s32 D_80087E08[];
extern s32 D_8008ABE0;
extern u8 D_8008875C[];
extern s8 D_80087E14[];
extern s16 D_8008ABD0[];
extern s16 D_8008ABC0[];
extern s16 D_8008ABC8[];
extern s16 D_8008ABD8[];
extern s32 D_80087EFC[];
extern s32 D_80087F08[];

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2);
s32 execute_link(dream_sys_t *This, s32 Unk1, s32 Unk2, s32 Unk3);
s32 test_4_tunnel_links(void *Unk0, s32 Unk1, s32 Unk2);
void func_8001E6F8(void *This, void *out);
s32 func_8005BD3C(void *a, void *b, void *c);
s32 func_8005AF64(dream_sys_t *This, s16 *a, s16 *b);
s32 func_8005BE28(s16 *arg0, s32 arg1);
s32 get_random_spawn_from_stage(void *dst, s32 chunk, s32 tick);
s32 calc_navigation_score(void);
void helper_1_update_entity(s32 arg0, void *arg1);
void init_nav_challenges_array(s32 *Unk1, s32 *Unk2);
void *memset(void *s, int c, u32 n);

typedef struct {
    u8 m_data[8];
    s16 m_hi;
} dream_sys_fb_pkt10_t;

typedef struct {
    u8 m_data[12];
} dream_sys_fb_pkt12_t;

typedef struct {
    u8 m_data[4];
} dream_sys_pkt4_t;

typedef struct {
    u8 m_data[4];
    s16 m_hi;
} dream_sys_pkt6_t;

dream_sys_t *dream_sys_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    dream_sys_t *allocated = (dream_sys_t *) memory_allocate_mem(0x928);

    if (allocated) {
        dream_sys_get_vtable()->dream_sys_construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void dream_sys_construct(dream_sys_t *This, void *Unk1, s32 Unk2, s32 Unk3) {
    func_80057C84()->Construct(This);
    This->vtable = dream_sys_get_vtable();
    This->m_Unk21 = Unk2;
    This->m_Unk22 = Unk3;
    This->m_Unk24 = 0;
    This->m_Unk23 = (s32)Unk1;
    This->vtable->Unk3(
        This, (*(s32(**)(void *, s32))(*(u32 *)Unk1 + 0x80))(Unk1, 0));
    This->vtable->dream_sys__get_set_dream_time_limit(This, -1);
    This->m_Unk27 = 1;
    This->m_Unk26 = 0;
    This->m_Unk541 = 1;
    This->vtable->dream_sys__init_new_game(This);
    This->vtable->dream_sys_unk15(This);
}

void dream_sys_unk15(dream_sys_t *This) {
    This->vtable->Unk23(This, 0);
    This->vtable->Unk16(This, 1, &D_80087E08);
    This->m_Unk31 = 0;
    This->m_Unk37 = 0;
    This->m_Unk50 = 0;
    This->m_Unk577 = 0;
    This->m_Unk578 = 0;
    This->m_Unk579 = 0;
    This->m_Unk29 = 0;
    This->m_Unk584 = 0;
}

void dream_sys_unk18(dream_sys_t *This, void **arg1) {
    s32 sp10[4];
    u8 *slot;
    s32 off;

    ((void (*)(void **, void *, void *, void *))*(void **)((u8 *)*arg1 + 0xE4))(
        arg1, sp10, This, (u8 *)This + 0x16C);
    ((void (*)(void *, void **, void *))func_80057C84()->Unk18)(This, arg1, sp10);
    This->vtable->Unk3(This, arg1);
    if (This->m_Unk16 == 0xE) {
        off = *(s32 *)((u8 *)This + 0x87C) * 0x24 + 0x470;
        slot = (u8 *)This + off;
        This->vtable->Unk16(This, 1, (s32 *)(slot + 0xE));
        This->vtable->dream_sys__get_set_dream_time_limit(This, *(s16 *)(slot + 0x1A) + 4);
        *(s32 *)((u8 *)This + 0x87C) = *(s32 *)((u8 *)This + 0x87C) + 1;
    }
    if (This->m_Unk26 != 0) {
        if (*(s32 *)((u8 *)This + 0x888) != 0) {
            This->vtable->Unk16(This, 1, (s32 *)*(s32 *)((u8 *)This + 0x888));
        }
    }
}

void func_80058A94(dream_sys_t *This) {
    void **temp_a0;

    temp_a0 = (void **)This->m_Unk18;
    ((void (*)(void **))(*(void **)((s8 *)*temp_a0 + 0xF0)))(temp_a0);
    This->vtable->Unk4(This, (void *)This->m_Unk18);
    func_80057C84()->Unk19(This);
}

void func_80058B08(dream_sys_t *This, s32 arg1) {
    void **obj;
    s32 *link;
    s32 value;
    s32 surface;

    func_80057C84()->Unk33(This, arg1);
    if (arg1 == -2) {
        goto neg2;
    }
    if (arg1 != -1) {
        return;
    }
    surface = *(u16 *)(This->m_Unk9 + 0x36) & 0x7F;
    This->m_FloorSurfaceType = surface;
    if (surface >= 0x18) {
        This->m_FloorSurfaceType = 0;
    }
    if (This->m_Unk16 == 0xF && This->m_FloorSurfaceType == 0) {
        This->m_FloorSurfaceType = 2;
    }
    if (This->m_NextMap == 9) {
        goto shared;
    }
    return;
neg2:
    obj = (void **)This->m_Unk18;
    link = ((s32 *(*)(void *, s32))(*(void **)((u8 *)*obj + 0x11C)))(obj, This->m_Unk4 + 0x18);
    if (*(s16 *)(link[1] + 0x2C) != 2) {
        goto other;
    }
shared:
    obj = (void **)This->m_Unk18;
    value = (*(s32 (**)(void **, s32, s32))(*(u32 *)obj + 0x10C))(obj, 0, 0);
    This->vtable->Unk116(This, value);
    return;
other:
    This->vtable->Unk136(This);
}

void set_move_from_pad(dream_sys_t *This, s32 arg1, s32 arg2) {
    if (This->m_Unk26 != 0) {
        return;
    }
    if (This->m_Unk27 != 0) {
        return;
    }
    if (This->m_Unk577 != 0) {
        return;
    }
    arg2 -= 2;
    switch (arg2) {
    case 0:
        This->m_MoveState = MOVE_FORWARD;
        return;
    case 1:
        This->m_MoveState = MOVE_BACKWARDS;
        return;
    case 2:
        This->m_LeftRightState = 1;
        return;
    case 3:
        This->m_LeftRightState = 2;
        return;
    case 4:
        This->m_LookUpDownState = 1;
        return;
    case 5:
        if (This->m_MoveState != MOVE_FORWARD) {
            return;
        }
        This->vtable->Unk96(This, 4);
        return;
    case 6:
        This->m_LookUpDownState = 2;
        return;
    case 11:
        This->m_Unk35 = 2;
        return;
    case 12:
        This->m_MoveState = MOVE_RIGHT;
        return;
    case 13:
        This->m_Unk35 = 1;
        return;
    case 14:
        This->m_MoveState = MOVE_LEFT;
        return;
    case 23:
        This->m_Unk28 = 1;
        return;
    case 32:
        ((void (*)(dream_sys_t *))This->vtable->Unk97)(This);
        return;
    case 47:
        return;
    default:
        return;
    }
}

s32 dream_sys__timer_tick(dream_sys_t *This, s32 arg1, s32 arg2) {
    u32 tick;
    s32 temp;

    temp = 2;
    if (arg2 == 2) {
        tick = This->m_GameTick;
        This->m_GameTick = tick + 1;
        if (tick >= (u32)This->m_DreamTimeLimit) {
            if (This->m_Unk25 != 0) {
                temp = This->m_Unk16;
                if ((temp != 0) || ((temp = This->vtable->dream_sys__load_next_flashback(This, 0)) != 0)) {
                    This->m_GameTick = 0;
                    return temp;
                }
            } else {
                This->vtable->dream_sys__flashback_saving(This, 0, 0x10);
            }
            This->vtable->Unk11(This, 0xA);
            This->m_GameTick = 0;
        } else {
            This->vtable->Unk69(This);
            This->vtable->Unk70(This);
        }
    }
#ifdef NON_MATCHING
    return temp;
#endif
}

void func_80058E8C(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk38(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFF) == 0x114) {
        This->vtable->dream_sys__process_chunk_change(This, Unk2, Unk3);
    }
}

void func_80058F18(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk54(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFFFF) == 0x1F234) {
        This->vtable->dream_sys__instance_effects_on_journal(This, Unk2, Unk3);
    }
}

void dream_sys__wall_link(dream_sys_t *This, s32 arg1, s32 arg2) {
    void **obj;
    void *pkt;

    ((void (*)(void *, s32, s32))func_80057C84()->Unk55)(This, arg1, arg2);
    if ((arg2 == 4) && (This->m_Unk16 == 0)) {
        obj = (void **)This->m_Unk18;
        pkt = ((void *(*)(void *, s32))(*(void **)((u8 *)*obj + 0xD4)))(obj, arg1);
        *(dream_sys_fb_pkt10_t *)&This->m_Unk90 = *(dream_sys_fb_pkt10_t *)pkt;
        if (This->vtable->dream_sys__static_wall_link(This, (s32)&This->m_Unk90) == 0) {
            if (This->m_Unk72 != 0) {
                This->vtable->dream_sys__dynamic_link(This);
            }
        }
        This->vtable->Unk136(This);
        This->vtable->Unk57(This);
    }
}

void func_800590E0(void) {
}

s32 func_800590E8(dream_sys_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    value = This->m_Unk25;
    if (Unk3 < 0) {
        *Unk2 = (void *) calc_dream_color((char *) &This->m_Unk99 + 2 * This->m_Unk95);
    } else {
        This->m_Unk25 = Unk3;
    }

    return value;
}

void func_80059148(dream_sys_t *This, s32 arg1) {
    This->m_Unk26 = arg1;
    if (arg1 != 0) {
        This->vtable->Unk95(This, 1);
        if (This->m_Unk544 != 0) {
            This->vtable->Unk16(This, 1, (s32 *)This->m_Unk544);
        }
    }
}

typedef struct {
    s32 m_Pad0;
    s32 m_Pad1;
    s16 m_A;
    s16 m_B;
    s32 m_Pad2;
} dream_sys_link_buf_t;

void reset_motion_for_link(dream_sys_t *This, s32 arg1, s32 arg2) {
    dream_sys_link_buf_t buf;

    This->vtable->dream_sys__log_chunk_mood(This, &This->m_Unk90);
    This->vtable->Unk77(This, 1);
    This->vtable->Unk78(This, 1);
    This->vtable->Unk95(This, arg1);
    This->m_Unk46 = -1;
    This->m_Unk44 = 0;
    This->m_FloorSurfaceType = 0;
    This->m_MoveState = MOVE_NONE;
    This->m_LeftRightState = 0;
    This->m_LookUpDownState = 0;
    This->m_Unk35 = 0;
    This->m_LookVerticalPosition = 0;
    This->m_Unk36 = 0;
    This->vtable->Unk98(This, 0, 1, 1, 1);
    This->vtable->Unk99(This, arg2);
    *(s16 *)((u8 *)&This->m_Unk89 + 2) = -1;
    This->m_Unk27 = 0;
    This->m_Unk16 = 0;
    This->m_Unk28 = 0;
    This->m_Unk577 = 0;
    This->m_Unk578 = 0;
    This->m_Unk579 = 0;
    This->m_Unk29 = 0;
    func_8001E6F8(This, &buf);
    buf.m_A = 0;
    buf.m_B = 1;
    This->vtable->Unk16(This, 1, (s32 *)&buf);
}

void func_80059310(dream_sys_t *This) {
    This->m_Unk27 = 1;
}

s32 func_8005931C(dream_sys_t *This) {
    return This->m_Unk28;
}

s32 dream_sys__get_set_dream_time_limit(dream_sys_t *This, s32 Limit) {
    s32 old_limit;

    if (Limit >= 0) {
        Limit *= 15;
    }

    old_limit = This->m_DreamTimeLimit;
    This->m_DreamTimeLimit = Limit;

    if (old_limit >= 0) {
        old_limit /= 15U;
    }

    return old_limit;
}

s32 func_80059360(dream_sys_t *This) {
    return This->m_GameTick / 15;
}

void func_8005937C(dream_sys_t *This, s32 Value) {
    This->m_Unk21 = Value;
}

void func_80059384(dream_sys_t *This, s32 Value) {
    This->m_Unk22 = Value;
}

void func_8005938C(dream_sys_t *This, s32 Value) {
    This->m_Unk24 = Value;
}

void func_80059394(dream_sys_t *This) {
    if (This->m_Unk27 == 0) {
        This->m_Unk28 = 0;
        This->m_Unk72 = This->m_GameTick % This->m_Unk71 == 0;
    }
}

void func_800593D8(dream_sys_t *This) {
    void (*m_Unk31)(void);
  void (*m_Unk37)(dream_sys_t *);

    m_Unk31 = (void (*)(void))This->m_Unk31;
  if ( m_Unk31 )
    m_Unk31();
    
  m_Unk37 = (void ( *)(dream_sys_t *))This->m_Unk37;
  if ( m_Unk37 )
    m_Unk37(This);
}


INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005942C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005950C);

void func_80059590(dream_sys_t *This) {
    This->m_Unk30 = 0;
}

void func_80059598(dream_sys_t *This) {
    This->m_Unk29 = 0;
}

s32 func_800595A0(dream_sys_t *This) {
    return 0;
}

void func_800595A8(dream_sys_t *This, s32 Unk) {
    This->vtable->Unk78(This, 0);

    if (Unk) {
        This->vtable->Unk77(This, 0);
    }
}

void func_80059610(dream_sys_t *This, s32 Unk2, s32 Unk3) {
    This->vtable->Unk78(This, Unk2);
    This->vtable->Unk77(This, Unk3);
}

void func_8005966C(dream_sys_t *This, s32 Unk) {
    dream_sys_vtable_t *vtable = This->vtable;

    This->m_Unk32 = Unk;

    switch (Unk) {
        case 0:
            This->m_Unk31 = 0;
            break;

        case 1:
            This->m_Unk31 = vtable->Unk79;
            break;

        case 2:
            This->m_Unk31 = vtable->Unk82;
            break;

        case 3:
            This->m_Unk31 = vtable->Unk83;
            break;

        default:
            break;
    }
}

void func_800596E8(dream_sys_t *This, s32 Unk) {
    s32 fnc;
    dream_sys_vtable_t *vtable = This->vtable;

    if (This->m_Unk38 == 2) {
        vtable->Unk94(This, 0);
    }

    This->m_Unk38 = Unk;

    switch (Unk) {
        case 0:
            This->m_Unk37 = 0;
            break;

        case 1:
            This->m_Unk37 = vtable->Unk84;
            break;

        case 2:
            fnc = vtable->Unk93;
            This->m_Unk48 = 1;
            This->m_Unk49 = 1;
            This->m_Unk37 = fnc;
            helper_1_set_entity(This->m_Unk21, &This->m_Unk50, 1, This, This->vtable->Unk100);
            break;

        default:
            break;
    }
}

void func_800597C0(dream_sys_t *This) {
    This->vtable->Unk80(This);
    This->vtable->Unk81(This);
}

void func_80059814(dream_sys_t *This) {
    s32 index;
    s32 delta;
    s32 limit;
    s32 sum;
    s32 *obj;
    s32 pos;

    index = This->m_LookUpDownState;
    if (index != 0) {
        delta = D_80087E50[index];
        limit = D_80087E5C[index];
        sum = This->m_LookVerticalPosition + delta;
        if (sum >= 0) {
            if (sum < limit) {
                goto apply;
            }
        } else if ((~sum + 1) < limit) {
            goto apply;
        }
        goto clear;
    apply:
        obj = (s32 *)This->m_Unk22;
        obj[9] += delta;
        This->m_LookVerticalPosition = sum;
    clear:
        This->m_LookUpDownState = 0;
    } else {
        pos = This->m_LookVerticalPosition;
        if (pos != 0) {
            if (pos < 0) {
                delta = 0x258;
            } else {
                delta = -0x258;
            }
            ((s32 *)This->m_Unk22)[9] = ((s32 *)This->m_Unk22)[9] + delta;
            This->m_LookVerticalPosition += delta;
        }
    }
}


void func_80059A1C(dream_sys_t *This);

void func_800598E8(dream_sys_t *This) {
    s32 index;
    s32 delta;
    s32 limit;
    s32 sum;
    s32 pos;

    This->m_Unk41 = This->m_MoveState == MOVE_FORWARD;
    index = This->m_Unk35;
    if (index != 0) {
        delta = D_80087E68[index];
        limit = D_80087E74[index];
        sum = This->m_Unk36 + delta;
        if (sum >= 0) {
            if (sum < limit) {
                goto apply;
            }
        } else if ((~sum + 1) < limit) {
            goto apply;
        }
        goto clear;
    apply:
        D_80087E84[0] = delta;
        This->vtable->Unk16(This, 0, (s32 *)((u8 *)&D_80087E84[0] - 4));
        This->m_Unk36 = sum;
    clear:
        This->m_Unk35 = 0;
        func_80059A1C(This);
    } else {
        pos = This->m_Unk36;
        if (pos != 0) {
            if (pos < 0) {
                delta = 0x2D;
            } else {
                delta = -0x2D;
            }
            D_80087E84[0] = delta;
            This->vtable->Unk16(This, 0, (s32 *)((u8 *)&D_80087E84[0] - 4));
            This->m_Unk36 += delta;
            func_80059A1C(This);
        }
    }
}

void func_80059A1C(dream_sys_t *This) {
    This->m_Unk41 = 0;

    if (This->m_MoveState) {
        if ((This->m_MoveState & 1) == 0) {
            This->m_MoveState -= 1;
        } else {
            This->m_MoveState += 1;
        }
    }
}

void func_80059A48(void) {
}

void func_80059A50(void) {
}

void func_80059A58(dream_sys_t *This) {
    if (This->m_Unk26 == 0) {
        This->vtable->Unk92(This);
        This->vtable->Unk85(This);
    } else if (This->m_Unk26 == 2) {
        This->vtable->Unk87(This);
    } else {
        This->vtable->Unk86(This);
    }
}

void func_80059AEC(dream_sys_t *This) {
    s32 value;

    if (!This->m_Unk27) {
        value = This->vtable->Unk88(This, 1);
        This->vtable->Unk91(This, value);
    }
}

void func_80059B50(dream_sys_t *This) {
    s32 value;

    This->m_MoveState = MOVE_FORWARD;

    if (!This->m_Unk27) {
        value = This->vtable->Unk88(This, 1);
        This->vtable->Unk91(This, value);
    } else {
        This->vtable->Unk88(This, 0);
    }
}

void func_80059BD4(dream_sys_t *This) {
    This->m_MoveState = MOVE_FORWARD;
}

s32 func_80059BE0(dream_sys_t *This, s32 arg1) {
    s32 flag;
    s32 saved;
    s32 count;
    s32 delta;
    s32 *obj;

    flag = 0;
    saved = 0;
    if (This->m_MoveState != 0) {
        saved = This->m_MoveState;
        count = This->m_Unk44 + 1;
        This->m_Unk44 = count;
        if (count >= 4) {
            goto wrap;
        }
        if (This->m_Unk42 != MOVE_RIGHT) {
            goto step;
        }
        {
            u32 bit;

            bit = count & 1;
            flag = bit < 1;
        }
        goto step;
    wrap:
        This->m_MoveState = MOVE_NONE;
        flag = 1;
    step:
        if (flag != 0) {
            This->vtable->Unk89(This);
        }
        obj = (s32 *)This->m_Unk22;
        if (obj != 0 && This->screen_shake_enabled != 0 && arg1 != 0) {
            delta = -0x32;
            if (This->m_Unk44 >= 3) {
                delta = 0x32;
            }
            obj[6] += delta;
            obj[9] += delta;
        }
        if (This->m_MoveState == MOVE_NONE) {
            This->m_Unk44 = 0;
        }
    }
    if (flag == 0) {
        This->vtable->Unk90(This);
    }
    return saved;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059D1C);

void func_80059E3C(dream_sys_t *This) {
    if (This->m_Unk46 >= 0) {
        (*(void ( **)(s32, s32))(*(s32 *)This->m_Unk21 + 132))(This->m_Unk21, This->m_Unk46);
        This->m_Unk46 = -1;
    }
}

extern s8 D_80087E34[];
extern s32 D_80087E20[];
extern void (*D_80087E3C[])(dream_sys_t *, s32, s32);

typedef struct func_80059E98_link func_80059E98_link_t;

typedef struct func_80059E98_link_vtable {
    /* 0x00 */ u8 pad[0x10C];
    /* 0x10C */ s32 (*Unk66)(func_80059E98_link_t *, s32, s32);
} func_80059E98_link_vtable_t;

typedef struct func_80059E98_link {
    /* 0x00 */ func_80059E98_link_vtable_t *vtable;
} func_80059E98_link_t;

typedef struct func_80059E98_inner {
    /* 0x00 */ s32 cleared;
    /* 0x04 */ u8 pad[0x14];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} func_80059E98_inner_t;

void func_80059E98(dream_sys_t *This, s32 arg) {
    s32 product;
    s32 ret;
    func_80059E98_link_t *link;
    func_80059E98_inner_t *inner;

    if (arg == 0) {
        return;
    }
    product = D_80087E34[arg] * D_80087E20[This->m_Unk42];
    This->vtable->Unk74(This);
    link = (func_80059E98_link_t *)This->m_Unk18;
    ret = link->vtable->Unk66(link, 0, 0);
    if (This->vtable->Unk118(This, ret) == 0 && This->vtable->Unk117(This, ret) == 0 && This->vtable->Unk115(This, ret) == 0) {
        This->vtable->Unk135(This);
        D_80087E3C[arg](This, product, This->m_Unk578 == 0);
        if (This->m_NextMap == 0) {
            inner = (func_80059E98_inner_t *)This->m_Unk4;
            if (inner->field_1C < -0x7D0 && inner->field_18 >= -0x1F3) {
                This->vtable->dream_sys__wall_link(This, This, 4);
            }
        }
    }
    *(s32 *)This->m_Unk4 = 0;
}

void func_8005A050(dream_sys_t *This) {
    s32 state;

    state = This->m_LeftRightState;
    if (state != 0) {
        This->vtable->Unk16(This, 0, (s32 *)((state * 0xC) + (s32)D_80087E80));
        This->m_LeftRightState = 0;
    }
}

void func_8005A0B0(dream_sys_t *This) {
    s32 *temp_v1;

    if (This->m_Unk48 != 0) {
        This->vtable->Unk46(This, D_80087EA4);
        temp_v1 = (s32 *)This->m_Unk22;
        temp_v1[9] = temp_v1[9] - 0x258;
    }
    if (This->m_Unk49 != 0) {
        helper_1_update_entity(This->m_Unk21, (u8 *)This + 0xCC);
    }
}

void func_8005A134(dream_sys_t *This, s32 Unk) {
    This->m_Unk48 = 0;
    This->m_Unk49 = Unk;

    if (Unk) {
        func_8002CC84(This->m_Unk21, &This->m_Unk50);
    }
}

s32 func_8005A168(dream_sys_t *This, s32 Value) {
    s32 old_value = This->m_Unk42;

    if (Value >= 0) {
        This->m_Unk42 = Value;
        This->m_Unk43 = Value;
    }

    return old_value;
}

s32 func_8005A184(dream_sys_t *This, s32 Value) {
    s32 next_value;

    next_value = This->m_Unk42;
    if (next_value != Value) {
        This->m_Unk43 = next_value;
        This->m_Unk42 = Value;
    }
    return next_value;
}

void func_8005A1A4(dream_sys_t *This) {
    This->m_Unk42 = This->m_Unk43;
}

void func_8005A1B0(dream_sys_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (Unk2 >= 0) {
        This->m_Unk72 = Unk2;
    }
    if (Unk3 >= 0) {
        This->m_Unk73 = Unk3;
    }
    if (Unk4 >= 0) {
        This->m_Unk74 = Unk4;
    }
    if (Unk5 >= 0) {
        This->m_Unk75 = Unk5;
    }
}

void func_8005A1EC(dream_sys_t *This, s32 Value) {
    This->m_Unk71 = Value;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A1F4);
// void func_8005A1F4(void *This, s32 *arg1) {
//     s32 v1;
//     s32 a0;
//
//     v1 = arg1[0];
//     if (v1 != 1) {
//         return;
//     }
//     a0 = arg1[1];
//     if (a0 == ((a0 / 20) * 20)) {
//         arg1[7] = 9;
//         arg1[8] = -1;
//         return;
//     }
//     arg1[12] = 9;
//     arg1[13] = -1;
// }

void dream_sys__init_new_game(dream_sys_t *This) {
    s32 temp_v1;

    temp_v1 = D_8008ABE0;
    This->m_Unk94 = 0;
    This->m_Unk95 = 0;
    This->m_Unk96 = 0;
    This->m_Unk97 = 0;
    This->m_Unk98 = 0;
    This->m_Unk282 = 0;
    *((u8 *)This + 0x5DF) = 0;
    *((u8 *)This + 0x5D8) = 0;
    This->screen_shake_enabled = 1;
    This->m_Unk414 = 0;
    This->m_Unk415 = 0;
    This->m_Unk93 = temp_v1;
    init_nav_challenges_array(&This->m_Unk375, &This->m_Unk383);
    memset(&This->m_Unk416, 0, 0x1F4);
}

void dream_sys__get_set_screen_shake(dream_sys_t *This, s32 *Value) {
    s32 old_value = This->screen_shake_enabled;
    This->screen_shake_enabled = *Value;
    *Value = old_value;
}

s32 get_day_number(dream_sys_t *This, s32 *Out) {
    if (Out) {
        *Out = This->m_Unk94;
    }
    return This->m_Unk95 + 1;
}

s32 dream_sys__advance_day(dream_sys_t *This) {
    s32 next_day = This->m_Unk95 + 1;
    This->m_Unk95 = next_day;

    if (next_day > 364) {
        This->m_Unk95 = 0;
        This->m_Unk94++;
    }

    return This->m_Unk95;
}

void func_8005A33C(dream_sys_t *This) {
    This->m_Unk541 = 0;
}

s32 func_8005A344(dream_sys_t *This) {
    return This->m_Unk541;
}

s32 *func_8005A350(dream_sys_t *This, s32 *Size) {
    if (Size) {
        *Size = 0x700;
    }

    return &This->m_Unk93;
}

s32 is_day_special(s16 *out, s32 day);


s32 dream_sys__start_day(dream_sys_t *This) {
    s32 special;

    This->m_Unk542 = 0;
    This->m_GameTick = 0;
    This->m_Unk546 = This->m_Unk95;
    if (This->m_Unk25 != 0) {
        ((void (*)(void *, s32))This->vtable->dream_sys__load_next_flashback)(This, 1);
    } else {
        special = is_day_special((u8 *)This + 0x168, This->m_Unk95 + 1);
        ((void (*)(void *, s32))This->vtable->dream_sys__init_mood_contibutors)(This, special);
        if (special != 0) {
            return -1;
        }
        This->vtable->dream_sys__init_spawn_loc(This);
    }
    return This->m_NextMap;
}

s32 dream_sys__end_day(dream_sys_t *This, s32 arg1) {
    s32 off;

    This->m_Unk95 = This->m_Unk546;
    if (This->m_Unk25 == 0) {
        if (arg1 == 0) {
            This->vtable->dream_sys__calc_unlock_score(This);
            off = This->m_Unk95 * 2;
            off += 0x190;
            ((void (*)(void *, void *))This->vtable->dream_sys__update_dream_chart)(This, (u8 *)This + off);
            This->vtable->dream_sys__advance_day(This);
            goto done;
        }
    }
    if (arg1 == 2) {
        This->vtable->dream_sys__init_new_game(This);
        This->m_Unk541 = 1;
    }
done:
    return This->m_Unk25;
}

dream_sys_t *dream_sys__get_cinematic(dream_sys_t *This, void *Unk) {
    return (dream_sys_t *)__builtin_memcpy((char *)This, (char *)Unk + 0x168, 4);
}

s32 generate_initial_spawn(void *arg0, s32 *arg1, void *arg2, s32 arg3);

void dream_sys__init_spawn_loc(dream_sys_t *This) {
    s32 sp14;
    dream_sys_mood_graph_point_t sp10;

    This->vtable->dream_sys__get_previous_day_mood(This, &sp10, 1);
    This->m_NextMap =
        generate_initial_spawn(&This->m_Unk90, &sp14, &sp10, This->m_Unk95);
    sp14 = This->vtable->dream_sys__get_set_dream_time_limit(This, sp14);
    This->m_Unk16 = 0xB;
}

void dream_sys__dynamic_link(dream_sys_t *This) {
    s32 RandomSpawnFromStage;;
    
    if ( !This->m_Unk16 )
  {
    RandomSpawnFromStage = get_random_spawn_from_stage(&This->m_Unk90, This->m_NextMap, This->m_GameTick);
    execute_link(This, RandomSpawnFromStage, 12, 1);
  }
}

s32 dream_sys__static_wall_link(dream_sys_t *This, s32 arg1) {
    s32 temp_v0;

    if (This->m_Unk16 != 0) {
        return 0;
    }
    temp_v0 = test_for_static_link(&This->m_Unk90, arg1, This->m_NextMap);
    if (temp_v0 < 0) {
        return 0;
    }
    execute_link(This, temp_v0, 0xD, 1);
    return 1;
}

s32 dream_sys__load_next_flashback(dream_sys_t *This, s32 arg1) {
    s32 idx;
    s32 off;
    u8 *slot;

    idx = *(s32 *)((u8 *)This + 0x87C);
    if (idx < This->m_Unk282) {
        *(s32 *)((u8 *)This + 0x44) = 0xE;
        off = idx * 0x24 + 0x470;
        slot = (u8 *)This + off;
        if (arg1 == 0) {
            ((void (*)(void *, s32))This->vtable->Unk11)(This, 0xE);
        }
        This->m_Unk95 = *(s32 *)(slot + 0x20);
        This->m_NextMap = *(s32 *)slot;
        *(dream_sys_fb_pkt10_t *)((u8 *)This + 0x16C) = *(dream_sys_fb_pkt10_t *)(slot + 4);
        return 1;
    }
    return 0;
}

s32 func_8005A700(dream_sys_t *This, s32 arg1) {
    s32 idx;
    s32 buf[4];

    if (This->m_Unk16 != 0) {
        return 0;
    }
    idx = test_4_tunnel_links(&This->m_Unk90, arg1, This->m_NextMap);
    if (idx < 0) {
        return 0;
    }
    func_8001E6F8(This, buf);
    if (func_8005BD3C(&This->m_Unk545, &This->m_Unk544, buf) == 0) {
        return 0;
    }
    if (This->m_Unk41 == 0) {
        return 0;
    }
    execute_link(This, idx, 0xF, 0);
    return 1;
}

s32 func_8005A7A0(dream_sys_t *This, s32 arg1) {
    s32 idx;

    if (This->m_Unk16 != 0) {
        return 0;
    }
    idx = func_8005BE90(&This->m_Unk90, This->m_NextMap, arg1, This->m_GameTick);
    if (idx < 0) {
        return 0;
    }
    This->m_Unk543 = (s32)func_8005BF48();
    This->m_Unk544 = 0;
    This->m_Unk545 = 0;
    execute_link(This, idx, 0x10, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A82C);

s32 execute_link(dream_sys_t *This, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_a0;

    This->m_Unk16 = arg2;
    This->vtable->Unk11(This, arg2);
    if (This->m_Unk16 == 0) {
        return 0;
    }
    This->m_NextMap = arg1;
    if (This->m_Unk25 != 0) {
        This->m_GameTick = 0;
    }
    if (arg3 != 0) {
        temp_a0 = (void *)This->m_Unk21;
        (*(void (**)(void *, s32, s32, s32))(*(s32 *)temp_a0 + 0x80))(
            temp_a0, 0x90, 0x6E, 0x6E);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A9CC);

s32 func_8005AB2C(dream_sys_t *This) {
    s32 v;

    if (This->m_Unk580 == 0) {
        func_8005AF64(This, D_8008ABC0, (s16 *)&This->m_Unk582);
    }
    if (This->m_Unk42 != 4) {
        v = This->m_Unk580;
        if (v >= 0x85) {
            return 1;
        }
        if (((u32)(v - 0x2B) < 0xF) || ((u32)(v - 0x4B) < 0xF)) {
            This->m_LeftRightState = 2;
        }
    } else {
        v = This->m_Unk580;
        if (v >= 0x13) {
            return 1;
        }
        if (((u32)(v - 8) < 2) || ((u32)(v - 0xD) < 2)) {
            This->vtable->Unk16(This, 0, D_80087EFC);
        }
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_Unk580 += 1;
    return 0;
}

s32 func_8005AC24(dream_sys_t *This) {
    s32 v;
    s32 turn;

    if (This->m_Unk580 == 0) {
        func_8005AF64(This, D_8008ABC8, (s16 *)&This->m_Unk582);
    }
    if (This->m_Unk42 != 4) {
        v = This->m_Unk580;
        if (v >= 0x95) {
            return 1;
        }
        if (((u32)(v - 0x16) < 0xF) || ((u32)(v - 0x39) < 0x10) || ((u32)(v - 0x6E) < 0xF)) {
            This->m_LeftRightState = 1;
        }
        turn = (u32)(This->m_Unk580 - 0x39) < 0x35;
    } else {
        v = This->m_Unk580;
        if (v >= 0x19) {
            return 1;
        }
        if (((u32)(v - 6) < 2) || ((u32)(v - 0xB) < 2) || ((u32)(v - 0x14) < 2)) {
            This->vtable->Unk16(This, 0, D_80087F08);
        }
        turn = (u32)(This->m_Unk580 - 3) < 0xE;
    }
    if (turn != 0) {
        This->m_LookUpDownState = 2;
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_Unk580 += 1;
    return 0;
}

s32 func_8005AD68(dream_sys_t *This) {
    s32 v;

    if (This->m_Unk580 == 0) {
        func_8005AF64(This, D_8008ABD0, (s16 *)&This->m_Unk582);
    }
    if (This->m_Unk42 != 4) {
        v = This->m_Unk580;
        if (v >= 0x65) {
            return 1;
        }
        if ((u32)(v - 0x2B) < 0xF) {
            This->m_LeftRightState = 2;
        }
    } else {
        v = This->m_Unk580;
        if (v >= 0xF) {
            return 1;
        }
        if ((u32)(v - 8) < 2) {
            This->vtable->Unk16(This, 0, D_80087EFC);
        }
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_Unk580 += 1;
    return 0;
}

s32 func_8005AE40(dream_sys_t *This) {
    s32 v;
    s32 turn;

    if (This->m_Unk580 == 0) {
        func_8005AF64(This, D_8008ABD8, (s16 *)&This->m_Unk582);
    }
    if (This->m_Unk42 != 4) {
        v = This->m_Unk580;
        if (v >= 0x71) {
            return 1;
        }
        if (((u32)(v - 0x1E) < 0xF) || ((u32)(v - 0x52) < 0xF)) {
            This->m_LeftRightState = 1;
        }
        turn = (u32)(This->m_Unk580 - 0x1E) < 0x34;
    } else {
        v = This->m_Unk580;
        if (v >= 0x13) {
            return 1;
        }
        if (((u32)(v - 6) < 2) || ((u32)(v - 0xF) < 2)) {
            This->vtable->Unk16(This, 0, D_80087F08);
        }
        turn = (u32)This->m_Unk580 < 9;
    }
    if (turn != 0) {
        This->m_LookUpDownState = 2;
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_Unk580 += 1;
    return 0;
}

s32 func_8005AF64(dream_sys_t *This, s16 *a, s16 *b) {
    s32 vec[3];
    s32 t0;
    s32 t1;

    vec[0] = a[0] - b[0];
    vec[1] = a[1] - b[1];
    t0 = a[2];
    t1 = b[2];
    vec[1] = 0;
    vec[2] = t0 - t1;
    return ((s32(*)(dream_sys_t *, s32 *))This->vtable->Unk46)(This, vec);
}

s32 func_8005AFD0(dream_sys_t *This) {
    return This->m_NextMap;
}

void dream_sys__process_chunk_change(dream_sys_t *This, void *arg1, s32 arg2) {
    if (arg2 == 5) {
        This->vtable->dream_sys__log_chunk_mood(
            This,
            (void *)((s32 (*)(void *, s32, s32))(*(void **)(*(s32 *)arg1 + 0x10C)))(arg1, 0, 0));
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__instance_effects_on_journal);

void dream_sys__get_previous_day_mood(dream_sys_t *This, s8 *out, s32 mode) {
    s32 t0;
    s32 t1;
    s32 count;
    s8 *p;
    s32 i;
    s32 a;
    s32 b;

    t0 = 0;
    t1 = 0;
    if (mode != 0) {
        if (This->m_Unk94 != 0) {
            goto last_day;
        }
        if (This->m_Unk95 == 0) {
            goto store_both;
        }
    last_day:
        {
            void *row;
            row = (u8 *)This + ((This->m_Unk95 - 1) << 1);
            t1 = ((s8 *)row)[0x190];
            t0 = ((s8 *)row)[0x191];
            out[0] = t1;
            out[1] = t0;
            return;
        }
    }
    count = 0x16D;
    if (This->m_Unk94 == 0) {
        count = This->m_Unk95;
    }
    if (count != 0) {
        p = (s8 *)This + 0x190;
        i = 0;
        if (t0 < count) {
            do {
                i += 1;
                a = p[0];
                b = p[1];
                p += 2;
                t1 += a;
                t0 += b;
            } while (i < count);
        }
        t1 /= count;
        t0 /= count;
    }
store_both:
    out[0] = t1;
    out[1] = t0;
}

void dream_sys__init_mood_contibutors(dream_sys_t *This, s32 arg1) {
    void *p144;
    void *p154;

    p144 = (u8 *)This + 0x144;
    This->vtable->dream_sys__clear_mood_graph(This, p144);
    p154 = (u8 *)This + 0x154;
    This->vtable->dream_sys__clear_mood_graph(This, p154);
    if (arg1 != 0) {
        ((void (*)(void *, void *, s32))This->vtable->dream_sys__log_mood)(This, p144, arg1);
        ((void (*)(void *, void *, s32))This->vtable->dream_sys__log_mood)(This, p154, arg1);
    }
}

void dream_sys__log_chunk_mood(dream_sys_t *This, void *CurrentPosition) {
    dream_sys_mood_graph_point_t *point = get_mood_from_stage_chunk(This->m_NextMap, CurrentPosition);
    This->vtable->dream_sys__log_mood(This, &This->m_Unk80, point);
}

void dream_sys__log_instance_mood(dream_sys_t *This, dream_sys_mood_graph_point_t *Source) {
    This->vtable->dream_sys__log_mood(This, &This->m_Unk84, Source);
}

void dream_sys__update_dream_chart(dream_sys_t *This, dream_sys_mood_graph_point_t *out) {
    dream_sys_mood_graph_point_t sp10;
    dream_sys_mood_graph_point_t sp12;

    This->vtable->dream_sys__get_mood_average(This, (dream_sys_mood_graph_contrib_t *)&This->m_Unk80, &sp10);
    This->vtable->dream_sys__get_mood_average(This, (dream_sys_mood_graph_contrib_t *)&This->m_Unk84, &sp12);
    if (This->m_Unk87 == 0) {
        sp12.value = sp10.value;
    }
    out->axis.dynamic = (s8)((sp10.axis.dynamic + sp12.axis.dynamic) / 2);
    out->axis.upper = (s8)((sp10.axis.upper + sp12.axis.upper) / 2);
}

s32 dream_sys__get_dream_color(dream_sys_t *This) {
    dream_sys_mood_graph_point_t current_mood;

    This->vtable->dream_sys__update_dream_chart(This, &current_mood);
    return calc_dream_color(&current_mood);
}

s32 calc_dream_color(u16 *arg0) {
    s8 *p;
    s32 i;
    u16 local;
    s8 v;
    s8 *table;
    s32 idx;

    p = (s8 *)&local;
    i = 0;
    local = *arg0;
    do {
        v = *p;
        if (v >= 4) {
            *p = 2;
        } else if (v < -3) {
            *p = 0;
        } else {
            *p = 1;
        }
        i += 1;
        p += 1;
    } while (i < 2);
    v = ((s8 *)&local)[0];
    table = D_80087E14;
    idx = v * 3;
    v = ((s8 *)&local)[1];
    return *(table + idx + v);
}

void dream_sys__clear_mood_graph(dream_sys_t *This, dream_sys_mood_graph_contrib_t *Contrib) {
    Contrib->last_mood.value = 0;
    Contrib->upper_mood = 0;
    Contrib->dynamic_mood = 0;
    Contrib->amount_mood = 0;
}

void dream_sys__log_mood(dream_sys_t *This, dream_sys_mood_graph_contrib_t *Contrib, dream_sys_mood_graph_point_t *Point) {
    Contrib->last_mood.value = Point->value;
    Contrib->dynamic_mood += Point->axis.dynamic;
    Contrib->upper_mood += Point->axis.upper;
    Contrib->amount_mood += 1;
}

void dream_sys__get_mood_average(dream_sys_t *This, dream_sys_mood_graph_contrib_t *arg1,
                                 dream_sys_mood_graph_point_t *arg2) {
    s32 temp_a2;

    temp_a2 = arg1->amount_mood;
    if (temp_a2 != 0) {
        arg2->axis.dynamic =
            calc_mood_axis(arg1->last_mood.axis.dynamic, arg1->dynamic_mood, temp_a2);
        arg2->axis.upper =
            calc_mood_axis(arg1->last_mood.axis.upper, arg1->upper_mood, arg1->amount_mood);
        return;
    }
    arg2->value = arg1->last_mood.value;
}

s32 calc_mood_axis(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_a1;

    var_a1 = (arg1 / arg2) + (arg0 / 3);
    if (var_a1 >= 0xA) {
        var_a1 = -9;
    } else if (var_a1 < -9) {
        var_a1 = 9;
    }
    return var_a1;
}

void dream_sys__calc_unlock_score(dream_sys_t *This) {
    s32 temp_a0;

    This->m_Unk97 = calc_navigation_score();
    temp_a0 = This->m_Unk98;
    if (temp_a0 < 0) {
        This->m_Unk98 = 0;
    } else if (temp_a0 > 0x02FAF080) {
        This->m_Unk98 = 0x02FAF080;
    }
    This->m_Unk96 = This->m_Unk97 + This->m_Unk98;
}

void dream_sys__add_flashback(dream_sys_t *This, s32 arg1, void *arg2, void *arg3, s32 arg4,
                              s32 arg5, s32 arg6) {
    s32 count;
    s32 idx;
    u8 *slot;

    count = *(s32 *)((u8 *)This + 0x46C);
    slot = (u8 *)This + 0x470;
    if (count < 0xA) {
        *(s32 *)((u8 *)This + 0x46C) = count + 1;
        idx = count * 9;
    } else {
        idx = ((u32)*(s32 *)((u8 *)This + 0x24) % 9) * 9;
    }
    slot += idx * 4;
    *(s32 *)slot = arg1;
    *(dream_sys_fb_pkt10_t *)(slot + 4) = *(dream_sys_fb_pkt10_t *)arg2;
    *(dream_sys_fb_pkt12_t *)(slot + 0xE) = *(dream_sys_fb_pkt12_t *)arg3;
    *(s16 *)(slot + 0x1C) = arg4;
    *(s16 *)(slot + 0x1A) = arg5;
    *(s32 *)(slot + 0x20) = arg6;
}

void dream_sys__flashback_saving(dream_sys_t *This, s32 arg1, s32 arg2) {
    s32 r;
    s32 temp;
    void **obj;
    s32 sp20[4];

    if (This->m_Unk18 != 0) {
        r = rand();
        if (r % 3 == 0) {
            obj = (void **)This->m_Unk18;
            temp = (*(s32 (**)(void **, s32, s32))(*(u32 *)obj + 0x10C))(obj, 0, 0);
            func_8001E6F8(This, sp20);
            ((void (*)(void *, s32, s32, void *, s32, s32, s32))This->vtable->dream_sys__add_flashback)(
                This, This->m_NextMap, temp, sp20, arg1, arg2, This->m_Unk95);
        }
    }
}

void dream_sys__reset_flashback_list(dream_sys_t *This) {
    This->m_Unk282 = 0;
}

typedef struct dream_link {
    s32 head[17];
    void *tail;
} dream_link_t;

typedef struct {
    s32 w[20];
} dream_blk50_t;

typedef struct {
    s32 w[10];
} dream_blk28_t;

void func_8005B904(dream_sys_t *This) {
    dream_link_t *link;

    link = (dream_link_t *)This->m_Unk4;
    *(dream_blk50_t *)&This->m_Unk547 = *(dream_blk50_t *)link;
    *(dream_blk28_t *)&This->m_Unk567 = *(dream_blk28_t *)link->tail;
}

void func_8005B990(dream_sys_t *This) {
    dream_link_t *link;

    link = (dream_link_t *)This->m_Unk4;
    *(dream_blk50_t *)link = *(dream_blk50_t *)&This->m_Unk547;
    *(dream_blk28_t *)link->tail = *(dream_blk28_t *)&This->m_Unk567;
    link->head[0] = 0;
}

s32 func_8005BA20(dream_sys_t *This, s32 Value) {
    s32 out;

    if (Value >= 0) {
        out = This->m_Unk584;
        This->m_Unk584 = Value;
    } else {
        out = This->m_Unk584;
    }

    return out;
}


dream_sys_vtable_t *dream_sys_get_vtable(void) {
    return &g_DREAM_SYS_VTABLE;
}

void init_nav_challenges_array(s32 *Unk1, s32 *Unk2) {
    s32 var_v1;
    s8* var_v0;

    var_v1 = 0x1D;
    var_v0 = (char *) Unk1 + 0x1D;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    gpNavChallengesComplete = Unk1;
    *Unk2 = 0;
    gpDinamicLinkPenalty = Unk2;
}

s32 calc_navigation_score(void) {
    s32 score;
    s32 addend;
    s8 *var_v1;
    s8 *temp_a1;

    score = 0;
    addend = 0xF4240;
    var_v1 = (s8 *)gpNavChallengesComplete;
    temp_a1 = var_v1 + 0x1E;
    do {
        if (*var_v1 != 0) {
            score += addend;
        }
        var_v1 += 1;
    } while ((s32)var_v1 < (s32)temp_a1);
    if (score > 0x01C9C37F) {
        score = 0x02FAF080;
    }
    score -= *(s32 *)gpDinamicLinkPenalty * 0x2B10;
    if (score < 0) {
        score = 0;
    }
    return score;
}

s32 func_8005BB14(s32 Unk) {
    return STAGE_TIME_LIMITS[Unk];
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", get_random_spawn_from_stage);

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2) {
    return get_static_spawn(Unk0, Unk1, Unk2, LEN_STAGE_PERMALINK_TRIGGERS, &STAGE_PERMALINK_TRIGGERS, &STAGE_PERMALINK_SPAWNS, 1);
}

s32 test_4_tunnel_links(void *Unk0, s32 Unk1, s32 Unk2) {
    return get_static_spawn(Unk0, Unk1, Unk2, D_800889F0, &D_80088980, &D_80088820, 1);
}

s32 func_8005BD3C(void **arg0, void **arg1, s16 *arg2) {
    u8 temp_s0;

    temp_s0 = D_800889B8[D_8008ACBC][D_8008ACC0];
    if (func_8005BE28(arg2, temp_s0) != 0) {
        if (arg1 != NULL) {
            *arg1 = (void *)(D_80088758 + temp_s0 * 0xC);
        }
        if (arg0 != NULL) {
            *arg0 = (void *)(D_80088758 + D_80088858[D_8008ACC4][D_8008ACC8] * 0xC);
        }
        return 1;
    }
    return 0;
}

s32 func_8005BE28(s16 *arg0, s32 arg1) {
    s16 diff;
    s16 wrapped;
    u16 *table;

    table = (u16 *)((u8 *)D_8008875C + ((arg1 & 0xFF) * 0xC));
    diff = arg0[2] - table[0];
    wrapped = diff;
    if (diff >= 0xB5) {
        wrapped = diff - 0x168;
    } else if (diff < -0xB4) {
        wrapped = diff + 0x168;
    }
    return ((u16)(wrapped + 0x2C)) < 0x59U;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BE90);

s32 *func_8005BF48(void) {
    s32 *out = NULL;
    
    if (D_8008ACC4 != 0xC) {
        out = &D_8008ABF0;
    }
    
    return out;
}

void func_8005BF68(s32 Unk) {
    D_8008ABE4 = Unk;
}

s32 test_4_instant_teleporters(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (D_8008ABE4) {
        return get_static_spawn(Unk1, Unk2, Unk3, &D_80088B5C, &D_80088B24, &D_80088A80, 0);
    }
    
    return -1;
}

s32 func_8005BFC4(void) {
    return D_8008ACBC == 0 ? 0xA : 0;
}

s32 test_4_staircase_nodes(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (!Unk3) {
        return get_static_spawn(Unk1, Unk2, 0, D_80088CBC, &D_80088C4C, &D_80088BA4, 0);
    }

    return -1;
}

s32 func_8005C02C(void **arg0, void **arg1, s16 *arg2) {
    u8 temp_s0;

    temp_s0 = D_80088C84[D_8008ACBC][D_8008ACC0];
    if (func_8005BE28(arg2, temp_s0) != 0) {
        if (arg1 != NULL) {
            *arg1 = (void *)(D_80088758 + temp_s0 * 0xC);
        }
        if (arg0 != NULL) {
            *arg0 = (void *)(D_80088758 + D_80088BDC[D_8008ACC4][D_8008ACC8] * 0xC);
        }
        return 1;
    }
    return 0;
}

s8 func_8005C118(void) {
    return ((s8 *)D_80088BA4[D_8008ACC4])[D_8008ACC8 * 6 + 5];
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", get_static_spawn);

s32 generate_initial_spawn(void *dst, s32 *time_out, void *mood, s32 tick) {
    struct {
        s16 coords;
        char pad[14];
    } loc;
    s32 chunk;
    s32 count;
    s16 *ptr;
    s32 i;
    s16 key;
    s32 ret;
    u8 idx;

    chunk = get_stage_chunk_from_mood((s8 *)&loc.coords, mood);
    if (chunk >= 0) {
        *time_out = STAGE_TIME_LIMITS[chunk];
        count = LEN_STAGE_SPAWNPOINTS[chunk];
        ptr = STAGE_SPAWNPOINTS[chunk];
        i = 0;
        if (count != 0) {
            key = loc.coords;
            do {
                i += 1;
                if (key == *ptr) {
                    goto found;
                }
                ptr += 3;
            } while (i < count);
        }
        ptr = (s16 *)((u8 *)STAGE_SPAWNPOINTS[chunk] + (loc.coords % count) * 6);
    found:
        *(dream_sys_pkt4_t *)dst = *(dream_sys_pkt4_t *)ptr;
        idx = ((u8 *)ptr)[4];
        ret = chunk;
        *(dream_sys_pkt6_t *)((u8 *)dst + 4) =
            *(dream_sys_pkt6_t *)((u8 *)SPAWN_POS_ADJUST + idx * 6);
        return ret;
    }
    chunk = get_random_spawn_from_stage(dst, chunk, tick);
    *time_out = STAGE_TIME_LIMITS[chunk];
    return chunk;
}

extern s16 SPECIAL_DAYS[];
extern s32 D_8008ABF4[4]; /* size > G8 so & uses lui */

s32 is_day_special(s16 *out, s32 day) {
    s32 magic;
    s32 i;
    s32 r;

    magic = 0x2AAAAAAB;
    i = 0;
    do {
        if (day != SPECIAL_DAYS[i]) {
            i += 1;
        } else {
            r = rand();
            out[1] = r % 6;
            out[0] = i % 12;
            return (s32)D_8008ABF4;
        }
    } while ((u32)i < 0x2AU);
    return 0;
}

