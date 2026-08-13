#ifndef LSD_STAGE_GRID_H
#define LSD_STAGE_GRID_H

#include <common.h>
#include "dream_sys.h"

#define STAGE_GRID_DIMENSION_COUNT 14

typedef struct {
    s16 columns;
    s16 rows;
    bool is_vertical;
} stage_grid_dimensions_t;

s32 stage_grid_get_dimension_count(void);
stage_grid_dimensions_t *stage_grid_get_dimension_table(s32 *length);
stage_grid_dimensions_t *stage_grid_get_dimension(s32 index);
s32 get_stage_chunk_from_mood(s8 *coords, dream_sys_mood_graph_point_t *mood);
dream_sys_mood_graph_point_t *get_mood_from_stage_chunk(s32 stage, s8 *coords);

#endif
