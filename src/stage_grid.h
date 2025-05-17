#ifndef LSD_STAGE_GRID_H
#define LSD_STAGE_GRID_H

#include <common.h>

#define STAGE_GRID_DIMENSION_COUNT 14

typedef struct {
    s16 columns;
    s16 rows;
    bool is_vertical;
} stage_grid_dimensions_t;

s32 stage_grid_get_dimension_count(void);
stage_grid_dimensions_t *stage_grid_get_dimension_table(s32 *Length);
stage_grid_dimensions_t *stage_grid_get_dimension(s32 Index);

#endif