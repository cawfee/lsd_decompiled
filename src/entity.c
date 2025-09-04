#include "entity.h"
#include "55DD4.h"

extern entity_vtable_t g_ENTITY_VTABLE;

entity_t *entity_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    entity_t *allocated = (entity_t *) memory_allocate_mem(0x108);

    if (allocated) {
        if (entity_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3) == NULL) {
            memory_free_mem(allocated);
            return NULL;
        }

        return allocated;
    }

    return NULL;
}

entity_vtable_t *entity_construct(entity_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    if (class_55DD4_get_vtable()->Construct(This, Unk3, Unk4)) {
        This->vtable = entity_get_vtable();
        This->m_Unk37 = Unk2;
        This->m_Unk38 = 0;
        This->m_Unk63 = 0;
        This->m_Unk64 = 0;
        This->vtable->Unk15(This);
        return This;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D108);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D1EC);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D278);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D314);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D418);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D480);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D560);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D658);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D6D4);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D714);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D7FC);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D864);

INCLUDE_ASM("asm/nonmatchings/entity", Entity__GetMoodEffect);

INCLUDE_ASM("asm/nonmatchings/entity", Entity__GetUnlockEffect);

INCLUDE_ASM("asm/nonmatchings/entity", Entity__GetLinkStage);

INCLUDE_ASM("asm/nonmatchings/entity", Entity__GetEventVideo);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D9F4);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DA3C);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DAAC);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DAFC);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DB8C);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DBF0);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DD18);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DE18);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DEE0);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005DF9C);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E02C);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E0B0);

entity_vtable_t *entity_get_vtable() {
    return &g_ENTITY_VTABLE;
}
