#include "common.h"

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr_dma", startIntrDMA);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr_dma", trapIntrDMA);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr_dma", setIntrDMA);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr_dma", memclr_dma);
