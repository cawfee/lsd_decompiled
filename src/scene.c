#include "scene.h"

#include "timer.h"

extern scene_vtable_t D_80086668;

scene_t *func_8004A130(u32 Unk1, u32 Unk2) {
    scene_t *allocated = (scene_t *) memory_allocate_mem(0x38);

    if (allocated) {
        func_8004A4B8()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_8004A19C(scene_t *This, void *Unk2, sound_vtable_t *SoundEngine) {
    timer_get_vtable()->timer_create(This);
    This->vtable = func_8004A4B8();

    if (Unk2) {
        This->m_Sound = sound_create(Unk2);
    } else {
        This->m_Sound = SoundEngine;
    }

    This->m_Unk11 = Unk2;
    This->vtable->Unk15(This);
}

void func_8004A228(scene_t *This) {
    if (This->m_Unk11) {
        This->m_Sound->vtable->init_800269F0(This->m_Sound);
    }

    timer_get_vtable()->base_class_cleanup(This);
}

void func_8004A294(scene_t *This) {
    This->vtable->Unk26(This, -1);
}

s32 scene_run(scene_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk9 = 0;
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk9;
}

void func_8004A324(scene_t *This) {
    timer_get_vtable()->Unk17(This);
}

void func_8004A35C(void) {
}

void func_8004A364(scene_t *This, void **Unk2, void *Unk3) {
    timer_get_vtable()->timer_increment(This, Unk2, Unk3);

    if (This->m_Unk6 > This->m_Unk10) {
        This->vtable->Unk23(This, 4);
    }
}

void func_8004A3EC(scene_t *This, s32 Unk) {
    timer_get_vtable()->Unk23(This, Unk);

    if (Unk == 4) {
        This->m_Unk9 = 1;
        This->vtable->Unk30(This);
    }
}

void func_8004A458(scene_t *This, s32 Unk) {
    This->m_Unk10 = Unk;

    if (Unk >= 0) {
        This->m_Unk10 = 20 * Unk;
    }
}

void func_8004A478(scene_t *This, s32 Unk) {
    if (This->m_Sound) {
        This->m_Sound->vtable->func_8002CA3C(This->m_Sound, Unk, 127, 127);
    }
}

scene_vtable_t *func_8004A4B8(void) {
    return &D_80086668;
}
