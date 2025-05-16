#ifndef LSD_171F0_H
#define LSD_171F0_H

#include <common.h>

typedef struct class_171F0_vtable {
    /* 0x000 8006d430 */ u32 value;
    /* 0x004 8006d434 */ void (*Destroy)(void *);
    /* 0x008 8006d438 */ void (*Construct)(void *);
    /* 0x00C 8006d43c */ void (*Cleanup)();
    /* 0x010 8006d440 */ void (*Unk3)(void *);
    /* 0x014 8006d444 */ void (*Unk4)(void *);
    /* 0x018 8006d448 */ void (*Unk5)(void *);
    /* 0x01C 8006d44c */ void (*Unk6)(void *);
    /* 0x020 8006d450 */ void (*Unk7)(void *);
    /* 0x024 8006d454 */ void (*Unk8)(void *);
    /* 0x028 8006d458 */ void (*Unk9)(void *);
    /* 0x02C 8006d45c */ void (*Unk10)(void *);
    /* 0x030 8006d460 */ void (*Unk11)(void *);
    /* 0x034 8006d464 */ void (*Unk12)(void *);
    /* 0x038 8006d468 */ void (*Unk13)(void *);
    /* 0x03C 8006d46c */ void (*Unk14)(void *);
    /* 0x040 8006d470 */ void (*Unk15)(void *);
    /* 0x044 8006d474 */ void (*Unk16)(void *, s32, s32, s32);
    /* 0x048 8006d478 */ void (*Unk17)(void *);
    /* 0x04C 8006d47c */ s32 (*Unk18)(void *, s32, s32);
    /* 0x050 8006d480 */ void (*Unk19)(void *);
    /* 0x054 8006d484 */ void (*Unk20)(void *, void *, s32);
    /* 0x058 8006d488 */ void (*Unk21)(void *);
    /* 0x05C 8006d48c */ void (*Unk22)(void *);
    /* 0x060 8006d490 */ void (*Unk23)(void *);
    /* 0x064 8006d494 */ void (*Unk24)(void *);
    /* 0x068 8006d498 */ void (*Unk25)(void *);
} class_171F0_vtable_t;

typedef struct class_171F0 {
    /* 0x00 */ class_171F0_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    s32 m_Unk2;
    void *m_Buffer;
    s32 m_Unk4;
    s32 m_Unk5;
    s32 m_Unk6;
    u16 m_Unk7_1;
    s16 m_Unk7_2;
    s32 m_Unk8;
    s16 m_Unk9;
    s16 m_Unk10;
} class_171F0_t;

void *func_80026CAC();
class_171F0_vtable_t *func_80026C9C(void);

#endif