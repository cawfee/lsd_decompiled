#include "common.h"
#include "base_class.h"

extern s32 D_8008A820;

s32 destroy_list(base_class_t **arr, s32 n) {
    base_class_t *obj;

    if (n-- > 0) {
        do {
            obj = *arr;
            *arr = obj->vtable->base_class_destructor(obj);
            arr++;
        } while (n-- > 0);
    }
}

void func_8001844C(s32 value) {
    D_8008A820 = value;
}

s32 func_80018458(void) {
    return D_8008A820;
}
