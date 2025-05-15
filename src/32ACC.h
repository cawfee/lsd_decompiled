#ifndef LSD_32ACC_H
#define LSD_32ACC_H

#include <common.h>

typedef struct class_32ACC_vtable {
    /* 0x000 8006eed8 */ u32 value;
    /* 0x004 8006eedc */ void (*Destroy)(void *);
    /* 0x008 8006eee0 */ void (*Construct)(void *, s32);
    /* 0x00C 8006eee4 */ void (*Cleanup)(void *);
    /* 0x010 8006eee8 */ void (*Unk3)(void *);
    /* 0x014 8006eeec */ void (*Unk4)(void *);
    /* 0x018 8006eef0 */ void (*Unk5)(void *);
    /* 0x01C 8006eef4 */ void (*Unk6)(void *);
    /* 0x020 8006eef8 */ void (*Unk7)(void *);
    /* 0x024 8006eefc */ void (*Unk8)(void *);
    /* 0x028 8006ef00 */ void (*Unk9)(void *);
    /* 0x02C 8006ef04 */ void (*Unk10)(void *);
    /* 0x030 8006ef08 */ void (*Unk11)(void *);
    /* 0x034 8006ef0c */ void (*Unk12)(void *);
    /* 0x038 8006ef10 */ void (*Unk13)(void *);
    /* 0x03C 8006ef14 */ u32 pad1;
    /* 0x040 8006ef18 */ u32 pad2;
    /* 0x044 8006ef1c */ u32 pad3;
    /* 0x048 8006ef20 */ u32 pad4;
    /* 0x04C 8006ef24 */ u32 pad5;
    /* 0x050 8006ef28 */ u32 pad6;
    /* 0x054 8006ef2c */ u32 pad7;
    /* 0x058 8006ef30 */ u32 pad8;
    /* 0x05C 8006ef34 */ void (*Unk22)(void *);
    /* 0x060 8006ef38 */ void (*Unk23)(void *);
    /* 0x064 8006ef3c */ void (*Unk24)(void *);
    /* 0x068 8006ef40 */ u32 pad9;
    /* 0x068 8006ef44 */ u32 pad10;
    /* 0x068 8006ef48 */ u32 pad11;
    /* 0x068 8006ef4C */ u32 pad12;
} class_32ACC_vtable_t;

typedef struct class_32ACC {
    /* 0x00 */ class_32ACC_vtable_t *vtable;
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
} class_32ACC_t;

class_32ACC_vtable_t *func_800423F0(void);

#endif