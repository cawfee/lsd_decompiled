#include "3A930.h"

#include "timer.h"

extern class_3A930_vtable_t **D_80086668;

class_3A930_t *func_8004A130(u32 Unk1, u32 Unk2) {
    class_3A930_t *allocated = (class_3A930_t *) memory_allocate_mem(0x38);

    if (allocated) {
        func_8004A4B8()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_8004A19C(class_3A930_t *This, void *Unk2, sound_engine_vtable_t *SoundEngine) {
    timer_get_vtable()->Construct(This);
    This->vtable = func_8004A4B8();

    if (Unk2) {
        This->m_SoundEngine = sound_engine_create(Unk2);
    } else {
        This->m_SoundEngine = SoundEngine;
    }

    This->m_Unk11 = Unk2;
    This->vtable->Unk15(This);
}

void func_8004A228(class_3A930_t *This) {
    if (This->m_Unk11) {
        This->m_SoundEngine->vtable->Destruct(This->m_SoundEngine);
    }

    timer_get_vtable()->Cleanup(This);
}

void func_8004A294(class_3A930_t *This) {
    This->vtable->Unk26(This, -1);
}

s32 func_8004A2C4(class_3A930_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk9 = 0;
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk9;
}

void func_8004A324(class_3A930_t *This) {
    timer_get_vtable()->Unk17(This);
}

void func_8004A35C(void) {
}

void func_8004A364(class_3A930_t *This, void **Unk2, void *Unk3) {
    timer_get_vtable()->Increment(This, Unk2, Unk3);

    if (This->m_Unk6 > This->m_Unk10) {
        This->vtable->Unk23(This, 4);
    }
}

void func_8004A3EC(class_3A930_t *This, s32 Unk) {
    timer_get_vtable()->Unk23(This, Unk);

    if (Unk == 4) {
        This->m_Unk9 = 1;
        This->vtable->Unk30(This);
    }
}

void func_8004A458(class_3A930_t *This, s32 Unk) {
    This->m_Unk10 = Unk;

    if (Unk >= 0) {
        This->m_Unk10 = 20 * Unk;
    }
}

void func_8004A478(class_3A930_t *This, s32 Unk) {
    if (This->m_SoundEngine) {
        This->m_SoundEngine->vtable->Unk16(This->m_SoundEngine, Unk, 127, 127);
    }
}

class_3A930_vtable_t *func_8004A4B8(void) {
    return &D_80086668;
}
