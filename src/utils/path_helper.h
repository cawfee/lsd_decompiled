#ifndef LSD_PATH_HELPER_H
#define LSD_PATH_HELPER_H

s32 get_seeded_random(s32 Seed, s32 Unk);

const char *get_ending_movie_path(s32 *DurationMaybe);
const char *get_ending_movie_path_2(s32 *DurationMaybe, s32);
const char *get_random_sound_type(s32 *Length);

s32 get_movie_duration_maybe(s32 Index);

#endif