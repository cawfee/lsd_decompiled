#ifndef PSX_MEMORY_H
#define PSX_MEMORY_H

#include <types.h>

u8 *bcopy(u8 *, u8 *, s32);
s8 *bzero(s8 *, s32);
int   memcmp (/*  unsigned char *, unsigned char *, int  */);

#endif