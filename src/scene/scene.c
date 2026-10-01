#include "scene/scene.h"

#include "base/base_class.h"
#include "base/timer.h"

void func_8003E030(void *, void **, s32);
void func_8003E418(void *, void *, s32);

scene_vtable_t D_80086668 = {
    0x230,
    base_class_destructor,
    scene_construct,
    scene_cleanup,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    func_8003E030,
    NULL,
    scene_reset,
    (void (*)(void *, void *, s32))scene_run,
    scene_stop,
    NULL,
    NULL,
    func_8003E418,
    scene_noop,
    scene_update,
    scene_finish,
    timer_begin_frame,
    timer_end_frame,
    scene_set_duration,
    scene_play_note,
    NULL,
    NULL,
    NULL,
};

scene_t *scene_create(u32 Unk1, u32 Unk2) {
    scene_t *allocated = (scene_t *) memory_allocate_mem(0x38);

    if (allocated) {
        scene_get_vtable()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void scene_construct(scene_t *This, void *Unk2, sound_vtable_t *SoundEngine) {
    timer_get_vtable()->timer_create(This);
    This->vtable = scene_get_vtable();

    if (Unk2) {
        This->m_Sound = sound_create(Unk2);
    } else {
        This->m_Sound = SoundEngine;
    }

    This->m_Unk11 = Unk2;
    This->vtable->Unk15(This);
}

void scene_cleanup(scene_t *This) {
    if (This->m_Unk11) {
        This->m_Sound->vtable->Destroy(This->m_Sound);
    }

    timer_get_vtable()->Cleanup(This);
}

void scene_reset(scene_t *This) {
    This->vtable->Unk26(This, -1);
}

s32 scene_run(scene_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk9 = 0;
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk9;
}

void scene_stop(scene_t *This) {
    timer_get_vtable()->Unk17(This);
}

void scene_noop(void *) {
}

void scene_update(scene_t *This, void **Unk2, void *Unk3) {
    timer_get_vtable()->timer_increment(This, Unk2, Unk3);

    if (This->m_Unk6 > This->m_Unk10) {
        This->vtable->Unk23(This, 4);
    }
}

void scene_finish(scene_t *This, s32 Unk) {
    timer_get_vtable()->Unk23(This, Unk);

    if (Unk == 4) {
        This->m_Unk9 = 1;
        This->vtable->Unk30(This);
    }
}

void scene_set_duration(scene_t *This, s32 Unk) {
    This->m_Unk10 = Unk;

    if (Unk >= 0) {
        This->m_Unk10 = 20 * Unk;
    }
}

void scene_play_note(scene_t *This, s32 Unk) {
    if (This->m_Sound) {
        This->m_Sound->vtable->sound_play_note(This->m_Sound, Unk, 127, 127);
    }
}

scene_vtable_t *scene_get_vtable(void) {
    return &D_80086668;
}
