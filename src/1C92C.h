#ifndef LSD_1C92C_H
#define LSD_1C92C_H

typedef struct class_1C92C_vtable {
    /* 0x000 8006d940 */ u32 value;
    /* 0x004 8006d944 */ void (*Destroy)(void *);
    /* 0x008 8006d948 */ void (*Construct)(void *, s32);
    /* 0x00C 8006d94c */ void (*Cleanup)(void *);
    /* 0x010 8006d950 */ void (*Unk3)(void *);
    /* 0x014 8006d954 */ void (*Unk4)(void *);
    /* 0x018 8006d958 */ void (*Unk5)(void *);
    /* 0x01C 8006d95c */ void (*Unk6)(void *);
    /* 0x020 8006d960 */ void (*Unk7)(void *);
    /* 0x024 8006d964 */ void (*Unk8)(void *);
    /* 0x028 8006d968 */ void (*Unk9)(void *);
    /* 0x02C 8006d96c */ void (*Unk10)(void *);
    /* 0x030 8006d970 */ void (*Unk11)(void *);
    /* 0x034 8006d974 */ void (*Unk12)(void *);
    /* 0x038 8006d978 */ void (*Unk13)(void *);
    /* 0x03C 8006d97c */ void (*Unk14)(void *);
    /* 0x040 8006d980 */ void (*Unk15)(void *);
    /* 0x044 8006d984 */ void (*Unk16)(void *);
    /* 0x048 8006d988 */ void (*Unk17)(void *);
    /* 0x04C 8006d98c */ void (*Unk18)(void *);
    /* 0x050 8006d990 */ void (*Unk19)(void *);
    /* 0x054 8006d994 */ void (*Unk20)(void *);
    /* 0x058 8006d998 */ void (*Unk21)(void *);
    /* 0x05C 8006d99c */ void (*Unk22)(void *);
    /* 0x060 8006d9a0 */ void (*Unk23)(void *);
    /* 0x064 8006d9a4 */ void (*Unk24)(void *);
    /* 0x068 8006d9a8 */ void (*Unk25)(void *);
    /* 0x06C 8006d9ac */ void (*Unk26)(void *, s32);
    /* 0x070 8006d9b0 */ void (*Unk27)(void *);
    /* 0x074 8006d9b4 */ void (*Unk28)(void *);
    /* 0x078 8006d9b8 */ void (*Unk29)(void *);
} class_1C92C_vtable_t;

typedef struct class_1C92C {
    /* 0x00 */ class_1C92C_vtable_t *vtable;
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
} class_1C92C_t;

class_1C92C_vtable_t *class_1C92C_get_vtable(void);

#endif