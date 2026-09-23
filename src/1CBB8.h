#ifndef LSD_1CBB8_H
#define LSD_1CBB8_H

#include <common.h>

typedef struct class_1CBB8_vtable {
    /* 0x000 8006d9bc */ u32 value;
    /* 0x004 8006d9c0 */ void (*init_800269F0)(void *);
    /* 0x008 8006d9c4 */ void (*class_1CBB8_construct)(void *);
    /* 0x00C 8006d9c8 */ void (*class_1CBB8_cleanup)(void *);
    /* 0x010 8006d9cc */ void (*Unk3)(void *);
    /* 0x014 8006d9d0 */ void (*Unk4)(void *);
    /* 0x018 8006d9d4 */ void (*Unk5)(void *);
    /* 0x01C 8006d9d8 */ void (*Unk6)(void *);
    /* 0x020 8006d9dc */ void (*Unk7)(void *);
    /* 0x024 8006d9e0 */ void (*Unk8)(void *);
    /* 0x028 8006d9e4 */ void (*Unk9)(void *);
    /* 0x02C 8006d9e8 */ void (*Unk10)(void *);
    /* 0x030 8006d9ec */ void (*Unk11)(void *);
    /* 0x034 8006d9f0 */ void (*Unk12)(void *);
    /* 0x038 8006d9f4 */ void (*Unk13)(void *);
    /* 0x03C 8006d9f8 */ void (*Unk14)(void *);
    /* 0x040 8006d9fc */ void (*class_1CBB8_unk15)(void *);
    /* 0x044 8006da00 */ void (*class_1CBB8_unk16)(void *);
    /* 0x048 8006da04 */ void (*class_1CBB8_unk17)(void *);
    /* 0x04C 8006da08 */ void (*class_1CBB8_unk18)(void *);
    /* 0x050 8006da0c */ void (*class_1CBB8_unk19)(void *);
    /* 0x054 8006da10 */ void (*class_1CBB8_unk20)(void *);
    /* 0x058 8006da14 */ void (*class_1CBB8_unk21)(void *);
    /* 0x05C 8006da18 */ void (*file_buf_release)(void *);
    /* 0x060 8006da1c */ void (*Unk23)(void *);
    /* 0x064 8006da20 */ void (*Unk24)(void *);
    /* 0x068 8006da24 */ void (*class_1CBB8_unk25)(void *);
    /* 0x06C 8006da28 */ void (*class_1CBB8_unk26)(void *);
    /* 0x070 8006da2c */ void (*class_1CBB8_unk27)(void *);
    /* 0x074 8006da30 */ void (*class_1CBB8_unk28)(void *);
} class_1CBB8_vtable_t;

typedef struct class_1CBB8 {
    /* 0x00 */ class_1CBB8_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
} class_1CBB8_t;

class_1CBB8_vtable_t *class_1CBB8_get_vtable(void);

#endif