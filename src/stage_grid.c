#include "stage_grid.h"

// https://github.com/FirecatFG/lsddecomp/blob/main/src/lsdde/StageGrid.c

extern dream_sys_mood_graph_point_t *STAGE_CHUNK_MOODS[];

static stage_grid_dimensions_t g_STAGE_GRID_DIMENSIONS[STAGE_GRID_DIMENSION_COUNT] = {
    { 1, 5, true },    // Apartment
    { 3, 2, false },   // Pit
    { 6, 6, false },   // Kyoto
    { 16, 16, false }, // Natural
    { 6, 5, false },   // Happy
    { 5, 6, false },   // Violence
    { 1, 6, true },    // Tower
    { 5, 1, false },   // Palace
    { 1, 3, false },   // Flesh
    { 1, 2, false },   // Clockwork
    { 3, 1, false },   // Hallway
    { 4, 3, false },   // Heaven
    { 4, 5, false },   // Void
    { 2, 2, false }    // Park
};

s32 stage_grid_get_dimension_count(void) {
    return STAGE_GRID_DIMENSION_COUNT;
}

stage_grid_dimensions_t *stage_grid_get_dimension_table(s32 *length) {
    if (length) {
        *length = STAGE_GRID_DIMENSION_COUNT;
    }

    return &g_STAGE_GRID_DIMENSIONS;
}

stage_grid_dimensions_t *stage_grid_get_dimension(s32 index) {
    return &stage_grid_get_dimension_table(NULL)[index];
}

s32 get_stage_chunk_from_mood(s8 *coords, dream_sys_mood_graph_point_t *mood) {
    dream_sys_mood_graph_point_t **moods_table;
    dream_sys_mood_graph_point_t *chunk_moods;
    s32 columns;
    s32 rows;
    s32 dim_offset;
    s32 col;
    s32 row;
    u32 stage;

    stage = 0;
    dim_offset = 0;
    moods_table = STAGE_CHUNK_MOODS;
    do {
        chunk_moods = *moods_table;
        rows = *(s16 *)((s8 *)&g_STAGE_GRID_DIMENSIONS[0].rows + dim_offset);
        columns = *(s16 *)((s8 *)g_STAGE_GRID_DIMENSIONS + dim_offset);
        for (row = 0; row < rows; row++) {
            for (col = 0; col < columns; col++) {
                if (mood->value == chunk_moods->value) {
                    coords[0] = col;
                    coords[1] = row;
                    return stage;
                }
                chunk_moods += 1;
            }
        }
        dim_offset += 8;
        stage += 1;
        moods_table += 1;
    } while (stage < STAGE_GRID_DIMENSION_COUNT);

    return -1;
}

dream_sys_mood_graph_point_t *get_mood_from_stage_chunk(s32 stage, s8 *coords) {
    return STAGE_CHUNK_MOODS[stage] + coords[1] * g_STAGE_GRID_DIMENSIONS[stage].columns + coords[0];
}
