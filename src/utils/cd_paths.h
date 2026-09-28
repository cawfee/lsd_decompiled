#ifndef LSD_CD_PATHS_H
#define LSD_CD_PATHS_H

s32 get_seeded_random(s32 Seed, s32 Unk);

const char *get_ending_movie_path(s32 *DurationMaybe);
const char *get_ending_movie_path_2(s32 *DurationMaybe, s32);
const char *get_random_sound_type(s32 *Length);

const char *get_logo_asmk_path(s32 *DurationMaybe);
const char *get_random_opening_movie_path(s32 *out, s32 unused);
const char *get_special_day_movie(s32 *out, s32 packed);
const char *get_special_reel_movie_path(s32 *out, s32 index, s32 count);

s32 get_movie_duration_maybe(s32 Index);

#endif