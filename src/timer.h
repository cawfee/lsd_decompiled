#ifndef LSD_TIMER_H
#define LSD_TIMER_H

#include <common.h>

typedef struct timer_vtable {
    /* 0x000 8006e878 */ u32 value;
    /* 0x004 8006e87c */ void (*Destroy)(void *);
    /* 0x008 8006e880 */ void (*Construct)(void *);
    /* 0x00C 8006e884 */ void (*Cleanup)(void *);
    /* 0x010 8006e888 */ void (*Unk3)(void *);
    /* 0x014 8006e88c */ void (*Unk4)(void *);
    /* 0x018 8006e890 */ void (*Unk5)(void *);
    /* 0x01C 8006e894 */ void (*Unk6)(void *);
    /* 0x020 8006e898 */ void (*Unk7)(void *);
    /* 0x024 8006e89c */ void (*Unk8)(void *);
    /* 0x028 8006e8a0 */ void (*Unk9)(void *);
    /* 0x02C 8006e8a4 */ void (*Unk10)(void *);
    /* 0x030 8006e8a8 */ void (*Unk11)(void *);
    /* 0x034 8006e8ac */ void (*Unk12)(void *);
    /* 0x038 8006e8b0 */ void (*Unk13)(void *);
    /* 0x03C 8006e8b4 */ u32 pad;
    /* 0x040 8006e8b8 */ void (*Unk15)(void *);
    /* 0x044 8006e8bc */ void (*Unk16)(void *, s32, s32);
    /* 0x048 8006e8c0 */ void (*Unk17)(void *);
    /* 0x04C 8006e8c4 */ u32 pad2;
    /* 0x050 8006e8c8 */ void (*Unk19)(void *);
    /* 0x054 8006e8cc */ void (*Unk20)(void *, void **, s32);
    /* 0x058 8006e8d0 */ void (*Unk21)(void *, void **, s32);
    /* 0x05C 8006e8d4 */ void (*Increment)(void *, void **, s32);
    /* 0x060 8006e8d8 */ void (*Unk23)(void *, s32);
    /* 0x064 8006e8dc */ void (*Unk24)(void *);
    /* 0x068 8006e8e0 */ void (*Unk25)(void *);
} timer_vtable_t;

typedef struct timer {
    /* 0x00 */ timer_vtable_t *vtable;
    // TODO real count unknown
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_TicksPassed;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
} timer_t;

timer_vtable_t *timer_get_vtable(void);

#endif