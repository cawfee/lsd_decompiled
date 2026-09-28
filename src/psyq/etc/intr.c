#include "common.h"

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", EnterCriticalSection);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ExitCriticalSection);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", FlushCache);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ResetCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", InterruptCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", DMACallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", VSyncCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", VSyncCallbacks);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", StopCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", RestartCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", CheckCallback);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", GetIntrMask);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", SetIntrMask);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", startIntr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", trapIntr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", setIntr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", stopIntr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", restartIntr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", memclr);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", HookEntryInt);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ChangeClearPAD);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ResetEntryInt);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ChangeClearRCnt);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", _96_remove);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", ReturnFromException);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", setjmp);

INCLUDE_ASM("asm/nonmatchings/psyq/etc/intr", longjmp);
