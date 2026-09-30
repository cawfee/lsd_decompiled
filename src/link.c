#include "common.h"
#include "dream_sys.h"
#include "entity.h"
#include "3520C.h"

s32 g_CurrentLocation = -1;
void *g_LinkScene = NULL;
dream_sys_t *g_LinkDreamSys = NULL;
s32 g_EntityHelper = 0;
void *g_LinkSceneData = NULL;

void transform_local_to_world(void *arg0, void *arg1, void *arg2, s32 arg3);

void func_8001EACC(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
s8 *link_find_teleport(s16 *arg0);
s32 link_check_teleport_condition(s32 arg0, s8 *arg1);
s32 link_spawn_object_group(s32 arg0, s8 *arg1, s32 arg2);
s32 link_spawn_object(s32 arg0, s32 arg1, u8 *arg2, class_3520C_t *arg3);
s32 func_80044A0C(s32 arg0);
s32 link_check_object(s32 arg0, void *arg1);
s32 link_create_object(s32 arg0, void *arg1, s32 arg2, s32 arg3);

extern base_class_t *g_SpecialEntityModel[];
extern base_class_t *g_SpecialEntityInstance[];

typedef struct {
    s16 m_Unk0;
    s16 m_Unk1;
    s16 m_Unk2;
} teleport_entry_t;

extern s8 g_StageTeleportCounts[];
extern teleport_entry_t *g_StageTeleportTables[];
extern u8 *g_StageObjectTables[];
extern s8 g_StageObjectCounts[];
extern s32 g_GrayManModelPath[];
extern s32 g_SymDogModelPath[];
void file_buf_set_triple(void *, s32, s32, s32);
void *func_8004468C(s32);

void link_init_stage_objects(void) {
    s32 sp10[6];
    s8 *counts;
    u8 **tables;
    u32 i;
    s32 j;
    s32 off;
    s32 *file;
    u8 **t;

    i = 0;
    counts = g_StageObjectCounts;
    tables = g_StageObjectTables;
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
    file_buf_set_triple(sp10, 0, (s32)g_GrayManModelPath, 1);
    i = 0;
    file = g_SymDogModelPath;
    off = 0;
    do {
        *(base_class_t **)((u8 *)g_SpecialEntityModel + off) = (base_class_t *)func_8004468C((s32)sp10);
        off += 0x14;
        i += 1;
        sp10[1] = (s32)file;
    } while (i == 0);
}

void link_destroy_models(void) {
    base_class_t **p;
    s32 i;
    base_class_t *obj;

    p = g_SpecialEntityModel;
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

void link_spawn_special_entity(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p;
    s32 i;
    entity_spawn_args_t args;

    p = (u8 *)g_SpecialEntityModel;
    i = 0;
    g_CurrentLocation = arg0;
    g_LinkScene = (void *)arg1;
    g_LinkDreamSys = (dream_sys_t *)arg2;
    g_EntityHelper = arg3;
    g_LinkSceneData = (void *)arg4;
    do {
        s32 id = i + 0x62;
        i += 1;
        args.m_Unk3 = *(s32 *)p;
        *(entity_t **)(p + 4) = entity_create(id, &args, g_EntityHelper);
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

void link_enable_teleport_type(s32 arg0) {
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

void link_destroy_teleport_entity(void) {
    base_class_t **p;
    s32 i;
    base_class_t *obj;

    i = 0;
    p = g_SpecialEntityInstance;
    do {
        obj = *p;
        i += 1;
        if (obj != NULL) {
            *p = obj->vtable->Destroy(obj);
        }
        p = (base_class_t **)((u8 *)p + 0x14);
    } while (i == 0);
}

s32 link_spawn_from_tile(s32 arg0, s16 *arg1, s32 arg2) {
    s8 *v0;

    v0 = link_find_teleport(arg1);
    if (v0 != NULL) {
        if (link_check_teleport_condition(arg2, v0) != 0) {
            return link_spawn_object_group(arg2, (s32)v0, arg0);
        }
        if (g_CurrentLocation != 0) {
            s32 value = rand();

            if (value == (value / 12) * 0xC && (arg2 & 1) == 0) {
                link_activate_object((u8 *)g_SpecialEntityModel);
            }
        }
        return 0;
    }
    return 0;
}

s32 link_find_teleport(s16 *arg0) {
    s32 temp_a2;
    teleport_entry_t *var_a0;
    s32 var_a1;

    temp_a2 = g_StageTeleportCounts[g_CurrentLocation];
    var_a0 = g_StageTeleportTables[g_CurrentLocation];
    var_a1 = 0;
    while (var_a1 < temp_a2) {
        if (*arg0 == var_a0->m_Unk0) {
            return link_adjust_teleport_target(var_a0, var_a1, temp_a2, arg0);
        }
        var_a1 += 1;
        var_a0 += 1;
    }
    return 0;
}

s32 link_adjust_teleport_target(s32 arg0, s32 arg1) {
    s32 var_s0 = arg0;
    s32 var_s1 = g_CurrentLocation;

    if (var_s1 == 4 && arg1 == 0x10 &&
        g_LinkDreamSys->vtable->dream_sys_get_dream_color(g_LinkDreamSys) == var_s1) {
        var_s0 += 0x1E;
    }
    return var_s0;
}

s32 link_check_teleport_condition(s32 arg0, s8 *arg1) {
    s8 v = arg1[2];
    s32 ret = 1;

    if (v != 0) {
        arg0 = arg0 % 2 + 1;
        ret = v != arg0;
    }
    return ret;
}

s32 link_spawn_object_group(s32 arg0, s8 *arg1, s32 arg2) {
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
        temp_s4 = g_StageObjectTables[g_CurrentLocation];
        while (var_s0 < end) {
            s8 c = *var_s0;

            if (c == -1) {
                break;
            }
            link_spawn_object(arg0, (s32)arg1, (s32)(temp_s4 + c * 8), temp_v0);
            var_s0 += 1;
        }
        return temp_v0;
    }
    return 0;
}

s32 link_spawn_object(s32 arg0, s32 arg1, u8 *arg2, class_3520C_t *arg3) {
    entity_spawn_args_t sp10;
    s32 temp_v0;
    s8 *var_s0;
    s8 *temp_s2;

    if (link_check_object(arg0, arg2) != 0) {
        var_s0 = (s8 *)(arg2 + 4);
        link_enable_teleport_type(arg2[3]);
        temp_v0 = arg3->vtable->Unk33(arg3, (s8)arg2[2]);
        temp_s2 = (s8 *)(arg2 + 8);
        sp10.m_Unk3 = temp_v0;
        if (temp_v0 != 0 && var_s0 < temp_s2) {
            while (var_s0 < temp_s2) {
                if (*var_s0 == -1) {
                    break;
                }
                if (link_create_object(arg2[3], &sp10, arg1, (u8)*var_s0) != 0) {
                    return 1;
                }
                var_s0 += 1;
            }
        }
        if (arg2[3] == 2) {
            return link_spawn_object(arg0, arg1, arg2 + 0x38, arg3);
        }
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/link", link_check_object);

extern s16 SPECIAL_DAYS[];

s32 link_is_special_color(s32 arg0) {
    s32 temp_s0 = ((s8 *)SPECIAL_DAYS)[0x4A + arg0];

    return temp_s0 == g_LinkDreamSys->vtable->dream_sys_get_dream_color(g_LinkDreamSys);
}

s32 link_check_day_offset(s32 arg0, s32 arg1) {
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

INCLUDE_ASM("asm/nonmatchings/link", link_create_object);

void link_activate_object(u8 *arg0) {
    vec3d_t pos;

    if (*(entity_t **)(arg0 + 4) != NULL) {
        (*(entity_t **)(arg0 + 4))->vtable->Unk19(*(entity_t **)(arg0 + 4));
        transform_local_to_world(g_LinkDreamSys, &pos, arg0 + 8, 0);
        (*(entity_t **)(arg0 + 4))->vtable->Unk18(*(entity_t **)(arg0 + 4),
                                                  g_LinkDreamSys, g_LinkSceneData,
                                                  g_LinkScene, &pos);
        func_8001EACC(*(entity_t **)(arg0 + 4), g_LinkDreamSys, 1, 0, 0);
    }
}
