#ifndef LSD_MAIN_MENU_H
#define LSD_MAIN_MENU_H

#include <common.h>

#include "310CC.h"
#include "dream_sys.h"
#include "memory_card.h"
#include "sound_engine.h"
#include "texture_helper.h"

typedef struct main_menu_vtable {
    /* 0x000 80086b60 */ u32 value;
    /* 0x004 80086b64 */ void (*Unk0)(void *);
    /* 0x008 80086b68 */ void (*Construct)(void *, s32);
    /* 0x00C 80086b6c */ void (*Unk2)(void *);
    /* 0x010 80086b70 */ void (*Unk3)(void *, void *);
    /* 0x014 80086b74 */ void (*Unk4)(void *, void *);
    /* 0x018 80086b78 */ void (*Unk5)(void *);
    /* 0x01C 80086b7c */ void (*Unk6)(void *);
    /* 0x020 80086b80 */ void (*Unk7)(void *);
    /* 0x024 80086b84 */ void (*Unk8)(void *);
    /* 0x028 80086b88 */ void (*Unk9)(void *);
    /* 0x02C 80086b8c */ void (*Unk10)(void *);
    /* 0x030 80086b90 */ void (*Unk11)(void *);
    /* 0x034 80086b94 */ void (*Unk12)(void *);
    /* 0x038 80086b98 */ void (*Unk13)(void *);
    /* 0x03C 80086b9c */ u32 pad1;
    /* 0x040 80086ba0 */ void (*Unk15)(void *, dream_sys_t *);
    /* 0x044 80086ba4 */ void (*Unk16)(void *);
    /* 0x048 80086ba8 */ void (*Unk17)(void *);
    /* 0x04C 80086bac */ void (*Unk18)(void *);
    /* 0x050 80086bb0 */ void (*Unk19)(void *);
    /* 0x054 80086bb4 */ void (*Unk20)(void *);
    /* 0x058 80086bb8 */ void (*Unk21)(void *);
    /* 0x05C 80086bbc */ void (*Unk22)(void *);
    /* 0x060 80086bc0 */ void (*Unk23)(void *, s32);
    /* 0x064 80086bc4 */ void (*Unk24)(void *);
    /* 0x068 80086bc8 */ void (*Unk25)(void *);
    /* 0x06C 80086bcc */ void (*Unk26)(void *, s32);
    /* 0x070 80086bd0 */ void (*Unk27)(void *);
    /* 0x074 80086bd4 */ void (*Unk28)(void *);
    /* 0x078 80086bd8 */ void (*Unk29)(void *);
    /* 0x07C 80086bdc */ void (*Unk30)(void *);
    /* 0x080 80086be0 */ void (*Unk31)(void *);
    /* 0x084 80086be4 */ void (*Unk32)(void *);
    /* 0x088 80086be8 */ u32 pad2;
    /* 0x08C 80086bec */ u32 pad3;
    /* 0x090 80086bf0 */ void (*Unk35)(void *);
    /* 0x094 80086bf4 */ void (*Unk36)(void *);
    /* 0x098 80086bf8 */ void (*Unk37)(void *);
    /* 0x09C 80086bfc */ void (*Unk38)(void *);
    /* 0x0A0 80086c00 */ void (*Unk39)(void *);
    /* 0x0A4 80086c04 */ void (*Unk40)(void *);
    /* 0x0A8 80086c08 */ void (*Unk41)(void *);
    /* 0x0AC 80086c0c */ void (*Unk42)(void *);
    /* 0x0B0 80086c10 */ void (*Unk43)(void *);
    /* 0x0B4 80086c14 */ u32 pad4;
    /* 0x0B8 80086c18 */ u32 pad5;
    /* 0x0BC 80086c1c */ u32 pad6;
    /* 0x0C0 80086c20 */ void (*Unk47)(void *);
    /* 0x0C4 80086c24 */ void (*Unk48)(void *);
    /* 0x0C8 80086c28 */ u32 pad7;
    /* 0x0CC 80086c2c */ u32 pad8;
    /* 0x0D0 80086c30 */ u32 pad9;
    /* 0x0D4 80086c34 */ void (*Unk52)(void *, char *, s32);
    /* 0x0D8 80086c38 */ void (*Unk53)(void *, char **);
    /* 0x0DC 80086c3c */ void (*Unk54)(void *);
    /* 0x0E0 80086c40 */ void (*Unk55)(void *, void *);
    /* 0x0E4 80086c44 */ void (*Unk56)(void *);
    /* 0x0E8 80086c48 */ void (*Unk57)(void *);
    /* 0x0EC 80086c4c */ void (*Unk58)(void *);
    /* 0x0F0 80086c50 */ void (*Unk59)(void *, s32, s32);
    /* 0x0F4 80086c54 */ void (*Unk60)(void *);
    /* 0x0F8 80086c58 */ void (*Unk61)(void *);
    /* 0x0FC 80086c5c */ void (*Unk62)(void *);
    /* 0x100 80086c60 */ void (*Unk63)(void *);
    /* 0x104 80086c64 */ void (*Unk64)(void *);
    /* 0x108 80086c68 */ void (*Unk65)(void *);
    /* 0x10C 80086c6c */ void (*Unk66)(void *);
    /* 0x110 80086c70 */ void (*Unk67)(void *);
    /* 0x114 80086c74 */ void (*Unk68)(void *);
    /* 0x118 80086c78 */ void (*Unk69)(void *);
    /* 0x11C 80086c7c */ void (*Unk70)(void *, s32, s32);
    /* 0x120 80086c80 */ void (*Unk71)(void *);
    /* 0x124 80086c84 */ void (*Unk72)(void *, s32);
    /* 0x128 80086c88 */ void (*Unk73)(void *);
    /* 0x12C 80086c8c */ void (*Unk74)(void *, void *);
    /* 0x130 80086c90 */ void (*Unk75)(void *);
    /* 0x134 80086c94 */ void (*Unk76)(void *);
    /* 0x138 80086c98 */ void (*Unk77)(void *, void **, s32);
} main_menu_vtable_t;

typedef struct main_menu {
    /* 0x00 */ main_menu_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ sound_engine_t *m_SoundEngine;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Unk23;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ s32 m_Unk30;
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_Unk32;
    /* 0x88 */ s32 m_Unk33;
    /* 0x8C */ s32 m_Unk34;
    /* 0x90 */ s32 m_Unk35;
    /* 0x94 */ s32 m_Unk36;
    /* 0x98 */ s32 m_Unk37;
    /* 0x9C */ s32 m_Unk38;
    /* 0xA0 */ s32 m_Unk39;
    /* 0xA4 */ dream_sys_t *m_DreamSys;
    /* 0xA8 */ texture_helper_t *m_TextureHelper;
    /* 0xAC */ memory_card_t *m_MemoryCard;
    /* 0xB0 */ class_310CC_t *m_Unk43;
    /* 0xB4 */ s32 m_Unk44;
    /* 0xB8 */ s32 m_Unk45;
    /* 0xBC */ char *m_RegionCode;    // Points to J01, probably a struct
    /* 0xC0 */ s32 m_RegionCodeParam; // Set to 0x700, argument passed into GetRegionCode
    /* 0xC4 */ s32 m_Unk48;
} main_menu_t;

main_menu_t *main_menu_create(u32 Unk1);
main_menu_vtable_t *main_menu_get_vtable(void);

#endif