#ifndef LSD_ASSET_PLAYER_H
#define LSD_ASSET_PLAYER_H

#include <common.h>

typedef struct asset_player_vtable {
    /* 0x000 8006e5f8 */ u32 value;
    /* 0x004 8006e5fc */ void (*Destroy)(void *);
    /* 0x008 8006e600 */ void (*Construct)(void *, s32, s32, s32, s32);
    /* 0x00C 8006e604 */ void (*Cleanup)(void *);
    /* 0x010 8006e608 */ void (*Unk3)(void *);
    /* 0x014 8006e60c */ void (*Unk4)(void *);
    /* 0x018 8006e610 */ void (*Unk5)(void *);
    /* 0x01C 8006e614 */ void (*Unk6)(void *);
    /* 0x020 8006e618 */ void (*Unk7)(void *);
    /* 0x024 8006e61c */ void (*Unk8)(void *);
    /* 0x028 8006e620 */ void (*Unk9)(void *);
    /* 0x02C 8006e624 */ void (*Unk10)(void *);
    /* 0x030 8006e628 */ void (*Unk11)(void *);
    /* 0x034 8006e62c */ void (*Unk12)(void *);
    /* 0x038 8006e630 */ void (*Unk13)(void *);
    /* 0x03C 8006e634 */ void (*Unk14)(void *);
    /* 0x040 8006e638 */ void (*Unk15)(void *);
    /* 0x044 8006e63c */ void (*Unk16)(void *, void *, const char *, s32, s32);
    /* 0x048 8006e640 */ void (*Unk17)(void *);
    /* 0x04C 8006e644 */ void (*Unk18)(void *);
    /* 0x050 8006e648 */ void (*Unk19)(void *);
    /* 0x054 8006e64c */ void (*Unk20)(void *);
    /* 0x058 8006e650 */ void (*Unk21)(void *);
    /* 0x05C 8006e654 */ void (*Unk22)(void *);
    /* 0x060 8006e658 */ void (*Unk23)(void *, s32);
    /* 0x064 8006e65c */ void (*Unk24)(void *);
    /* 0x068 8006e660 */ void (*Unk25)(void *);
    /* 0x06C 8006e664 */ void (*Unk26)(void *, u32);
    /* 0x070 8006e668 */ void (*Unk27)(void *);
    /* 0x074 8006e66c */ void (*Unk28)(void *);
    /* 0x078 8006e670 */ void (*Unk29)(void *);
    /* 0x07C 8006e674 */ void (*Unk30)(void *);
    /* 0x080 8006e678 */ void (*Unk31)(void *);
    /* 0x084 8006e67c */ void (*Unk32)(void *);
    /* 0x088 8006e680 */ void (*Unk33)(void *);
    /* 0x08C 8006e684 */ void (*Unk34)(void *);
    /* 0x090 8006e688 */ void (*Unk35)(void *);
    /* 0x094 8006e68c */ void (*Unk36)(void *);
    /* 0x098 8006e690 */ void (*Unk37)(void *);
    /* 0x09C 8006e694 */ void (*Unk38)(void *);
    /* 0x0A0 8006e698 */ void (*Unk39)(void *);
    /* 0x0A4 8006e69c */ void (*Unk40)(void *);
    /* 0x0A8 8006e6a0 */ void (*Unk41)(void *);
    /* 0x0AC 8006e6a4 */ void (*Unk42)(void *);
    /* 0x0B0 8006e6a8 */ void (*Unk43)(void *);
    /* 0x0B4 8006e6ac */ void (*Unk44)(void *);
    /* 0x0B8 8006e6b0 */ void (*Unk45)(void *);
    /* 0x0BC 8006e6b4 */ void (*Unk46)(void *);
    /* 0x0C0 8006e6b8 */ void (*Unk47)(void *);
    /* 0x0C4 8006e6bc */ void (*Unk48)(void *);
    /* 0x0C8 8006e6c0 */ void (*Unk49)(void *);
    /* 0x0CC 8006e6c4 */ void (*Unk50)(void *);
    /* 0x0D0 8006e6c8 */ void (*Unk51)(void *);
    /* 0x0D4 8006e6cc */ void (*Unk52)(void *);
    /* 0x0D8 8006e6d0 */ void (*Unk53)(void *);
    /* 0x0DC 8006e6d4 */ void (*Unk54)(void *);
    /* 0x0E0 8006e6d8 */ void (*Unk55)(void *);
    /* 0x0E4 8006e6dc */ void (*Unk56)(void *);
    /* 0x0E8 8006e6e0 */ void (*Unk57)(void *);
    /* 0x0EC 8006e6e4 */ void (*Unk58)(void *);
    /* 0x0F0 8006e6e8 */ void (*Unk59)(void *);
    /* 0x0F4 8006e6ec */ void (*Unk60)(void *);
    /* 0x0F8 8006e6f0 */ void (*Unk61)(void *);
    /* 0x0FC 8006e6f4 */ void (*Unk62)(void *);
    /* 0x100 8006e6f8 */ void (*Unk63)(void *);
    /* 0x104 8006e6fc */ void (*Unk64)(void *);
    /* 0x108 8006e700 */ void (*Unk65)(void *);
    /* 0x10C 8006e704 */ void (*Unk66)(void *);
    /* 0x110 8006e708 */ void (*Unk67)(void *);
    /* 0x114 8006e70c */ void (*Unk68)(void *);
    /* 0x118 8006e710 */ void (*Unk69)(void *);
    /* 0x11C 8006e714 */ void (*Unk70)(void *);
    /* 0x120 8006e718 */ void (*Unk71)(void *);
    /* 0x124 8006e71c */ void (*Unk72)(void *);
    /* 0x128 8006e720 */ void (*Unk73)(void *);
    /* 0x12C 8006e724 */ void (*Unk74)(void *, s32);
    /* 0x130 8006e728 */ void (*Unk75)(void *);
    /* 0x134 8006e72c */ void (*Unk76)(void *);
} asset_player_vtable_t;

typedef struct asset_player {
    /* 0x00 */ asset_player_vtable_t *vtable;
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
    /* 0x48 */ s32 m_Unk17;
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
    /* 0xA4 */ s32 m_Unk40;
    /* 0xA8 */ s32 m_Unk41;
    /* 0xAC */ s32 m_Unk42;
    /* 0xB0 */ s32 m_Unk43;
    /* 0xB4 */ s32 m_Unk44;
    /* 0xB8 */ s32 m_Unk45;
    /* 0xBC */ s32 m_Unk46;
    /* 0xC0 */ s32 m_Unk47;
    /* 0xC4 */ s32 m_Unk48;
    /* 0xC8 */ s32 m_Unk49;
    /* 0xCC */ s32 m_Unk50;
    /* 0xD0 */ s32 m_Unk51;
    /* 0xD4 */ s32 m_Unk52;
    /* 0xD8 */ s32 m_Unk53;
    /* 0xDC */ s32 m_Unk54;
} asset_player_t;

asset_player_t *asset_player_create(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
asset_player_vtable_t *asset_player_get_vtable(void);

#endif