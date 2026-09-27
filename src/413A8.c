#include "413A8.h"
#include "text_line.h"
#include "322B4.h"
#include "3249C.h"
#include "base_class.h"
#include "memory.h"
#include "tim_image.h"

class_413A8_t *func_80050BA8(char *Unk1, s32 Unk2) {
    class_413A8_t *allocated = (class_413A8_t *) memory_allocate_mem(0x4C);

    if (allocated) {
        func_80051A4C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}
