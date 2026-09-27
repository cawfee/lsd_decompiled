#include "46B20.h"

#include <psx/rand.h>

extern class_46B20_vtable_t D_800876FC;

void func_80056DF0(void) {
}

void func_80056DF8(class_46B20_t *This) {
    destroy_list(&This->m_Unk32, 5);
}

void func_80056E1C(class_46B20_t *This) {
    func_80056D18(This, 0, 0, 0);
}

extern s32 D_8008788C[];

void func_80056E44(class_46B20_t *This) {
    class_46B20_t **slot;
    s32 i;
    s32 which;

    slot = (class_46B20_t **)&This->m_Unk33;
    i = 0;
    do {
        i++;
        which = (s32)&D_8008788C[((u32)rand() % 6) * 3];
        slot[0]->vtable->Unk17(slot[0], 1, which);
        slot[0]->m_Unk32 = (rand() % 360) << 12;
        slot++;
    } while (i < 4);
}

void func_80056F28(class_46B20_t *This) {
    destroy_list(&This->m_Unk32, 5);
}

class_46B20_vtable_t *func_80056F4C(void) {
    return &D_800876FC;
}
