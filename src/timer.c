#include "timer.h"
#include "base_class.h"
#include "32C00.h"
#include "32E94.h"
#include "renderer.h"

extern timer_vtable_t **g_TIMER_VTABLE;
extern class_32E94_t *func_80042694(void);
extern renderer_t *renderer_create(void);

void timer_create(timer_t *This) {
    base_class_get_vtable()->Construct(This);

    This->vtable = timer_get_vtable();
    This->vtable->Unk15(This);
}

void func_8003E030(timer_t *This, void **Unk2, void *Unk3) {
    u32 value;
    base_class_get_vtable()->Unk13(This, Unk2, Unk3);

    value = *(u32 *) *Unk2 & 0xF;

    if (value == 1) {
        This->vtable->Unk20(This, Unk2, Unk3);
    } else if (value == 2) {
        This->vtable->Unk21(This, Unk2, Unk3);
    } else if (value == 5) {
        This->vtable->Increment(This, Unk2, Unk3);
    }
}

void timer_reset(timer_t *This) {
    This->m_TicksPassed = 0;
    This->m_Unk7 = 0;
}

void func_8003E10C(timer_t *This, s32 *Unk2, s32 Unk3) {
    s32 value;
    timer_vtable_t *vtable;
    s32 m_Unk5;

    value = Unk2[2];
    vtable = This->vtable;
    if (value == 0) {
        value = (s32) func_80042400();
    }
    This->m_Unk3 = value;

    value = Unk2[3];
    if (value == 0) {
        value = (s32) func_80042694();
    }
    This->m_Unk4 = value;

    value = Unk2[4];
    if (value == 0) {
        value = (s32) renderer_create();
    }
    This->m_Unk5 = value;

    This->m_Unk2 = (s32) Unk2;
    m_Unk5 = This->m_Unk5;
    vtable->Unk3(This, Unk2[0]);
    vtable->Unk3(This, Unk2[1]);
    vtable->Unk3(This, This->m_Unk3);
    vtable->Unk18(This, 0, 0, 0);
    This->m_Unk8 = Unk3;
    if (Unk3 == 0) {
        (*(void (**)(s32, s32))(*(s32 *) m_Unk5 + 0x10))(m_Unk5, Unk2[0]);
        (*(void (**)(s32, s32))(*(s32 *) m_Unk5 + 0x10))(m_Unk5, This->m_Unk3);
        (*(void (**)(s32, s32))(*(s32 *) This->m_Unk4 + 0x10))(This->m_Unk4, This->m_Unk3);
        vtable->Unk23(This, 2);
        vtable->Unk17(This);
    }
}

void func_8003E280(timer_t *This) {
    timer_vtable_t *vtable;
    s32 m_Unk8;
    s32 m_Unk5;
    s32 m_Unk4;
    s32 m_Unk3;

    vtable = This->vtable;
    vtable->Unk19(This);
    m_Unk8 = This->m_Unk8;
    m_Unk5 = This->m_Unk5;
    if (m_Unk8 == 0) {
        (*(void (**)(s32, s32))(*(s32 *) This->m_Unk4 + 0x14))(This->m_Unk4, This->m_Unk3);
        (*(void (**)(s32, s32))(*(s32 *) m_Unk5 + 0x14))(m_Unk5, This->m_Unk3);
        (*(void (**)(s32, s32))(*(s32 *) m_Unk5 + 0x14))(m_Unk5, *(s32 *) This->m_Unk2);
    }
    vtable->Unk4(This, This->m_Unk3);
    vtable->Unk4(This, *(s32 *) (This->m_Unk2 + 4));
    vtable->Unk4(This, *(s32 *) This->m_Unk2);
    if (*(s32 *) (This->m_Unk2 + 0x10) != m_Unk5) {
        This->m_Unk5 = (*(s32 (**)(s32))(*(s32 *) m_Unk5 + 4))(m_Unk5);
    }
    m_Unk4 = This->m_Unk4;
    if (*(s32 *) (This->m_Unk2 + 0xC) != m_Unk4) {
        This->m_Unk4 = (*(s32 (**)(s32))(*(s32 *) m_Unk4 + 4))(m_Unk4);
    }
    m_Unk3 = This->m_Unk3;
    if (*(s32 *) (This->m_Unk2 + 8) != m_Unk3) {
        This->m_Unk3 = (*(s32 (**)(s32))(*(s32 *) m_Unk3 + 4))(m_Unk3);
    }
}

void func_8003E418(timer_t *This, s32 Unk2, s32 Unk3) {
    s32 obj;

    if (Unk3 == 2) {
        (*(void (**)(s32))(*(s32 *) This->m_Unk3 + 0x44))(This->m_Unk3);
        obj = *(s32 *) (This->m_Unk2 + 4);
        (*(void (**)(s32))(*(s32 *) obj + 0x44))(obj);
        (*(void (**)(s32))(*(s32 *) obj + 0x48))(obj);
    }
}

// Increment the timer by 1 tick
void timer_increment(timer_t *This, void **Unk2, s32 Unk3) {
    This->m_TicksPassed++;
}

void func_8003E4B8(timer_t *This, s32 Unk2) {
    timer_vtable_t *vtable;
    void (*fn)(void *);

    vtable = This->vtable;
    This->m_Unk7 = Unk2;
    vtable->Unk11(This, Unk2);
    if (Unk2 == 2) {
        fn = vtable->Unk24;
        goto do_call;
    }
    if (Unk2 == 3) {
        fn = vtable->Unk25;
    do_call:
        fn(This);
    }
}

void func_8003E538(timer_t *This) {
    u32 *m_Unk2;

    m_Unk2 = (u32 *) This->m_Unk2;
    This->m_TicksPassed = 0;
    (*(int (**)(u32))(*(u32 *) *m_Unk2 + 72))(*m_Unk2);
}

void func_8003E578(timer_t *This) {
    (*(void (**)(u32))(**(u32 **) This->m_Unk2 + 76))(*(u32 *) This->m_Unk2);
    This->m_TicksPassed = 0;
}

timer_vtable_t *timer_get_vtable(void) {
    return &g_TIMER_VTABLE;
}
