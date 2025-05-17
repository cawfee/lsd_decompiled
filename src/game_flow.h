#ifndef LSD_GAME_FLOW_H
#define LSD_GAME_FLOW_H

#include "dream_sys.h"
#include "gs_helper.h"

typedef struct game_flow_vtable {
    /* 0x000 8006d3c8 */ u32 value;
    /* 0x004 8006d3cc */ void (*Destroy)(void *);
    /* 0x008 8006d3d0 */ void (*Construct)(void *, void *);
    /* 0x00C 8006d3d4 */ void (*Cleanup)(void *);
    /* 0x010 8006d3d8 */ void (*Unk3)(void *, void *);
    /* 0x014 8006d3dc */ void (*Unk4)(void *, void *);
    /* 0x018 8006d3e0 */ void (*Unk5)(void *);
    /* 0x01C 8006d3e4 */ void (*Unk6)(void *, void *, void **);
    /* 0x020 8006d3e8 */ void (*Unk7)(void *, void *);
    /* 0x024 8006d3ec */ void (*Unk8)(void *, void *);
    /* 0x028 8006d3f0 */ void (*Unk9)(void *);
    /* 0x02C 8006d3f4 */ void (*Unk10)(void *, void *, void **);
    /* 0x030 8006d3f8 */ void (*Unk11)(void *);
    /* 0x034 8006d3fc */ void (*Unk12)(void *);
    /* 0x038 8006d400 */ void (*Unk13)(void *, void *, void *);
    /* 0x03C 8006d404 */ u32 pad;
    /* 0x040 8006d408 */ void (*GetDayBasedSeed)(void *);
    /* 0x044 8006d40c */ void (*GetUnk1)(void *, void *, void *);
    /* 0x048 8006d410 */ void (*Unk17)(void *);
    /* 0x04C 8006d414 */ void (*ExecutePhases)(void *);
    /* 0x050 8006d418 */ void (*DisplayLogoSequence)(void *);
    /* 0x054 8006d41c */ void (*PlayIntroMovie)(void *);
    /* 0x058 8006d420 */ s32 (*ExecMainMenu)(void *);
    /* 0x05C 8006d424 */ void (*Menu_Unused)(void *);
    /* 0x060 8006d428 */ s32 (*ExecDreamSession)(void *);
    /* 0x064 8006d42c */ void (*PlayEndingMovie)(void *);
} game_flow_vtable_t;

typedef struct game_flow {
    /* 0x00 */ game_flow_vtable_t *vtable;
    /* 0x04 */ void *m_UnkObj1;
    /* 0x08 */ void *m_UnkObj2;
    /* 0x0C */ s16 unk1;
    /* 0x0E */ s16 unk2;
    /* 0x10 */ s16 unk3;
    /* 0x12 */ s16 unk4;
    /* 0x14 */ s32 unk5;
    /* 0x18 */ s32 m_IsInit;
    /* 0x1C */ gs_helper_t *m_GSHelper;
    /* 0x20 */ game_config_t *m_Config;
    /* 0x24 */ s32 m_UnkGameMember;
    /* 0x28 */ dream_sys_t *m_pDreamSys;
    /* 0x2C */ s32 m_Unk10;
} game_flow_t;

game_flow_t *game_flow_create(game_config_t *);
game_flow_vtable_t *game_flow_get_vtable(void);

void game_flow_callback();

#endif