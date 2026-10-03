#ifndef COMMON_H
#define COMMON_H

#include "game.h"
#include "include_asm.h"
#include "types.h"

#define UNUSED UNUSED(x)(void)(x)

typedef struct {
    s32 x;
    s32 y;
} vec2d_t;

// 16bit vec3d variant
typedef struct {
    s16 x;
    s16 y;
    s16 z;
} vec3d_16_t;

// 32bit vec3d
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} vec3d_t;

// 16bit vec4d variant
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} vec4d_16_t;

// 3d 16bit box
typedef struct {
    vec3d_16_t min;
    vec3d_16_t max;
} box3d_16_t;

typedef struct {
    s16 num;
    s16 den;
} frac_t;

#endif