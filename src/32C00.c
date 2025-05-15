#include "common.h"

void *func_80042400() {
    void *allocated = (void *) memory_allocate_mem(0x1C);

    if (allocated) {
        void *vtable = func_80042684();
        (*((void (**)(void *)) vtable + 2))(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042450);

INCLUDE_ASM("asm/nonmatchings/32C00", func_800424A8);

INCLUDE_ASM("asm/nonmatchings/32C00", func_800424E0);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042550);

INCLUDE_ASM("asm/nonmatchings/32C00", func_800425D8);

INCLUDE_ASM("asm/nonmatchings/32C00", func_800425EC);

INCLUDE_ASM("asm/nonmatchings/32C00", func_8004264C);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042658);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042664);

INCLUDE_ASM("asm/nonmatchings/32C00", func_8004266C);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042678);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042684);
