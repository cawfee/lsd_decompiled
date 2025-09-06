#include "dream_sys.h"
#include "477E4.h"
#include "base_class.h"

extern dream_sys_vtable_t **g_DREAM_SYS_VTABLE;

dream_sys_t *dream_sys_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    dream_sys_t *allocated = (dream_sys_t *) memory_allocate_mem(0x928);

    if (allocated) {
        dream_sys_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys_construct);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys_unk15);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys_unk18);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058A94);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058B08);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058C58);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__TimerTick);

void func_80058E8C(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk38(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFF) == 0x114) {
        This->vtable->Unk120(This, Unk2, Unk3);
    }
}

void func_80058F18(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk54(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFFFF) == 0x1F234) {
        This->vtable->Unk121(This, Unk2, Unk3);
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__WallLink);

void func_800590E0(void) {
}

s32 func_800590E8(dream_sys_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    value = This->m_Unk25;
    if (Unk3 < 0) {
        *Unk2 = (void *) CalcDreamColor((char *) &This->m_Unk99 + 2 * This->m_Unk95);
    } else {
        This->m_Unk25 = Unk3;
    }

    return value;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059148);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800591B4);

void func_80059310(dream_sys_t *This) {
    This->m_Unk27 = 1;
}

s32 func_8005931C(dream_sys_t *This) {
    return This->m_Unk28;
}

s32 DreamSys__GetSetDreamTimeLimit(dream_sys_t *This, s32 Limit) {
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

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800593D8);

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

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059814);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800598E8);

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

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059BE0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059D1C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059E3C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059E98);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A050);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A0B0);

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

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__InitNewGame);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetSetScreenShake);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A2E4);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__AdvanceDay);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A33C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A344);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A350);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__StartDay);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__EndDay);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetCinematic);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__InitSpawnLoc);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__DynamicLink);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__StaticWallLink);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__LoadNextFlashback);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A700);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A7A0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A82C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", ExecuteLink);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A9CC);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AB2C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AC24);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AD68);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AE40);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AF64);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AFD0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__ProcessChunkChange);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__InstanceEffectsOnJournal);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetPreviousDayMood);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__InitMoodContibutors);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__LogChunkMood);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__LogInstanceMood);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__UpdateDreamChart);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetDreamColor);

INCLUDE_ASM("asm/nonmatchings/dream_sys", CalcDreamColor);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__ClearMoodGraph);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__LogMood);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetMoodAverage);

INCLUDE_ASM("asm/nonmatchings/dream_sys", CalcMoodAxis);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__CalcUnlockScore);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__AddFlashback);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__FlashbackSaving);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__ResetFlashbackList);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005B904);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005B990);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BA20);

dream_sys_vtable_t *dream_sys_get_vtable(void) {
    return &g_DREAM_SYS_VTABLE;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", InitNavChallengesArray);

INCLUDE_ASM("asm/nonmatchings/dream_sys", CalcNavigationScore);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BB14);

INCLUDE_ASM("asm/nonmatchings/dream_sys", GetRandomSpawnFromStage);

INCLUDE_ASM("asm/nonmatchings/dream_sys", TestForStaticLink);

INCLUDE_ASM("asm/nonmatchings/dream_sys", Test4TunnelLinks);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BD3C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BE28);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BE90);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BF48);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BF68);

INCLUDE_ASM("asm/nonmatchings/dream_sys", Test4InstantTeleporters);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BFC4);

INCLUDE_ASM("asm/nonmatchings/dream_sys", Test4StaircaseNodes);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005C02C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005C118);

INCLUDE_ASM("asm/nonmatchings/dream_sys", GetStaticSpawn);

INCLUDE_ASM("asm/nonmatchings/dream_sys", GenerateInitialSpawn);

INCLUDE_ASM("asm/nonmatchings/dream_sys", IsDaySpecial);
