#ifndef LSD_32C00_H
#define LSD_32C00_H

#include <common.h>

typedef struct class_32C00_vtable {
    /* 0x000 8006ef50 */ u32 value;
    /* 0x004 8006ef54 */ void (*Destroy)(void *);
    /* 0x008 8006ef58 */ void (*Construct)(void *);
    /* 0x00C 8006ef5c */ void (*Cleanup)(void *);
    /* 0x010 8006ef60 */ void (*Unk3)(void *);
    /* 0x014 8006ef64 */ void (*Unk4)(void *);
    /* 0x018 8006ef68 */ void (*Unk5)(void *);
    /* 0x01C 8006ef6c */ void (*Unk6)(void *);
    /* 0x020 8006ef70 */ void (*Unk7)(void *);
    /* 0x024 8006ef74 */ void (*Unk8)(void *);
    /* 0x028 8006ef78 */ void (*Unk9)(void *);
    /* 0x02C 8006ef7c */ void (*Unk10)(void *);
    /* 0x030 8006ef80 */ void (*Unk11)(void *, s32);
    /* 0x034 8006ef84 */ void (*Unk12)(void *);
    /* 0x038 8006ef88 */ void (*Unk13)(void *);
    /* 0x03C 8006ef8c */ void (*Unk14)(void *);
    /* 0x040 8006ef90 */ void (*Unk15)(void *, s32);
    /* 0x044 8006ef94 */ void (*Unk16)(void *);
    /* 0x048 8006ef98 */ void (*Unk17)(void *);
    /* 0x04C 8006ef9c */ void (*Unk18)(void *);
    /* 0x050 8006efa0 */ void (*Unk19)(void *);
    /* 0x054 8006efa4 */ void (*Unk20)(void *);
    /* 0x058 8006efa8 */ void (*Unk21)(void *);
} class_32C00_vtable_t;

typedef struct class_32C00 {
    /* 0x00 */ class_32C00_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
} class_32C00_t;

class_32C00_t *func_80042400(void);
class_32C00_vtable_t *func_80042684(void);

#endif