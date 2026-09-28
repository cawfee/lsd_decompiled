#include "common.h"

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_ExpAllocArea);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_expand);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_InitHeap);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_malloc);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_free);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_realloc);

INCLUDE_ASM("asm/nonmatchings/psyq/malloc", psyq_malloc_calloc);
