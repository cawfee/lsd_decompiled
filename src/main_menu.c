#include "main_menu.h"
#include "2C694.h"

extern main_menu_vtable_t **g_MAIN_MENU_VTABLE;

static const char *g_MENU_BUTTON_STATES[3] = { "Off", "On", NULL };

static void *D_80086CA8[7] = { NULL, NULL, (void *) 0x8080, NULL, (void *) 0x35, (void *) 0x39, &g_MENU_BUTTON_STATES };

static void *D_80086CC4[6] = { NULL, NULL, NULL, NULL, NULL, &D_80086CA8 };

static u32 D_80086CE0[7] = { 0, 1, 0, 0, 0, 0, 0 };

static const char *g_MENU_ITEMS[7] = { "START", "FLASHBACK", "SAVE", "LOAD", "GRAPH", "SHAKE", NULL };

static u32 D_8008A9B4 = 0xFFFFFFFC;
static u32 D_8008A9B8 = 0xFFFFFFE9;
static u32 D_8008A9BC = 0xFFFFFFC2;
static u32 D_8008A9C0 = 0xFFFFFFB0;
static u32 D_8008A9C4 = 0xFFFFFFEA;
static u32 D_8008A9C8 = 0xFFFFFFB0;
static u32 D_8008A9CC = 0xFFFF;

static u32 D_80086D14[6][2] = { { 8, 0xFFFFFFFD }, { 8, 9 }, { 8, 21 }, { 8, 33 }, { 8, 45 }, { 8, 57 } };

static char *g_FONT_ICON_PATH SECTION(".data") = "ETC\\FONTICON.TIM";

static const void *D_80086D54[9] = { (void *) 0,  (void *) 0,    (void *) 0,  (void *) 0x80505050, (void *) 0x80,
                                     &D_80086CE0, &g_MENU_ITEMS, &D_80086D14, &D_80086CC4 };

static char *D_80011454 = "BISLPS-01556";

static char *D_80086D6C[16] = { "-01", "-02", "-03", "-04", "-05", "-06", "-07", "-08",
                                "-09", "-10", "-11", "-12", "-13", "-14", "-15", NULL };

static u32 D_80086DAC[6] = { 0, 0x140, 0xF0, 0xF00000, 0x140, 0xF0 };

static char *D_8008AA10 = "BISLPS-01556xxx";

// SHIFT-JIS
static char *g_SPACES = "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81"
                        "\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x00";
static char *g_DAY_STR = "\x82\x6b\x82\x72\x82\x63\x81\x40\x81\x40\x81\x40\x82\x63\x82\x81\x82\x99\x82\x4f\x82\x4f\x82"
                         "\x50\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40"
                         "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x00";

static const char *g_NUMBERS = "7654321";
static u8 D_8008AA28 = 0;
static s32 D_8008AA2C = 0;

main_menu_t *main_menu_create(u32 Unk1) {
    main_menu_t *allocated = (main_menu_t *) memory_allocate_mem(0xC4);

    if (allocated) {
        main_menu_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8004D578(main_menu_t *This, dream_sys_t *DreamSys) {
    char *font_icon_path = &g_FONT_ICON_PATH;
    func_8003DFBC()->Construct(This, font_icon_path, "ETC\\ETCSE", 0);
    This->vtable = main_menu_get_vtable();
    This->m_SoundEngine->vtable->Unk23(This->m_SoundEngine, -1);
    This->m_DreamSys = DreamSys;
    This->m_MemoryCard = 0;
    This->m_RegionCode = DreamSys->vtable->GetRegionCode(DreamSys, &This->m_RegionCodeParam);
    func_8004D6AC(DreamSys->vtable->Unk103(DreamSys, 0));

    This->vtable->Unk53(This, font_icon_path);
    This->vtable->Unk15(This, DreamSys);
}

void func_8004D678(main_menu_t *This, s32 Vtable) {
    s32 unk47 = This->m_RegionCode;
    s32 is_enabled = 1;

    if (*(int *) (unk47 + 12) > 9999999) {
        is_enabled = *(u32 *) (unk47 + 756) == 0;
    }

    *(u32 *) (*(u32 *) (Vtable + 24) + 4) = is_enabled;
}

void func_8004D6AC(s32 Value) {
    func_8004109C(g_NUMBERS, Value, 3, 0);

    __builtin_memcpy(g_DAY_STR + 0x12, g_NUMBERS, 6);
}

void func_8004D704(main_menu_t *This) {
    if (This->m_MemoryCard) {
        This->m_MemoryCard->vtable->Destroy(This->m_MemoryCard);
        This->m_TextureHelper->vtable->Destruct(This->m_TextureHelper);
    }

    func_8003DFBC()->Cleanup(This);
}

// Something related to menu input
void func_8004D788(main_menu_t *This, void **Unk2, s32 Unk3) {
    func_8003DFBC()->Unk13(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xF) == 0xB) {
        This->vtable->Unk77(This, Unk2, Unk3);
    }
}

void func_8004D814(main_menu_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk10 = 400;
    This->vtable->Unk52(This, "ETC\\TITLE.TIM", 0);
    This->vtable->Unk26(This, 10);
    This->m_DreamSys->vtable->Unk59(This->m_DreamSys, 0, 0);
}

void func_8004D898(main_menu_t *This) {
    s32 *iter_D_ptr;
    u32 loop_count;

    loop_count = 0;
    iter_D_ptr = &D_80086DAC;

    do {
        s32 *param_for_Unk30_arg2 = iter_D_ptr;

        iter_D_ptr += 3;
        loop_count += 1;

        (*(void (**)(s32, char *, s32 *))(**(u32 **) This->m_Unk2 + 0x78))(*(u32 *) This->m_Unk2,
                                                                           (char *) &This->m_Unk35 + 3,
                                                                           param_for_Unk30_arg2); // TODO
    } while (loop_count < 2);
}

void func_8004D90C(main_menu_t *This, s32 Unk) {
    func_8003DFBC()->Unk23(This, Unk);

    if (Unk == 5) {
        This->vtable->Unk72(This, 0);
    }

    if (Unk == 10) {
        This->vtable->Unk30(This);
        This->vtable->Unk59(This, *(u32 *) (This->m_Unk18 + 8), 1);
        This->vtable->Unk29(This);
    }
}

// TODO messy function
void func_8004D9D4(main_menu_t *This) {
    class_2C694_vtable_t *obj_from_bc;
    int m_Unk21_val;
    void (*method_to_call_ptr)(main_menu_t *);

    obj_from_bc = func_8003DFBC();
    obj_from_bc->Unk35(This);

    m_Unk21_val = This->m_Unk21;

    if (m_Unk21_val == 2) {
        goto L_case2_Unk75;
    }

    if (m_Unk21_val >= 3) {
        goto L_handle_ge3;
    }

    if (m_Unk21_val == 1) {
        goto L_case1_Unk59_Unk36;
    }

    goto L_epilogue;

L_handle_ge3:
    if (m_Unk21_val == 3) {
        goto L_case3_Unk76;
    }

    if (m_Unk21_val == 4) {
        goto L_case4_setUnk13_Unk36;
    }

    goto L_epilogue;

L_case1_Unk59_Unk36: {
    dream_sys_t *local_dream_sys = This->m_DreamSys;
    This->m_Unk13 = 0;
    local_dream_sys->vtable->Unk59(local_dream_sys, 0, 1);

    method_to_call_ptr = This->vtable->Unk36;
    goto L_common_call_point;
}

L_case2_Unk75:
    method_to_call_ptr = This->vtable->Unk75;
    goto L_common_call_point;

L_case3_Unk76:
    method_to_call_ptr = This->vtable->Unk76;
    goto L_common_call_point;

L_case4_setUnk13_Unk36: {
    main_menu_vtable_t *vtable_for_case4 = This->vtable;
    This->m_Unk13 = 2;
    method_to_call_ptr = vtable_for_case4->Unk36;
    goto L_common_call_point;
}

L_common_call_point:
    method_to_call_ptr(This);
    goto L_epilogue;

L_epilogue:
    return;
}

void func_8004DABC(main_menu_t *This) {
    s32 unk;

    func_8003DFBC()->Unk36(This);
    unk = *(u32 *) (This->m_Unk23 + 20);
    This->m_DreamSys->vtable->Unk102(This->m_DreamSys, &unk);
}

void func_8004DB18(main_menu_t *This, void *Unk) {
    s32 len;
    void *mem;
    class_310CC_t *unk_class;

    if (Unk) {
        if (This->m_DreamSys->vtable->Unk106(This->m_DreamSys)) {
            strcpy(g_DAY_STR + 0x18, g_SPACES);
            func_800507F8(g_DAY_STR, 0);
        }

        len = (__builtin_strlen(g_DAY_STR) >> 1) + 4;
        mem = memory_allocate_mem(len);
        func_80040FC0(mem, g_DAY_STR);

        This->m_Unk43 = func_800408CC(*((u32 *) Unk + 1), len, mem);
        This->m_Unk43->m_Unk41_4 = 8;
        This->m_Unk43->m_Unk42_1 = 4;
        This->m_Unk43->m_Unk41_3 = 9;
        memory_free_mem(mem);
    }
}

void func_8004DC08(main_menu_t *This) {
    This->m_Unk43->vtable->Destroy(This->m_Unk43);
    func_8003DFBC()->Unk54(This);
}

INCLUDE_ASM("asm/nonmatchings/main_menu", func_8004DC64);
// void func_8004DC64(main_menu_t *This, s32 Unk) {
//     func_8003DFBC()->Unk55(This, Unk);
//     This->m_Unk43->vtable->Unk18(This->m_Unk43, Unk, &D_8008A9B4);
// }

// INCLUDE_ASM("asm/nonmatchings/main_menu", func_8004DCD0);
void func_8004DCD0(main_menu_t *This, char *Unk_arg_s0) {
    u8 local_buf[3];
    u8 *s1_buf_ptr = local_buf;

    u32 v1_idx_for_D8AA28;
    s32 v0_val_to_modify;
    u8 *v1_target_addr_in_buf;

    func_8003DFBC()->Unk56(This, Unk_arg_s0);

    if (This->m_Unk14 != 0) {
        v1_idx_for_D8AA28 = D_8008AA28;
        v0_val_to_modify = 0x80;
        local_buf[0] = 0;
        local_buf[1] = 0;
        local_buf[2] = 0;

        v1_target_addr_in_buf = v1_idx_for_D8AA28 + s1_buf_ptr;
    } else {
        __builtin_memcpy(local_buf, Unk_arg_s0, 3);

        if (D_8008AA2C < 0x80) {
            v0_val_to_modify = local_buf[0];
            v0_val_to_modify = v0_val_to_modify + 0x80;
            local_buf[0] = v0_val_to_modify;
            goto UPDATES_ONLY;
        }

        v1_idx_for_D8AA28 = D_8008AA28;
        v1_target_addr_in_buf = s1_buf_ptr + v1_idx_for_D8AA28;

        v0_val_to_modify = *v1_target_addr_in_buf;
        v0_val_to_modify = v0_val_to_modify + 0x80;
    }
STORE_AND_PROCEED:
    *v1_target_addr_in_buf = v0_val_to_modify;

UPDATES_ONLY:
    if ((++D_8008AA28 & 0xFFU) >= 3) {
        D_8008AA28 = 0;
    }

    if (++D_8008AA2C >= 0x101) {
        D_8008AA2C = 0;
    }

    This->m_Unk43->vtable->Unk45(This->m_Unk43, local_buf);
}

INCLUDE_ASM("asm/nonmatchings/main_menu", func_8004DE08);
// void func_8004DE08(main_menu_t *This) {
//     s32 unk_value;
//     u8 *mem;
//     u32 unk[2];

//     unk_value = This->m_Unk21;
//     mem = memory_allocate_mem(*((u8 *)This->m_Unk43 + 169));

//     func_80040FC0(mem, g_DAY_STR);
//     (*(void ( **)(void *, u8 *))(*(u32 *)This->m_Unk43 + 204))(This->m_Unk43, mem);
//     memory_free_mem(mem);

//     func_8004D678(This, This->m_Unk18, This->m_DreamSys);
//     This->vtable->Unk55(This, (void *)This->m_Unk4);
//     This->m_DreamSys->vtable->Unk102(This->m_DreamSys, unk);

//     This->m_Unk21 = 5;
//     This->vtable->Unk23(This, 11);
//     This->vtable->Unk70(This, unk[0], 1);
//     This->vtable->Unk23(This, 15);
//     This->vtable->Unk59(This, unk_value, 0);
//     This->m_DreamSys->vtable->Unk102(This->m_DreamSys, unk);
//  }

void func_8004DF64(main_menu_t *This, s32 Unk) {
    if (!This->m_MemoryCard) {
        This->m_TextureHelper = texture_helper_create("CARD\\FILEICN1.TIM\0", Unk);
        This->m_MemoryCard = memory_card_create(1, 0);
    }

    This->m_MemoryCard->vtable->Unk26(This->m_MemoryCard, D_80011454, &D_80086D6C, *(u32 *) (This->m_Unk2 + 4),
                                      This->m_Unk3, This->m_Unk4, This->m_SoundEngine);

    This->vtable->Unk3(This, (s32) This->m_MemoryCard);
    This->vtable->Unk4(This, *(void **) (This->m_Unk2 + 4));
    This->vtable->Unk4(This, (void *) This->m_Unk3);
}

void func_8004E054(main_menu_t *This) {
    This->vtable->Unk3(This, *(u32 *) (This->m_Unk2 + 4));
    This->vtable->Unk3(This, This->m_Unk3);
    This->vtable->Unk4(This, This->m_MemoryCard);
    This->m_MemoryCard->vtable->Unk27(This->m_MemoryCard);
}

void func_8004E0E4(main_menu_t *This) {
    dream_sys_t *dream_sys_obj;
    u32 title_ptr; // points to ETC\TITLE.TIM
    void (*func_ptr)(dream_sys_t *, s32 *);

    s32 unk_struct[2];

    dream_sys_obj = This->m_DreamSys;
    title_ptr = *(u32 *) ((char *) This->m_Unk23 + 0x14);
    func_ptr = dream_sys_obj->vtable->Unk102;
    unk_struct[0] = title_ptr;
    func_ptr(dream_sys_obj, &unk_struct[0]);
    This->vtable->Unk73(This);

    if (This->m_DreamSys->vtable->Unk106(This->m_DreamSys)) {
        *(u8 *) D_8008AA10 = 0;
    }

    This->m_MemoryCard->vtable->Unk29(This->m_MemoryCard, D_8008AA10, g_DAY_STR, 13, 3, This->m_TextureHelper,
                                      This->m_RegionCode, This->m_RegionCodeParam);
}

void func_8004E1C4(main_menu_t *This) {
    This->vtable->Unk73(This);

    This->m_MemoryCard->vtable->Unk28(This->m_MemoryCard, D_8008AA10, g_DAY_STR, This->m_RegionCode,
                                      This->m_RegionCodeParam);
}

void func_8004E230(main_menu_t *This, void *Unk2, s32 Unk3) {
    if (Unk3 > 0x17) {
        return;
    }

    if (Unk3 < 0x16) {
        return;
    }

    This->vtable->Unk74(This, Unk2);

    if (Unk3 == 0x16) {
        This->m_DreamSys->vtable->Unk105(This->m_DreamSys);
        This->vtable->Unk72(This, 22);
    }
}

main_menu_vtable_t *main_menu_get_vtable(void) {
#ifndef CCG8
    return &g_MAIN_MENU_VTABLE;
#else
    // G8 hack
    main_menu_vtable_t *result;

    __asm__("lui     %0, %%hi(%1)\n\t"
            "addiu   %0, %0, %%lo(%1)"
            : "=r"(result)
            : "i"(&g_MAIN_MENU_VTABLE));

    return result;
#endif
}
