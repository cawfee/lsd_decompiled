#ifndef LSD_MEMORY_CARD_H
#define LSD_MEMORY_CARD_H

typedef struct memory_card_vtable {
    /* 0x000 80086dc4 */ u32 value;
    /* 0x004 80086dc8 */ void (*Destroy)(void *);
    /* 0x008 80086dcc */ void (*Construct)(void *, s32, s32);
    /* 0x00C 80086dd0 */ void (*Cleanup)(void *);
    /* 0x010 80086dd4 */ void (*Unk3)(void *, void *);
    /* 0x014 80086dd8 */ void (*Unk4)(void *, void *);
    /* 0x018 80086ddc */ void (*Unk5)(void *);
    /* 0x01C 80086de0 */ void (*Unk6)(void *, void *, void **);
    /* 0x020 80086de4 */ void (*Unk7)(void *, void *);
    /* 0x024 80086de8 */ void (*Unk8)(void *, void *);
    /* 0x028 80086dec */ void (*Unk9)(void *);
    /* 0x02C 80086df0 */ void (*Unk10)(void *, void *, void **);
    /* 0x030 80086df4 */ void (*Unk11)(void *);
    /* 0x034 80086df8 */ void (*Unk12)(void *);
    /* 0x038 80086dfc */ void (*Unk13)(void *, void *, void *);
    /* 0x03C 80086e00 */ u32 pad;
    /* 0x040 80086e04 */ void (*Unk15)(void *);
    /* 0x044 80086e08 */ void (*Unk16)(void *);
    /* 0x048 80086e0c */ void (*Unk17)(void *);
    /* 0x04C 80086e10 */ void (*Unk18)(void *);
    /* 0x050 80086e14 */ void (*Unk19)(void *);
    /* 0x054 80086e18 */ void (*Unk20)(void *);
    /* 0x058 80086e1c */ void (*Unk21)(void *);
    /* 0x05C 80086e20 */ void (*Unk22)(void *);
    /* 0x060 80086e24 */ void (*Unk23)(void *);
    /* 0x064 80086e28 */ void (*Unk24)(void *);
    /* 0x068 80086e2c */ void (*Unk25)(void *);
    /* 0x06C 80086e30 */ void (*Unk26)(void *, char **, char **, void *, s32, s32, s32);
    /* 0x070 80086e34 */ void (*Unk27)(void *);
    /* 0x074 80086e38 */ void (*Unk28)(void *, char *, char *, char *, s32);
    /* 0x078 80086e3c */ void (*Unk29)(void *, char *, char *, s32, s32, s32, char *, s32);
    /* 0x07C 80086e40 */ void (*Unk30)(void *, s32);
    /* 0x080 80086e44 */ void (*Unk31)(void *);
    /* 0x084 80086e48 */ void (*Unk32)(void *);
    /* 0x088 80086e4c */ void (*Unk33)(void *);
    /* 0x08C 80086e50 */ void (*Unk34)(void *);
    /* 0x090 80086e54 */ void (*Unk35)(void *);
    /* 0x094 80086e58 */ void (*Unk36)(void *);
    /* 0x098 80086e5c */ void (*Unk37)(void *);
    /* 0x09C 80086e60 */ void (*Unk38)(void *);
    /* 0x0A0 80086e64 */ void (*Unk39)(void *);
    /* 0x0A4 80086e68 */ void (*Unk40)(void *);
    /* 0x0A8 80086e6c */ void (*Unk41)(void *);
    /* 0x0AC 80086e70 */ void (*Unk42)(void *);
    /* 0x0B0 80086e74 */ void (*Unk43)(void *);
} memory_card_vtable_t;

typedef struct memory_card {
    /* 0x00 */ memory_card_vtable_t *vtable;
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
    /* 0x60 */ void *m_Unk23;
    /* 0x64 */ void *m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ void *m_Unk29;
    /* 0x7C */ void *m_Unk30;
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_Unk32;
} memory_card_t;

memory_card_vtable_t *memory_card_get_vtable(void);

#endif