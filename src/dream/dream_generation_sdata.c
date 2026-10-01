#include "common.h"

/*
 * Dream generation .sdata image: the globals are all <= 8 bytes, so a
 * -G8 unit keeps them in .sdata.  dream_generation.c only declares them
 * `extern` (a complete scalar or an incomplete array), which preserves
 * the original absolute references to the array pairs while the scalars
 * stay gp-relative.
 */

s32 g_GenerationOwner = 0;
s32 g_GenerationFlags = 0;
s32 g_GenerationEffectColor = 0;

s32 g_GenerationEffectOrigin[2] = { -100, -100 };
s32 g_GenerationEffectScreen[2] = { 320, 240 };

s32 g_GenerationEffectX = -100;
s32 g_GenerationEffectY = -60;
s32 g_GenerationEffectW = 320;
s32 g_GenerationEffectH = 144;

u8 g_GenerationInfoColor[4] = {
    0x80, 0x80, 0x80, 0x00,
};

u8 g_GenerationEntityColorDefault[4] = {
    0x80, 0x80, 0x80, 0x00,
};

s8 g_GenerationEntryDefault[4] = {
    0x00, 0x00, 0x00, 0x00,
};

s8 g_GenerationEntryA[8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x0C,
};

s8 g_GenerationEntryB[4] = {
    0x00, 0x02, 0x0B, 0x0B,
};

s8 g_GenerationEntryC[4] = {
    0x00, 0x02, 0x03, 0x03,
};

