#ifndef LSD_TIMER_H
#define LSD_TIMER_H

#include <common.h>

#include "base/base.h"

typedef struct timer timer_t;
typedef struct timer_vtable timer_vtable_t;

struct timer_vtable {
    /* 0x000 8006e878 */ u32 type_id;
    /* 0x004 8006e87c */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006e880 */ void (*Construct)(timer_t *);
    /* 0x00C 8006e884 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006e888 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006e88c */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006e890 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006e894 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006e898 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006e89c */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006e8a0 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006e8a4 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006e8a8 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006e8ac */ void (*Nop)(base_class_t *);
    /* 0x038 8006e8b0 */ void (*OnNotify)(timer_t *, base_class_t *, s32);
    /* 0x03C 8006e8b4 */ void (*Unused1)();
    /* 0x040 8006e8b8 */ void (*Reset)(timer_t *);
    /* 0x044 8006e8bc */ void (*Unk16)(timer_t *, s32 *, s32);
    /* 0x048 8006e8c0 */ void (*Unk17)(timer_t *);
    /* 0x04C 8006e8c4 */ void (*Unk18)(timer_t *, s32, s32, s32);
    /* 0x050 8006e8c8 */ void (*Unk19)(timer_t *);
    /* 0x054 8006e8cc */ void (*Unk20)(timer_t *, base_class_t *, s32);
    /* 0x058 8006e8d0 */ void (*Unk21)(timer_t *, base_class_t *, s32);
    /* 0x05C 8006e8d4 */ void (*Increment)(timer_t *, base_class_t *, s32);
    /* 0x060 8006e8d8 */ void (*Unk23)(timer_t *, s32);
    /* 0x064 8006e8dc */ void (*Unk24)(timer_t *);
    /* 0x068 8006e8e0 */ void (*Unk25)(timer_t *);
};

struct timer {
    /* 0x00 */ timer_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ void *m_Unk3;
    /* 0x14 */ void *m_Unk4;
    /* 0x18 */ void *m_Unk5;
    /* 0x1C */ s32 m_TicksPassed;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
};

void timer_create(timer_t *This);
void timer_on_notify(timer_t *This, base_class_t *Sender, s32 Code);
void timer_reset(timer_t *This);
void func_8003E10C(timer_t *This, s32 *Unk2, s32 Unk3);
void func_8003E280(timer_t *This);
void func_8003E418(timer_t *This, base_class_t *Sender, s32 Code);
void timer_increment(timer_t *This, base_class_t *Sender, s32 Code);
void func_8003E4B8(timer_t *This, s32 Unk2);
void timer_begin_frame(timer_t *This);
void timer_end_frame(timer_t *This);
timer_vtable_t *timer_get_vtable(void);

#endif
