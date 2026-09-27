#include "413A8.h"
#include "base_class.h"
#include "memory.h"

extern u8 *D_8008AAE4;

int strlen(char *s);
void func_80050CD8(class_413A8_t *This);

void func_80050C14(class_413A8_t *This, char *arg1, s32 arg2) {
    s32 len;
    u8 *p;
    s32 count;

    base_class_get_vtable()->Construct(This);
    This->vtable = func_80051A4C();
    len = strlen(arg1);
    This->m_Unk3 = len;
    This->m_Unk9 = (s32)memory_allocate_mem(len + 4);
    p = D_8008AAE4;
    count = 0;
    if (*p != 0) {
        do {
            p += 1;
            count += 1;
        } while (*p != 0);
    }
    This->m_Unk4 = count;
    func_80050CD8(This);
    This->vtable->Unk15(This, arg1, arg2);
}
