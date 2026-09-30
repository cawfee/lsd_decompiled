#include "common.h"
#include "dream_sys.h"
#include "entity.h"
#include "3520C.h"

extern dream_sys_t *D_8008AC00;
extern void *D_8008AC08;
extern void *D_8008ABFC;
extern s32 D_8008ABF8;
extern s32 D_8008AC04;

void func_8001E600(void *arg0, void *arg1, void *arg2, s32 arg3);
void func_8001EACC(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
s8 *func_8005C8AC(s16 *arg0);
s32 func_8005C9A4(s32 arg0, s8 *arg1);
s32 func_8005C9DC(s32 arg0, s8 *arg1, s32 arg2);
s32 func_8005CAB4(s32 arg0, s32 arg1, u8 *arg2, class_3520C_t *arg3);
s32 func_80044A0C(s32 arg0);
s32 func_8005CBC8(s32 arg0, void *arg1);
s32 func_8005CDF8(s32 arg0, void *arg1, s32 arg2, s32 arg3);

extern base_class_t *D_80088D28[];
extern base_class_t *D_80088D2C[];

typedef struct {
    s16 m_Unk0;
    s16 m_Unk1;
    s16 m_Unk2;
} teleport_entry_t;

extern s8 D_80089AC4[];
extern teleport_entry_t *D_80089A8C[];
extern u8 *D_80089A44[];
extern s8 D_80089A7C[];
extern s32 D_8001186C[];
extern s32 D_8001187C[];
void file_buf_set_triple(void *, s32, s32, s32);
void *func_8004468C(s32);

void func_8005C508(void) {
    s32 sp10[6];
    s8 *counts;
    u8 **tables;
    u32 i;
    s32 j;
    s32 off;
    s32 *file;
    u8 **t;

    i = 0;
    counts = D_80089A7C;
    tables = D_80089A44;
    do {
        j = 0;
        if (*counts > 0) {
            t = tables;
            do {
                ((u8 *)*t)[j * 8] = 0;
                j += 1;
            } while (j < *counts);
        }
        counts += 1;
        tables += 1;
        i += 1;
    } while (i < 0xE);
    file_buf_set_triple(sp10, 0, (s32)D_8001186C, 1);
    i = 0;
    file = D_8001187C;
    off = 0;
    do {
        *(base_class_t **)((u8 *)D_80088D28 + off) = (base_class_t *)func_8004468C((s32)sp10);
        off += 0x14;
        i += 1;
        sp10[1] = (s32)file;
    } while (i == 0);
}

void func_8005C5E8(void) {
    base_class_t **p;
    s32 i;
    base_class_t *obj;

    p = D_80088D28;
    i = 0;
    do {
        obj = *p;
        i += 1;
        if (obj != NULL) {
            *p = obj->vtable->Destroy(obj);
        }
        p = (base_class_t **)((u8 *)p + 0x14);
    } while (i == 0);
}

typedef struct {
    s32 m_Unk0;
    s32 m_Unk1;
    s32 m_Unk2;
    s32 m_Unk3;
} entity_spawn_args_t;

void func_8005C650(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p;
    s32 i;
    entity_spawn_args_t args;

    p = (u8 *)D_80088D28;
    i = 0;
    D_8008ABF8 = arg0;
    D_8008ABFC = (void *)arg1;
    D_8008AC00 = (dream_sys_t *)arg2;
    D_8008AC04 = arg3;
    D_8008AC08 = (void *)arg4;
    do {
        s32 id = i + 0x62;
        i += 1;
        args.m_Unk3 = *(s32 *)p;
        *(entity_t **)(p + 4) = entity_create(id, &args, D_8008AC04);
        p += 0x14;
    } while (i == 0);
    set_teleports_enabled(arg0);
}

void set_teleport_links_enabled(s32);

void set_teleports_enabled(s32 arg0) {
    s32 enable = 0;

    if (arg0 == 0xB || arg0 == 3) {
        enable = 1;
    }
    set_teleport_links_enabled(enable);
}

void func_8005C714(s32 arg0) {
    switch (arg0) {
    case 0x4E:
    case 0xB:
    case 0x38:
        set_teleport_links_enabled(1);
        break;
    case 0x5D:
        set_teleport_links_enabled(1);
        break;
    }
}

void func_8005C76C(void) {
    base_class_t **p;
    s32 i;
    base_class_t *obj;

    i = 0;
    p = D_80088D2C;
    do {
        obj = *p;
        i += 1;
        if (obj != NULL) {
            *p = obj->vtable->Destroy(obj);
        }
        p = (base_class_t **)((u8 *)p + 0x14);
    } while (i == 0);
}

s32 func_8005C7D4(s32 arg0, s16 *arg1, s32 arg2) {
    s8 *v0;

    v0 = func_8005C8AC(arg1);
    if (v0 != NULL) {
        if (func_8005C9A4(arg2, v0) != 0) {
            return func_8005C9DC(arg2, (s32)v0, arg0);
        }
        if (D_8008ABF8 != 0) {
            s32 value = rand();

            if (value == (value / 12) * 0xC && (arg2 & 1) == 0) {
                func_8005CF34((u8 *)D_80088D28);
            }
        }
        return 0;
    }
    return 0;
}

s32 func_8005C8AC(s16 *arg0) {
    s32 temp_a2;
    teleport_entry_t *var_a0;
    s32 var_a1;

    temp_a2 = D_80089AC4[D_8008ABF8];
    var_a0 = D_80089A8C[D_8008ABF8];
    var_a1 = 0;
    while (var_a1 < temp_a2) {
        if (*arg0 == var_a0->m_Unk0) {
            return func_8005C930(var_a0, var_a1, temp_a2, arg0);
        }
        var_a1 += 1;
        var_a0 += 1;
    }
    return 0;
}

s32 func_8005C930(s32 arg0, s32 arg1) {
    s32 var_s0 = arg0;
    s32 var_s1 = D_8008ABF8;

    if (var_s1 == 4 && arg1 == 0x10 &&
        D_8008AC00->vtable->dream_sys_get_dream_color(D_8008AC00) == var_s1) {
        var_s0 += 0x1E;
    }
    return var_s0;
}

s32 func_8005C9A4(s32 arg0, s8 *arg1) {
    s8 v = arg1[2];
    s32 ret = 1;

    if (v != 0) {
        arg0 = arg0 % 2 + 1;
        ret = v != arg0;
    }
    return ret;
}

s32 func_8005C9DC(s32 arg0, s8 *arg1, s32 arg2) {
    s32 sp10[4];
    s32 temp_v0;
    s8 *var_s0;
    s8 *end;
    u8 *temp_s4;

    sp10[0] = arg2;
    temp_v0 = func_80044A0C((s32)sp10);
    if (temp_v0 != 0) {
        var_s0 = arg1 + 3;
        end = arg1 + 6;
        temp_s4 = D_80089A44[D_8008ABF8];
        while (var_s0 < end) {
            s8 c = *var_s0;

            if (c == -1) {
                break;
            }
            func_8005CAB4(arg0, (s32)arg1, (s32)(temp_s4 + c * 8), temp_v0);
            var_s0 += 1;
        }
        return temp_v0;
    }
    return 0;
}

s32 func_8005CAB4(s32 arg0, s32 arg1, u8 *arg2, class_3520C_t *arg3) {
    entity_spawn_args_t sp10;
    s32 temp_v0;
    s8 *var_s0;
    s8 *temp_s2;

    if (func_8005CBC8(arg0, arg2) != 0) {
        var_s0 = (s8 *)(arg2 + 4);
        func_8005C714(arg2[3]);
        temp_v0 = arg3->vtable->Unk33(arg3, (s8)arg2[2]);
        temp_s2 = (s8 *)(arg2 + 8);
        sp10.m_Unk3 = temp_v0;
        if (temp_v0 != 0 && var_s0 < temp_s2) {
            while (var_s0 < temp_s2) {
                if (*var_s0 == -1) {
                    break;
                }
                if (func_8005CDF8(arg2[3], &sp10, arg1, (u8)*var_s0) != 0) {
                    return 1;
                }
                var_s0 += 1;
            }
        }
        if (arg2[3] == 2) {
            return func_8005CAB4(arg0, arg1, arg2 + 0x38, arg3);
        }
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CBC8);

extern s16 SPECIAL_DAYS[];

s32 func_8005CD58(s32 arg0) {
    s32 temp_s0 = ((s8 *)SPECIAL_DAYS)[0x4A + arg0];

    return temp_s0 == D_8008AC00->vtable->dream_sys_get_dream_color(D_8008AC00);
}

s32 func_8005CDA8(s32 arg0, s32 arg1) {
    s32 base = (arg0 - 1) / 30 + 1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (base == arg1) {
            return 1;
        }
        arg1 += 3;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CDF8);

void func_8005CF34(u8 *arg0) {
    vec3d_t pos;

    if (*(entity_t **)(arg0 + 4) != NULL) {
        (*(entity_t **)(arg0 + 4))->vtable->Unk19(*(entity_t **)(arg0 + 4));
        func_8001E600(D_8008AC00, &pos, arg0 + 8, 0);
        (*(entity_t **)(arg0 + 4))->vtable->Unk18(*(entity_t **)(arg0 + 4),
                                                  D_8008AC00, D_8008AC08,
                                                  D_8008ABFC, &pos);
        func_8001EACC(*(entity_t **)(arg0 + 4), D_8008AC00, 1, 0, 0);
    }
}
