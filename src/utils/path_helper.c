#include <common.h>

#include <psx/rand.h>

#include "../stage_grid.h"
#include "paths.h"

static char *g_CDI_STR = "CDI\\";
static s32 D_8008A964 = NULL;
static s32 D_8008A968 = NULL;

extern const char *g_SE_PATHS[];

static s16 D_80086170[] = { 0x424, 0x440, 0x3B9, 0x49B, 0x3D3, 0x4CF, 0x416, 0x1DA, 0x20C, 0x1B7,  0x15D, 0x17B, 0x160,
                            0x160, 0x1DB, 0x363, 0x20F, 0x1BD, 0x18F, 0x243, 0x108, 0x21D, 0x236,  0x145, 0x1B4, 0x20C,
                            0x20A, 0x20B, 0x289, 0x1C3, 0x1D1, 0x1D9, 0x19B, 0x1EA, 0x1D3, 0x20B,  0xBB,  0x180, 0x5A,
                            0x5A,  0x5A,  0x5A,  0x5A,  0x5A,  0x5A,  0x5A,  0x5A,  0x5A,  0xFFF6, 0x5A };

char *get_data_folder(void) {
    return g_CDI_STR;
}

s32 get_seeded_random(s32 Seed, s32 Unk) {
    if (Seed != 0) {
        srand(Seed);
    }

    return rand();
}

void func_80048D28(s32 arg0, s32 arg1) {
    if (arg0 >= 0) {
        D_8008A964 = arg0;
    }

    if (arg1 >= 0) {
        D_8008A968 = arg1;
    }
}

const char *get_path_table(s32 *Count) {
    if (Count != NULL) {
        // Amount of strings before opening movies?
        *Count = 560;
    }

    return &g_STRING_TABLE;
}

const char **get_sound_types_paths(void) {
    return &g_SOUND_TYPES;
}

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", get_random_sound_type);

// Only 1 SE exists in the list
const char **get_se_paths(void) {
    return &g_SE_PATHS;
}

// Retrieves the first and only SE path
const char *get_se_path(void) {
    return *get_se_paths();
}

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_80048E2C);

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_80048E80);

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_80048EA0);

const char *func_80048F60(void) {
    return func_80048E2C() + 0x70;
}

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_80048F84);

const char *func_8004903C(s32 Arg) {
    return func_80048E2C(Arg) + 0xFC;
}

const char *func_80049060(s32 Arg1, s32 Arg2) {
    return func_8004903C(Arg1) + 28 * Arg2;
}

const char *func_80049098(s32 Arg1, s32 Arg2, s32 Arg3) {
    return func_80049060(Arg1, Arg2 + (stage_grid_get_dimension(Arg1)->columns * Arg3));
}

const char *get_logo_asmk_path(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = '1';
    }

    return "ETC\\ASMK.STR\0\0"; // TODO pad
}

const char *get_opening_movie_path(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = 0;
    }

    return get_path_table(0) + 0x3D40;
}

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_8004913C);

// Get the first and only movie path
const char *get_ending_movie_path(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = 7;
    }

    return get_path_table(0) + 0x3E04;
}

// Seemingly duplicate function to get the movie path from the movie path,
// maybe more endings were suppose to exist?
// Takes in an index but never used?
const char *get_ending_movie_path_2(s32 *DurationMaybe, s32 Unk) {
    s32 ret;
    const char *path = get_ending_movie_path(&ret);

    if (DurationMaybe != NULL) {
        *DurationMaybe = ret;
    }

    return path;
}

// Get the first event movie path
const char *get_event1_movie_path(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = 8;
    }

    // "FILM\EVENT1.STR"
    return get_path_table(0) + 0x3E20;
}

// Get an event movie path for a given index
const char *get_event_movie_path(s32 *DurationMaybe, s32 Index) {
    s32 duration_copy;
    const char *path = get_event1_movie_path(&duration_copy);

    if (DurationMaybe != NULL) {
        *DurationMaybe = Index + duration_copy;
    }

    return path + (0x1C * Index);
}

// Gets FILM\SPDAY01A.STR, SPDAY02A, and so on from a given index
const char *get_special_movie_path(s32 *DurationMaybe, s32 Index) {
    const char *path = get_path_table(0) + 0x3EC8;

    if (DurationMaybe != NULL) {
        *DurationMaybe = 2 * Index + 0xE;
    }

    return &path[0xA8 * Index];
}

// Takes in flags on a special day to play an event movie, or to play a special day movie
INCLUDE_ASM("asm/nonmatchings/utils/path_helper", get_special_day_movie);

s32 get_movie_duration_maybe(s32 Index) {
#ifdef NON_MATCHING
    return D_80086170[Index];
#else
    s32 result;
    s32 a0_r;

    __asm__(".set noat\n\t"
            "sll   %1, %2, 1\n\t"
            "lui   $1, %%hi(%3)\n\t"
            "addiu $1, $1, %%lo(%3)\n\t"
            "addu  $1, $1, %1\n\t"
            "lh    %0, 0($1)\n\t"

            : "=r"(result), "=r"(a0_r)
            : "1"(Index), "i"(&D_80086170)
            : "$1");

    return result;
#endif
}

INCLUDE_ASM("asm/nonmatchings/utils/path_helper", func_800493E4);
