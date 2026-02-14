#ifndef LSD_RENDERER_H
#define LSD_RENDERER_H

#include <common.h>

typedef struct renderer_vtable {
    /* 0x000 8006e8e4 */ u32 value;
    /* 0x004 8006e8e8 */ void (*Destroy)(void *);
    /* 0x008 8006e8ec */ void (*Construct)(void *);
    /* 0x00C 8006e8f0 */ void (*Cleanup)(void *);
    /* 0x010 8006e8f4 */ void (*Unk3)(void *);
    /* 0x014 8006e8f8 */ void (*Unk4)(void *, s32);
    /* 0x018 8006e8fc */ void (*Unk5)(void *);
    /* 0x01C 8006e900 */ void (*Unk6)(void *);
    /* 0x020 8006e904 */ void (*Unk7)(void *);
    /* 0x024 8006e908 */ void (*Unk8)(void *);
    /* 0x028 8006e90c */ void (*Unk9)(void *);
    /* 0x02C 8006e910 */ void (*Unk10)(void *);
    /* 0x030 8006e914 */ void (*Unk11)(void *);
    /* 0x034 8006e918 */ void (*Unk12)(void *);
    /* 0x038 8006e91c */ void (*Unk13)(void *);
    /* 0x03C 8006e920 */ void (*Unk14)(void *);
    /* 0x040 8006e924 */ void (*Unk15)(void *);
    /* 0x044 8006e928 */ void (*Unk16)(void *);
    /* 0x048 8006e92c */ void (*Unk17)(void *);
    /* 0x04C 8006e930 */ void (*Unk18)(void *);
    /* 0x050 8006e934 */ void (*Unk19)(void *);
    /* 0x054 8006e938 */ void (*Unk20)(void *);
    /* 0x058 8006e93c */ void (*Unk21)(void *);
    /* 0x05C 8006e940 */ void (*Unk22)(void *);
    /* 0x060 8006e944 */ void (*Unk23)(void *);
    /* 0x064 8006e948 */ void (*Unk24)(void *);
    /* 0x068 8006e94c */ void (*Unk25)(void *);
    /* 0x06C 8006e950 */ void (*Unk26)(void *);
    /* 0x070 8006e954 */ void (*Unk27)(void *);
    /* 0x074 8006e958 */ void (*Unk28)(void *);
    /* 0x078 8006e95c */ void (*Unk29)(void *);
    /* 0x07C 8006e960 */ void (*Unk30)(void *);
    /* 0x080 8006e964 */ void (*Unk31)(void *);
    /* 0x084 8006e968 */ void (*Unk32)(void *);
    /* 0x088 8006e96c */ void (*Unk33)(void *);
    /* 0x08C 8006e970 */ void (*Unk34)(void *);
    /* 0x090 8006e974 */ void (*Unk35)(void *);
    /* 0x094 8006e978 */ void (*Unk36)(void *);
    /* 0x098 8006e97c */ void (*Unk37)(void *);
    /* 0x09C 8006e980 */ void (*Unk38)(void *);
    /* 0x0A0 8006e984 */ void (*Unk39)(void *);
    /* 0x0A4 8006e988 */ void (*Unk40)(void *, s32);
    /* 0x0A8 8006e98c */ void (*Unk41)(void *);
    /* 0x0AC 8006e990 */ void (*Unk42)(void *);
    /* 0x0B0 8006e994 */ void (*Unk43)(void *);
    /* 0x0B4 8006e998 */ void (*Unk44)(void *);
    /* 0x0B8 8006e99c */ void (*Unk45)(void *);
} renderer_vtable_t;

typedef struct renderer {
    /* 0x00 */ renderer_vtable_t *vtable;
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
    /* 0x34 */ s32 m_Unk12[2];
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ void (*m_Unk15)(void);
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s8 m_Unk21[8];
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
} renderer_t;

renderer_vtable_t *renderer_get_vtable(void);

#endif