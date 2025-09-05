#ifndef COMMON_H
#define COMMON_H

#include "game.h"
#include "include_asm.h"
#include "types.h"
#include "unknown.h"

#define UNUSED UNUSED(x)(void)(x)

typedef struct {
    s32 x;
    s32 y;
} vec2d_t;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} vec3d_t;

#endif