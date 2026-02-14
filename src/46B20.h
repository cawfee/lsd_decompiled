#ifndef LSD_46B20_H
#define LSD_46B20_H

#include <common.h>

typedef struct class_46B20_vtable {
    /* 0x000 800876fc */ u32 value;
    /* 0x004 80087700 */ void (*Destroy)(void *);
    /* 0x008 80087704 */ void *(*Construct)(void *, s32, s32, s32, s32);
    /* 0x00C 80087708 */ void (*Cleanup)(void *);
    /* 0x010 8008770c */ void (*Unk3)(void *);
    /* 0x014 80087710 */ void (*Unk4)(void *);
    /* 0x018 80087714 */ void (*Unk5)(void *);
    /* 0x01C 80087718 */ void (*Unk6)(void *);
    /* 0x020 8008771c */ void (*Unk7)(void *);
    /* 0x024 80087720 */ void (*Unk8)(void *);
    /* 0x028 80087724 */ void (*Unk9)(void *);
    /* 0x02C 80087728 */ void (*Unk10)(void *);
    /* 0x030 8008772c */ void (*Unk11)(void *);
    /* 0x034 80087730 */ void (*Unk12)(void *);
    /* 0x038 80087734 */ void (*Unk13)(void *);
    /* 0x03C 80087738 */ void (*Unk14)(void *);
    /* 0x040 8008773c */ void (*Unk15)(void *, s32);
    /* 0x044 80087740 */ void (*Unk16)(void *, s32, s32);
    /* 0x048 80087744 */ void (*Unk17)(void *, s32, s32);
    /* 0x04C 80087748 */ void (*Unk18)(void *, s32, s32);
    /* 0x050 8008774c */ void (*Unk19)(void *);
    /* 0x054 80087750 */ void (*Unk20)(void *);
    /* 0x058 80087754 */ void (*Unk21)(void *);
    /* 0x05C 80087758 */ void (*Unk22)(void *);
    /* 0x060 8008775c */ void (*Unk23)(void *);
    /* 0x064 80087760 */ void (*Unk24)(void *);
    /* 0x068 80087764 */ void (*Unk25)(void *);
    /* 0x06C 80087768 */ void (*Unk26)(void *);
    /* 0x070 8008776c */ void (*Unk27)(void *);
    /* 0x074 80087770 */ void (*Unk28)(void *);
    /* 0x078 80087774 */ void (*Unk29)(void *);
    /* 0x07C 80087778 */ void (*Unk30)(void *);
    /* 0x080 8008777c */ void (*Unk31)(void *);
    /* 0x084 80087780 */ void (*Unk32)(void *);
    /* 0x088 80087784 */ void (*Unk33)(void *);
    /* 0x08C 80087788 */ void (*Unk34)(void *);
    /* 0x090 8008778c */ void (*Unk35)(void *);
    /* 0x094 80087790 */ void (*Unk36)(void *);
    /* 0x098 80087794 */ void (*Unk37)(void *);
    /* 0x09C 80087798 */ void (*Unk38)(void *);
    /* 0x0A0 8008779c */ void (*Unk39)(void *);
    /* 0x0A4 800877a0 */ void (*Unk40)(void *);
    /* 0x0A8 800877a4 */ void (*Unk41)(void *);
    /* 0x0AC 800877a8 */ void (*Unk42)(void *);
    /* 0x0B0 800877ac */ void (*Unk43)(void *);
    /* 0x0B4 800877b0 */ void (*Unk44)(void *);
    /* 0x0B8 800877b4 */ void (*Unk45)(void *);
    /* 0x0BC 800877b8 */ void (*Unk46)(void *);
    /* 0x0C0 800877bc */ void (*Unk47)(void *);
    /* 0x0C4 800877c0 */ void (*Unk48)(void *);
    /* 0x0C8 800877c4 */ void (*Unk49)(void *);
    /* 0x0CC 800877c8 */ void (*Unk50)(void *);
    /* 0x0D0 800877cc */ void (*Unk51)(void *);
    /* 0x0D4 800877d0 */ void (*Unk52)(void *);
    /* 0x0D8 800877d4 */ void (*Unk53)(void *);
    /* 0x0DC 800877d8 */ void (*Unk54)(void *);
    /* 0x0E0 800877dc */ void (*Unk55)(void *);
    /* 0x0E4 800877e0 */ void (*Unk56)(void *);
    /* 0x0E8 800877e4 */ void (*Unk57)(void *);
    /* 0x0EC 800877e8 */ void (*Unk58)(void *);
    /* 0x0F0 800877ec */ void (*Unk59)(void *);
} class_46B20_vtable_t;

typedef struct class_46B20 {
    /* 0x00 */ class_46B20_vtable_t *vtable;
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
} class_46B20_t;

class_46B20_vtable_t *func_80056F4C(void);

#endif // LSD_46B20_H