#ifndef LSD_305B0_H
#define LSD_305B0_H

#include "common.h"

typedef struct class_305B0 class_305B0_t;
typedef struct entity entity_t;

typedef struct class_305B0_vtable {
    /* 0x000 8006e99c */ u32 value;
    /* 0x004 8006e9a0 */ void (*Destroy)(class_305B0_t *);
    /* 0x008 8006e9a4 */ void (*Construct)(class_305B0_t *, s32, s32, s32);
    /* 0x00C 8006e9a8 */ void (*Cleanup)(class_305B0_t *);
    /* 0x010 8006e9ac */ void (*Unk3)(class_305B0_t *);
    /* 0x014 8006e9b0 */ void (*Unk4)(class_305B0_t *);
    /* 0x018 8006e9b4 */ void (*Unk5)(class_305B0_t *);
    /* 0x01C 8006e9b8 */ void (*Unk6)(class_305B0_t *);
    /* 0x020 8006e9bc */ void (*Unk7)(class_305B0_t *);
    /* 0x024 8006e9c0 */ void (*Unk8)(class_305B0_t *);
    /* 0x028 8006e9c4 */ void (*Unk9)(class_305B0_t *);
    /* 0x02C 8006e9c8 */ void (*Unk10)(class_305B0_t *);
    /* 0x030 8006e9cc */ void (*Unk11)(class_305B0_t *);
    /* 0x034 8006e9d0 */ void (*Unk12)(class_305B0_t *);
    /* 0x038 8006e9d4 */ void (*Unk13)(class_305B0_t *);
    /* 0x03C 8006e9d8 */ void (*Unk14)(class_305B0_t *);
    /* 0x040 8006e9dc */ void (*Unk15)(class_305B0_t *, s32);
    /* 0x044 8006e9e0 */ void (*Unk16)(class_305B0_t *);
    /* 0x048 8006e9e4 */ void (*Unk17)(class_305B0_t *);
    /* 0x04C 8006e9e8 */ void (*Unk18)(class_305B0_t *, entity_t *, s32);
    /* 0x050 8006e9ec */ void (*Unk19)(class_305B0_t *);
    /* 0x054 8006e9f0 */ void (*Unk20)(class_305B0_t *);
    /* 0x058 8006e9f4 */ void (*Unk21)(class_305B0_t *);
    /* 0x05C 8006e9f8 */ void (*Unk22)(class_305B0_t *);
    /* 0x060 8006e9fc */ void (*Unk23)(class_305B0_t *, s32);
    /* 0x064 8006ea00 */ void (*Unk24)(class_305B0_t *, s32);
    /* 0x068 8006ea04 */ void (*Unk25)(class_305B0_t *);
    /* 0x06C 8006ea08 */ void (*Unk26)(class_305B0_t *);
    /* 0x070 8006ea0c */ void (*Unk27)(class_305B0_t *);
    /* 0x074 8006ea10 */ void (*Unk28)(class_305B0_t *);
    /* 0x078 8006ea14 */ void (*Unk29)(class_305B0_t *);
    /* 0x07C 8006ea18 */ void (*Unk30)(class_305B0_t *);
    /* 0x080 8006ea1c */ void (*Unk31)(class_305B0_t *);
    /* 0x084 8006ea20 */ void (*Unk32)(class_305B0_t *);
    /* 0x088 8006ea24 */ void (*Unk33)(class_305B0_t *);
    /* 0x08C 8006ea28 */ void (*Unk34)(class_305B0_t *);
    /* 0x090 8006ea2c */ void (*Unk35)(class_305B0_t *);
    /* 0x094 8006ea30 */ void (*Unk36)(class_305B0_t *);
    /* 0x098 8006ea34 */ void (*Unk37)(class_305B0_t *);
    /* 0x09C 8006ea38 */ void (*Unk38)(class_305B0_t *);
    /* 0x0A0 8006ea3c */ void (*Unk39)(class_305B0_t *);
    /* 0x0A4 8006ea40 */ void (*Unk40)(class_305B0_t *);
    /* 0x0A8 8006ea44 */ void (*Unk41)(class_305B0_t *);
    /* 0x0AC 8006ea48 */ void (*Unk42)(class_305B0_t *);
    /* 0x0B0 8006ea4c */ void (*Unk43)(class_305B0_t *);
    /* 0x0B4 8006ea50 */ void (*Unk44)(class_305B0_t *);
    /* 0x0B8 8006ea54 */ void (*Unk45)(class_305B0_t *);
    /* 0x0BC 8006ea58 */ void (*Unk46)(class_305B0_t *);
    /* 0x0C0 8006ea5c */ void (*Unk47)(class_305B0_t *);
    /* 0x0C4 8006ea60 */ void (*Unk48)(class_305B0_t *);
    /* 0x0C8 8006ea64 */ void (*Unk49)(class_305B0_t *);
    /* 0x0CC 8006ea68 */ void (*Unk50)(class_305B0_t *);
    /* 0x0D0 8006ea6c */ void (*Unk51)(class_305B0_t *, s32);
    /* 0x0D4 8006ea70 */ void (*Unk52)(class_305B0_t *);
    /* 0x0D8 8006ea74 */ void (*Unk53)(class_305B0_t *);
    /* 0x0DC 8006ea78 */ void (*Unk54)(class_305B0_t *);
    /* 0x0E0 8006ea7c */ void (*Unk55)(class_305B0_t *, s32);
    /* 0x0E4 8006ea80 */ void (*Unk56)(class_305B0_t *);
    /* 0x0E8 8006ea84 */ void (*Unk57)(class_305B0_t *);
    /* 0x0EC 8006ea88 */ void (*Unk58)(class_305B0_t *);
    /* 0x0F0 8006ea8c */ void (*Unk59)(class_305B0_t *);
} class_305B0_vtable_t;

typedef struct class_305B0 {
    /* 0x00 */ class_305B0_vtable_t *vtable;
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
} class_305B0_t;

class_305B0_t *class_305B0_create(s32 Unk1, s32 Unk2, s32 Unk3);
class_305B0_vtable_t *class_305B0_get_vtable();

#endif // LSD_305B0_H