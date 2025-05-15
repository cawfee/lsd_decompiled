#include "timer.h"
#include "base_class.h"

extern timer_vtable_t **g_TIMER_VTABLE;

void timer_create(timer_t *This) {
    base_class_get_vtable()->Construct(This);

    This->vtable = timer_get_vtable();
    This->vtable->Unk15(This);
}

void func_8003E030(timer_t *This, void **Unk2, void *Unk3) {
    u32 value;
    base_class_get_vtable()->Unk13(This, Unk2, Unk3);

    value = *(u32 *)*Unk2 & 0xF;

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

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E10C);

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E280);

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E418);

// Increment the timer by 1 tick
void timer_increment(timer_t *This) {
    This->m_TicksPassed++;
}

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E4B8);

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E538);

INCLUDE_ASM("asm/nonmatchings/timer", func_8003E578);

timer_vtable_t *timer_get_vtable(void) {
    return &g_TIMER_VTABLE;
}
