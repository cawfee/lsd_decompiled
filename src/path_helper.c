#include "common.h"

#include <psx/rand.h>

static s32 D_8008A964 = NULL;
static s32 D_8008A968 = NULL;

extern const char *g_STRING_TABLE[];
extern const char *g_SOUND_TYPES[];
extern const char *g_SE_PATHS[];
extern const char *g_ASMK_PATHS[];

INCLUDE_ASM("asm/nonmatchings/path_helper", func_80048CF0);

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

/**
 * Returns the address of the first element of the string table
 * It takes in a s32 if not null and sets it to the assumed table count.
 * Unchecked if 560 is the actual amount of strings in the table.
 */
const char *get_path_table(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = 0x230;
    }

    return &g_STRING_TABLE;
}

const char **get_sound_types_paths(void) {
    return &g_SOUND_TYPES;
}

// access to $gp
INCLUDE_ASM("asm/nonmatchings/path_helper", get_random_sound_type);

// Only 1 SE exists in the list
const char **get_se_paths(void) {
    return &g_SE_PATHS;
}

// Retrieves the first and only SE path
const char *get_se_path(void) {
    return *get_se_paths();
}

INCLUDE_ASM("asm/nonmatchings/path_helper", func_80048E2C);

INCLUDE_ASM("asm/nonmatchings/path_helper", func_80048E80);

// access to $gp
INCLUDE_ASM("asm/nonmatchings/path_helper", func_80048EA0);

const char *func_80048F60(void) {
    return func_80048E2C() + 0x70;
}

INCLUDE_ASM("asm/nonmatchings/path_helper", func_80048F84);

const char *func_8004903C(s32 Arg) {
    return func_80048E2C(Arg) + 0xFC;
}

const char *func_80049060(s32 Arg1, s32 Arg2) {
    return func_8004903C(Arg1) + 28 * Arg2;
}

const char *func_80049098(s32 Arg1, s32 Arg2, s32 Arg3) {
    return func_80049060(Arg1, Arg2 + (*(s16 *) GetStageGridDimensions() * Arg3));
}

const char *get_logo_asmk_path(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = '1';
    }

    return &g_ASMK_PATHS;
}

const char *get_opening_movie_path(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = 0;
    }

    return get_path_table(0) + 0x3D40;
}

INCLUDE_ASM("asm/nonmatchings/path_helper", func_8004913C);

// Get the first and only movie path
const char *get_ending_movie_path(s32 *DurationMaybe) {
    if (DurationMaybe != NULL) {
        *DurationMaybe = 7;
    }

    return get_path_table(0) + 0x3E04;
}

// Seemingly duplicate function to get the movie path from the movie path,
// maybe more endings were suppose to exist?
const char *get_ending_movie_path_2(s32 *DurationMaybe) {
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
INCLUDE_ASM("asm/nonmatchings/path_helper", get_special_day_movie);

INCLUDE_ASM("asm/nonmatchings/path_helper", get_movie_duration_maybe);

INCLUDE_ASM("asm/nonmatchings/path_helper", func_800493E4);
