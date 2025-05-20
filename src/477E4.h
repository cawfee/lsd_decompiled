#ifndef LSD_477E4_H
#define LSD_477E4_H

#include <common.h>

typedef struct class_477E4_vtable {
    /* 0x000 800878d4 */ u32 value;
    /* 0x004 800878d8 */ void (*Destroy)(void *);
    /* 0x008 800878dc */ s32 (*Construct)(void *);
    /* 0x00C 800878e0 */ void (*Cleanup)(void *);
    /* 0x010 800878e4 */ void (*Unk3)(void *);
    /* 0x014 800878e8 */ void (*Unk4)(void *);
    /* 0x018 800878ec */ void (*Unk5)(void *);
    /* 0x01C 800878f0 */ void (*Unk6)(void *);
    /* 0x020 800878f4 */ void (*Unk7)(void *);
    /* 0x024 800878f8 */ void (*Unk8)(void *);
    /* 0x028 800878fc */ void (*Unk9)(void *);
    /* 0x02C 80087900 */ void (*Unk10)(void *);
    /* 0x030 80087904 */ void (*Unk11)(void *);
    /* 0x034 80087908 */ void (*Unk12)(void *);
    /* 0x038 8008790c */ void (*Unk13)(void *);
    /* 0x03C 80087910 */ void (*Unk14)(void *);
    /* 0x040 80087914 */ void (*Unk15)(void *);
    /* 0x044 80087918 */ void (*Unk16)(void *);
    /* 0x048 8008791c */ void (*Unk17)(void *);
    /* 0x04C 80087920 */ void (*Unk18)(void *);
    /* 0x050 80087924 */ void (*Unk19)(void *);
    /* 0x054 80087928 */ void (*Unk20)(void *);
    /* 0x058 8008792c */ void (*Unk21)(void *);
    /* 0x05C 80087930 */ void (*Unk22)(void *);
    /* 0x060 80087934 */ void (*Unk23)(void *);
    /* 0x064 80087938 */ void (*Unk24)(void *);
    /* 0x068 8008793c */ void (*Unk25)(void *);
    /* 0x06C 80087940 */ void (*Unk26)(void *);
    /* 0x070 80087944 */ void (*Unk27)(void *);
    /* 0x074 80087948 */ void (*Unk28)(void *);
    /* 0x078 8008794c */ void (*Unk29)(void *);
    /* 0x07C 80087950 */ void (*Unk30)(void *);
    /* 0x080 80087954 */ void (*Unk31)(void *);
    /* 0x084 80087958 */ void (*Unk32)(void *);
    /* 0x088 8008795c */ void (*Unk33)(void *);
    /* 0x08C 80087960 */ void (*Unk34)(void *);
    /* 0x090 80087964 */ void (*Unk35)(void *);
    /* 0x094 80087968 */ void (*Unk36)(void *);
    /* 0x098 8008796c */ void (*Unk37)(void *);
    /* 0x09C 80087970 */ void (*Unk38)(void *, void **, s32);
    /* 0x0A0 80087974 */ void (*Unk39)(void *);
    /* 0x0A4 80087978 */ void (*Unk40)(void *);
    /* 0x0A8 8008797c */ void (*Unk41)(void *);
    /* 0x0AC 80087980 */ void (*Unk42)(void *);
    /* 0x0B0 80087984 */ void (*Unk43)(void *);
    /* 0x0B4 80087988 */ void (*Unk44)(void *);
    /* 0x0B8 8008798c */ void (*Unk45)(void *);
    /* 0x0BC 80087990 */ void (*Unk46)(void *, void *);
    /* 0x0C0 80087994 */ void (*Unk47)(void *);
    /* 0x0C4 80087998 */ void (*Unk48)(void *);
    /* 0x0C8 8008799c */ void (*Unk49)(void *);
    /* 0x0CC 800879a0 */ void (*Unk50)(void *);
    /* 0x0D0 800879a4 */ void (*Unk51)(void *);
    /* 0x0D4 800879a8 */ void (*Unk52)(void *);
    /* 0x0D8 800879ac */ void (*Unk53)(void *);
    /* 0x0DC 800879b0 */ void (*Unk54)(void *, void **, s32);
    /* 0x0E0 800879b4 */ void (*Unk55)(void *);
    /* 0x0E4 800879b8 */ void (*Unk56)(void *);
    /* 0x0E8 800879bc */ void (*Unk57)(void *);
    /* 0x0EC 800879c0 */ void (*Unk58)(void *);
} class_477E4_vtable_t;

typedef struct class_477E4 {
    /* 0x00 */ class_477E4_vtable_t *vtable;
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
    /* 0x48 */ s16 m_Unk17_1;
    /* 0x4A */ s16 m_Unk17_2;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
} class_477E4_t;

class_477E4_vtable_t *func_80057C84(void);

#endif