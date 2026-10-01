#include <common.h>

#include <psx/rand.h>

#include "scene/stage_grid.h"
#include "utils/paths.h"

static char *g_CDI_STR = "CDI\\";
/* Forced sound-type / music-track selection set by set_audio_path_override;
   0 means "use the seeded random choice". */
static s32 g_SoundTypeOverride = NULL;
static s32 g_MusicTrackOverride = NULL;

extern const char *g_SE_PATHS[];

/* Play length in seconds for each movie in g_STRING_TABLE order; indexed by
   the duration hint returned by the movie path getters. */
static s16 g_MovieDurations[] = {
    1060,  1088,  953,   1179,  979,   1231,  1046,  474,   524,   439,   349,   379,   352,
    352,   475,   867,   527,   445,   399,   579,   264,   541,   566,   325,   436,   524,
    522,   523,   649,   451,   465,   473,   411,   490,   467,   523,   187,   384,   90,
    90,    90,    90,    90,    90,    90,    90,    90,    90,    -10,   90,
};

char *get_data_folder(void) {
    return g_CDI_STR;
}

s32 get_seeded_random(s32 Seed, s32 Unk) {
    if (Seed != 0) {
        srand(Seed);
    }

    return rand();
}

void set_audio_path_override(s32 SoundType, s32 MusicTrack) {
    if (SoundType >= 0) {
        g_SoundTypeOverride = SoundType;
    }

    if (MusicTrack >= 0) {
        g_MusicTrackOverride = MusicTrack;
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

const char *get_random_sound_type(s32 *Length) {
    u32 idx;
    const char **paths;
    s32 override;
    s32 off;

    idx = (u32)get_seeded_random(0, (s32)Length) % 7u;
    paths = get_sound_types_paths();
    override = g_SoundTypeOverride;
    if (override != 0) {
        off = (override - 1) * 4;
    } else {
        off = idx * 4;
    }
    return *(const char **)((u8 *)paths + off);
}

// Only 1 SE exists in the list
const char **get_se_paths(void) {
    return &g_SE_PATHS;
}

// Retrieves the first and only SE path
const char *get_se_path(void) {
    return *get_se_paths();
}

s32 get_stage_paths(s32 Arg) {
    return get_path_table(NULL) + (g_StagePathStart[Arg] * 0x1C);
}

const char *get_stage_paths_str(s32 Arg) {
    return get_stage_paths(Arg);
}

const char *get_random_stage_texture_path(s32 arg0, s32 seed_arg, s32 count) {
    s32 mod;
    s32 idx;

    count = count - 1;
    count = count % 40;
    mod = (count / 10) + 1;
    idx = get_seeded_random(0, seed_arg) % mod;
    return get_stage_paths_str(arg0) + (idx * 0x1C);
}

const char *get_stage_music_paths(s32 Arg) {
    return get_stage_paths(Arg) + 0x70;
}

const char *get_stage_music_path(s32 arg0, s32 unused) {
    u32 idx;
    const char *path;
    s32 override;
    s32 off;

    idx = (u32)get_seeded_random(0, unused) % 5u;
    if (arg0 == 9) {
        if (idx == 2) {
            idx = 3;
        }
        if (g_MusicTrackOverride == 3) {
            g_MusicTrackOverride = 4;
        }
    }
    path = get_stage_music_paths(arg0);
    override = g_MusicTrackOverride;
    if (override != 0) {
        off = (override - 1) * 7;
    } else {
        off = (s32)idx * 7;
    }
    return (const char *)((u8 *)path + off * 4);
}

const char *get_stage_model_paths(s32 Arg) {
    return get_stage_paths(Arg) + 0xFC;
}

const char *get_stage_model_path(s32 Arg1, s32 Arg2) {
    return get_stage_model_paths(Arg1) + 28 * Arg2;
}

const char *get_stage_model_path_by_grid(s32 Arg1, s32 Arg2, s32 Arg3) {
    return get_stage_model_path(Arg1, Arg2 + (stage_grid_get_dimension(Arg1)->columns * Arg3));
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

const char *get_random_opening_movie_path(s32 *out, s32 unused) {
    s32 dur;
    u32 idx;
    const char *path;

    idx = (u32)get_seeded_random(0, unused) % 7u;
    path = get_opening_movie_path(&dur);
    if (out != NULL) {
        *out = idx + dur;
    }
    return path + (idx * 0x1C);
}

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

    return path + (LSD_PATH_LEN * Index);
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
const char *get_special_day_movie(s32 *out, s32 packed) {
    s32 dur;
    const char *path;
    s32 val;

    if (*(s16 *)&packed >= 0) {
        path = get_special_movie_path(&dur, *(s16 *)&packed);
        if (out != NULL) {
            if (((u16 *)&packed)[1] < 2U) {
                val = ((s16 *)&packed)[1] + dur;
            } else {
                val = -1;
            }
            *out = val;
        }
        return path + (((s16 *)&packed)[1] * 0x1C);
    }
    return get_event_movie_path(out, ((s16 *)&packed)[1]);
}

s32 get_movie_duration_maybe(s32 Index) {
    return g_MovieDurations[Index];
}

// Picks one of the special-day movies at `index` and sums the durations of
// `count` consecutive movies (used to time the concatenated special reel).
const char *get_special_reel_movie_path(s32 *out, s32 index, s32 count) {
    s32 start;
    const char *path;
    s32 i;
    s32 end;

    path = get_special_movie_path(&start, index);
    end = count << 1;
    *out = 0;
    end += start;
    i = start;
    while (i < end) {
        *out += g_MovieDurations[i] + 10;
        i++;
    }
    *out -= 10;
    return path;
}

