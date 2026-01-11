#ifndef LSD_2C694_H
#define LSD_2C694_H

#include <common.h>

#include "349B4.h"
#include "354D4.h"
#include "35730.h"
#include "sound_engine.h"
#include "texture_helper.h"

typedef struct class_2C694_vtable {
    /* 0x000 8006e730 */ u32 value;
    /* 0x004 8006e734 */ void (*Destruct)(void *);
    /* 0x008 8006e738 */ void (*Construct)(void *, char **, char *, s32);
    /* 0x00C 8006e73c */ void (*Cleanup)(void *);
    /* 0x010 8006e740 */ void (*Unk3)(void *);
    /* 0x014 8006e744 */ void (*Unk4)(void *);
    /* 0x018 8006e748 */ void (*Unk5)(void *);
    /* 0x01C 8006e74c */ void (*Unk6)(void *);
    /* 0x020 8006e750 */ void (*Unk7)(void *);
    /* 0x024 8006e754 */ void (*Unk8)(void *);
    /* 0x028 8006e758 */ void (*Unk9)(void *);
    /* 0x02C 8006e75c */ void (*Unk10)(void *);
    /* 0x030 8006e760 */ void (*Unk11)(void *);
    /* 0x034 8006e764 */ void (*Unk12)(void *);
    /* 0x038 8006e768 */ void (*Unk13)(void *, void **, s32);
    /* 0x03C 8006e76c */ void (*Unk14)(void *);
    /* 0x040 8006e770 */ void (*Unk15)(void *);
    /* 0x044 8006e774 */ void (*Unk16)(void *, void *, s32);
    /* 0x048 8006e778 */ void (*Unk17)(void *);
    /* 0x04C 8006e77c */ void (*Unk18)(void *);
    /* 0x050 8006e780 */ void (*Unk19)(void *);
    /* 0x054 8006e784 */ void (*Unk20)(void *);
    /* 0x058 8006e788 */ void (*Unk21)(void *);
    /* 0x05C 8006e78c */ void (*Unk22)(void *, s32, s32);
    /* 0x060 8006e790 */ void (*Unk23)(void *, s32);
    /* 0x064 8006e794 */ void (*Unk24)(void *);
    /* 0x068 8006e798 */ void (*Unk25)(void *);
    /* 0x06C 8006e79c */ void (*Unk26)(void *, s32);
    /* 0x070 8006e7a0 */ void (*Unk27)(void *, s32);
    /* 0x074 8006e7a4 */ void (*Unk28)(void *);
    /* 0x078 8006e7a8 */ void (*Unk29)(void *);
    /* 0x07C 8006e7ac */ void (*Unk30)(void *);
    /* 0x080 8006e7b0 */ void (*Unk31)(void *);
    /* 0x084 8006e7b4 */ void (*Unk32)(void *);
    /* 0x088 8006e7b8 */ void (*Unk33)(void *);
    /* 0x08C 8006e7bc */ void (*Unk34)(void *);
    /* 0x090 8006e7c0 */ void (*Unk35)(void *);
    /* 0x094 8006e7c4 */ void (*Unk36)(void *);
    /* 0x098 8006e7c8 */ void (*Unk37)(void *, void (*)(), void *);
    /* 0x09C 8006e7cc */ void (*Unk38)(void *, s32);
    /* 0x0A0 8006e7d0 */ void (*Unk39)(void *, s32);
    /* 0x0A4 8006e7d4 */ void (*Unk40)(void *, char *, char *, s16 *);
    /* 0x0A8 8006e7d8 */ void (*Unk41)(void *);
    /* 0x0AC 8006e7dc */ void (*Unk42)(void *);
    /* 0x0B0 8006e7e0 */ void (*Unk43)(void *);
    /* 0x0B4 8006e7e4 */ void (*Unk44)(void *);
    /* 0x0B8 8006e7e8 */ void (*Unk45)(void *);
    /* 0x0BC 8006e7ec */ void (*Unk46)(void *);
    /* 0x0C0 8006e7f0 */ void (*Unk47)(void *);
    /* 0x0C4 8006e7f4 */ void (*Unk48)(void *);
    /* 0x0C8 8006e7f8 */ void (*Unk49)(void *);
    /* 0x0CC 8006e7fc */ void (*Unk50)(void *);
    /* 0x0D0 8006e800 */ void (*Unk51)(void *);
    /* 0x0D4 8006e804 */ void (*Unk52)(void *, char *, s32);
    /* 0x0D8 8006e808 */ void (*Unk53)(void *, s32);
    /* 0x0DC 8006e80c */ void (*Unk54)(void *);
    /* 0x0E0 8006e810 */ void (*Unk55)(void *, s32);
    /* 0x0E4 8006e814 */ void (*Unk56)(void *, char *);
    /* 0x0E8 8006e818 */ void (*Unk57)(void *);
    /* 0x0EC 8006e81c */ void (*Unk58)(void *);
    /* 0x0F0 8006e820 */ void (*Unk59)(void *, s32, s32);
    /* 0x0F4 8006e824 */ void (*Unk60)(void *);
    /* 0x0F8 8006e828 */ void (*Unk61)(void *);
    /* 0x0FC 8006e82c */ void (*Unk62)(void *);
    /* 0x100 8006e830 */ void (*Unk63)(void *, s32, s32);
    /* 0x104 8006e834 */ void (*Unk64)(void *, s32);
    /* 0x108 8006e838 */ void (*Unk65)(void *);
    /* 0x10C 8006e83c */ void (*Unk66)(void *);
    /* 0x110 8006e840 */ void (*Unk67)(void *);
    /* 0x114 8006e844 */ void (*Unk68)(void *);
    /* 0x118 8006e848 */ void (*Unk69)(void *);
    /* 0x11C 8006e84c */ void (*Unk70)(void *, s32, s32);
    /* 0x120 8006e850 */ void (*Unk71)(void *);
} class_2C694_vtable_t;

typedef struct class_2C694 {
    /* 0x00 */ class_2C694_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ u32 m_TicksPassed;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_HasIdleTimeout;
    /* 0x40 */ u32 m_TimeoutIdleTime; // Max time for idling before event occurs (menu movie plays, etc.)
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ sound_engine_t *m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 *m_Unk22;
    /* 0x60 */ s32 *m_Unk23;
    /* 0x64 */ s32 *m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s8 *m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ class_349B4_t *m_Unk29;
    /* 0x7C */ class_354D4_t *m_Unk30;
    /* 0x80 */ class_35730_t *m_Unk31;
    /* 0x84 */ s32 m_Unk32;
    /* 0x88 */ s32 (*m_Unk33)();
    /* 0x8C */ s32 (*m_Unk34)();
    /* 0x90 */ s32 m_Unk35;
    /* 0x94 */ s32 m_Unk36;
    /* 0x98 */ s32 m_Unk37;
    /* 0x9C */ void (*m_Unk38)(void *);
    /* 0xA0 */ void *m_Unk39;
    /* 0xA4 */ s32 m_Unk40;
} class_2C694_t;

class_2C694_t *func_8003BE94(u32 Unk1, u32 Unk2, u32 Unk3);
class_2C694_vtable_t *func_8003DFBC(void);

#endif