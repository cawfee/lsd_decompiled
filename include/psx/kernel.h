#ifndef PSX_KERNEL_H
#define PSX_KERNEL_H

extern void SetMem(long);

extern long OpenEvent(unsigned long, long, long, long (*Func)());
extern long CloseEvent(long);

extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);

#endif