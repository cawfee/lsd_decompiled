#include "dream_sys.h"

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

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__func_588ec);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__func_58968);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058A94);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058B08);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058C58);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__TimerTick);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058E8C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058F18);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__WallLink);

void func_800590E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800590E8);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059148);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800591B4);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059310);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005931C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", DreamSys__GetSetDreamTimeLimit);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059360);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005937C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059384);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005938C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059394);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800593D8);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005942C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005950C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059590);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059598);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800595A0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800595A8);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059610);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005966C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800596E8);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800597C0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059814);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800598E8);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059A1C);

void func_80059A48(void) {
}

void func_80059A50(void) {
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059A58);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059AEC);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059B50);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059BD4);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059BE0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059D1C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059E3C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059E98);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A050);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A0B0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A134);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A168);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A184);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A1A4);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A1B0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A1EC);

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
