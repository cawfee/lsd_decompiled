#include "scene/stage_grid.h"

// https://github.com/FirecatFG/lsddecomp/blob/main/src/lsdde/StageGrid.c

static stage_grid_dimensions_t g_STAGE_GRID_DIMENSIONS[STAGE_GRID_DIMENSION_COUNT] = {
    { 1, 5, true },    // STG00 Bright Moon Cottage
    { 3, 2, false },   // STG01 Pit & Temple
    { 6, 6, false },   // STG02 Kyoto
    { 16, 16, false }, // STG03 The Natural World
    { 6, 5, false },   // STG04 Happy Town
    { 5, 6, false },   // STG05 Violence District
    { 1, 6, true },    // STG06 Moonlight Tower
    { 5, 1, false },   // STG07 Temple Dojo
    { 1, 3, false },   // STG08 Flesh Tunnels
    { 1, 2, false },   // STG09 Clockwork Machines
    { 3, 1, false },   // STG10 Long Hallway
    { 4, 3, false },   // STG11 Sun Faces Heave
    { 4, 5, false },   // STG12 Black Space
    { 2, 2, false }    // STG13 Monument Park
};

/* Per-stage mood grids, one entry per grid cell in row-major order.
 * Each entry is the signed (axis.dynamic, axis.upper) mood pair. */
dream_sys_mood_graph_point_t STG00_CHUNK_MOODS[] = {
    { { 0, -3 } }, { { 1, 1 } }, { { -1, 1 } }, { { 0, 0 } }, { { -5, -7 } }, { { 0, 0 } },
};

dream_sys_mood_graph_point_t STG01_CHUNK_MOODS[] = {
    { { 7, 1 } }, { { 1, 2 } }, { { 8, -6 } }, { { 9, 0 } }, { { 0, -9 } }, { { -8, -6 } },
};

dream_sys_mood_graph_point_t STG02_CHUNK_MOODS[] = {
    { { 0, 9 } },  { { 1, 5 } },   { { 2, 5 } },   { { 2, 4 } },   { { 2, 3 } },   { { 3, 3 } },
    { { 3, 2 } },  { { 4, 2 } },   { { 4, 1 } },   { { 3, 1 } },   { { 3, 0 } },   { { 2, 0 } },
    { { 2, -1 } }, { { 1, -1 } },  { { 1, -2 } },  { { 1, -4 } },  { { 9, 0 } },   { { 1, -5 } },
    { { 0, -5 } }, { { -1, -5 } }, { { -1, -4 } }, { { -1, -2 } }, { { -1, -1 } }, { { -2, -1 } },
    { { -2, 0 } }, { { -3, 0 } },  { { -3, 1 } },  { { -4, 1 } },  { { -4, 2 } },  { { -3, 2 } },
    { { -3, 3 } }, { { -2, 3 } },  { { -2, 4 } },  { { -2, 5 } },  { { -1, 5 } },  { { 1, 3 } },
};

dream_sys_mood_graph_point_t STG03_CHUNK_MOODS[] = {
    { { 9, 0 } },   { { 9, 0 } },   { { 6, 7 } },   { { 6, 6 } },   { { 9, 0 } },   { { 9, 0 } },   { { 7, 6 } },
    { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 7, 5 } },   { { 9, 0 } },   { { 8, 5 } },   { { 9, 5 } },
    { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 4 } },   { { 9, 3 } },
    { { 9, 2 } },   { { 9, 1 } },   { { 9, 0 } },   { { 9, -1 } },  { { 9, 0 } },   { { 9, -2 } },  { { 9, -3 } },
    { { 9, -4 } },  { { 9, -5 } },  { { 8, -5 } },  { { 7, -5 } },  { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },
    { { 9, 0 } },   { { 9, 0 } },   { { 7, -6 } },  { { 6, -6 } },  { { 6, -7 } },  { { -6, -7 } }, { { -6, -6 } },
    { { 9, 0 } },   { { -7, -6 } }, { { -7, -5 } }, { { -8, -5 } }, { { -9, -5 } }, { { 9, 0 } },   { { 9, 0 } },
    { { 9, 0 } },   { { 9, 0 } },   { { -9, -4 } }, { { -9, -3 } }, { { -9, -2 } }, { { -9, -1 } }, { { -9, 0 } },
    { { -9, 1 } },  { { -9, 2 } },  { { -9, 3 } },  { { -9, 4 } },  { { -9, 5 } },  { { -8, 5 } },  { { -7, 5 } },
    { { -7, 6 } },  { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { -6, 6 } },  { { -6, 7 } },
    { { -1, 7 } },  { { 0, 7 } },   { { 1, 7 } },   { { 1, 6 } },   { { 2, 6 } },   { { 3, 6 } },   { { 4, 6 } },
    { { 5, 6 } },   { { 5, 5 } },   { { 9, 0 } },   { { 9, 0 } },   { { 5, 4 } },   { { 6, 4 } },   { { 7, 4 } },
    { { 8, 4 } },   { { 8, 3 } },   { { 8, 2 } },   { { 8, 1 } },   { { 8, 0 } },   { { 8, -1 } },  { { 8, -2 } },
    { { 8, -3 } },  { { 8, -4 } },  { { 7, -4 } },  { { 6, -4 } },  { { 9, 0 } },   { { 9, 0 } },   { { 5, -4 } },
    { { 5, -5 } },  { { 5, -6 } },  { { 4, -6 } },  { { 3, -6 } },  { { 2, -6 } },  { { 1, -6 } },  { { -1, -6 } },
    { { -2, -6 } }, { { -3, -6 } }, { { -4, -6 } }, { { -5, -6 } }, { { 9, 0 } },   { { -5, -5 } }, { { 9, 0 } },
    { { 9, 0 } },   { { 9, 0 } },   { { -5, -4 } }, { { -6, -4 } }, { { -7, -4 } }, { { -8, -4 } }, { { -8, -3 } },
    { { -8, -2 } }, { { -8, -1 } }, { { -8, 0 } },  { { -8, 1 } },  { { -8, 2 } },  { { -8, 3 } },  { { -8, 4 } },
    { { -7, 4 } },  { { 9, 0 } },   { { 9, 0 } },   { { -6, 4 } },  { { -5, 4 } },  { { -5, 5 } },  { { -5, 6 } },
    { { -4, 6 } },  { { -3, 6 } },  { { 9, 0 } },   { { -2, 6 } },  { { -1, 6 } },  { { 3, 5 } },   { { 4, 5 } },
    { { 4, 4 } },   { { 4, 3 } },   { { 5, 3 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 6, 3 } },
    { { 9, 0 } },   { { 7, 3 } },   { { 7, 2 } },   { { 7, -1 } },  { { 7, -2 } },  { { 7, -3 } },  { { 6, -3 } },
    { { 5, -3 } },  { { 4, -4 } },  { { 4, -5 } },  { { 3, -5 } },  { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },
    { { 2, -5 } },  { { -2, -5 } }, { { -3, -5 } }, { { -4, -5 } }, { { -4, -4 } }, { { 9, 0 } },   { { -5, -3 } },
    { { -6, -3 } }, { { -7, -3 } }, { { -7, -2 } }, { { -7, -1 } }, { { -7, 2 } },  { { 9, 0 } },   { { 9, 0 } },
    { { 9, 0 } },   { { 9, 0 } },   { { -7, 3 } },  { { -6, 3 } },  { { -5, 3 } },  { { -4, 3 } },  { { -4, 4 } },
    { { -4, 5 } },  { { -3, 5 } },  { { 0, 5 } },   { { 3, 4 } },   { { 5, 2 } },   { { 6, 2 } },   { { 6, 1 } },
    { { 6, 0 } },   { { 6, -1 } },  { { 9, 0 } },   { { 9, 0 } },   { { 6, -2 } },  { { 5, -2 } },  { { 4, -2 } },
    { { 3, -2 } },  { { 3, -3 } },  { { 3, -4 } },  { { 2, -4 } },  { { -2, -4 } }, { { -3, -4 } }, { { -3, -3 } },
    { { 9, 0 } },   { { -3, -2 } }, { { -4, -2 } }, { { -5, -2 } }, { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },
    { { -6, -2 } }, { { -6, -1 } }, { { -6, 0 } },  { { -6, 1 } },  { { -6, 2 } },  { { -5, 2 } },  { { -3, 4 } },
    { { -1, 4 } },  { { 0, 4 } },   { { 1, 4 } },   { { 5, 1 } },   { { 5, 0 } },   { { 5, -1 } },  { { 9, 0 } },
    { { 9, 0 } },   { { 4, -1 } },  { { 3, -1 } },  { { 2, -2 } },  { { 2, -3 } },  { { 1, -3 } },  { { -1, -3 } },
    { { -2, -3 } }, { { -2, -2 } }, { { -3, -1 } }, { { -4, -1 } }, { { -5, -1 } }, { { -5, 0 } },  { { -5, 1 } },
    { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 4, 0 } },   { { -4, 0 } },  { { 9, 0 } },
    { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },
    { { 9, 0 } },   { { 0, 0 } },   { { 0, 0 } },   { { 9, 0 } },
};

dream_sys_mood_graph_point_t STG04_CHUNK_MOODS[] = {
    { { 5, 9 } },  { { 5, 8 } },  { { 7, 7 } },  { { 4, 7 } },  { { 3, 7 } },  { { 9, 0 } },
    { { 2, 7 } },  { { -2, 7 } }, { { -3, 7 } }, { { -4, 7 } }, { { -5, 7 } }, { { -5, 8 } },
    { { -5, 9 } }, { { -4, 9 } }, { { -3, 9 } }, { { -2, 9 } }, { { -1, 9 } }, { { 9, 0 } },
    { { 1, 9 } },  { { 2, 9 } },  { { 3, 9 } },  { { 4, 9 } },  { { 4, 8 } },  { { 3, 8 } },
    { { 2, 8 } },  { { 1, 8 } },  { { 0, 8 } },  { { -1, 8 } }, { { -2, 8 } }, { { 9, 0 } },
};

dream_sys_mood_graph_point_t STG05_CHUNK_MOODS[] = {
    { { 3, -7 } },  { { 3, -8 } },  { { 4, -8 } },  { { 5, -8 } },  { { 5, -9 } },  { { 9, 0 } },
    { { 4, -9 } },  { { 3, -9 } },  { { 2, -9 } },  { { 1, -9 } },  { { -1, -8 } }, { { -1, -9 } },
    { { -2, -9 } }, { { -3, -9 } }, { { -4, -9 } }, { { 9, 0 } },   { { -5, -9 } }, { { -5, -8 } },
    { { -4, -8 } }, { { -3, -8 } }, { { 9, 0 } },   { { -3, -7 } }, { { -2, -7 } }, { { -1, -7 } },
    { { 0, -7 } },  { { 1, -7 } },  { { 2, -7 } },  { { 2, -8 } },  { { 1, -8 } },  { { 0, -8 } },
};

dream_sys_mood_graph_point_t STG06_CHUNK_MOODS[] = {
    { { 0, -4 } }, { { 0, -2 } }, { { 0, -1 } }, { { 0, 1 } }, { { 0, 2 } }, { { 1, 2 } },
};

dream_sys_mood_graph_point_t STG07_CHUNK_MOODS[] = {
    { { 2, 2 } }, { { 2, 1 } }, { { 1, 0 } }, { { -1, 0 } }, { { -2, 1 } }, { { 0, 0 } },
};

dream_sys_mood_graph_point_t STG08_CHUNK_MOODS[] = {
    { { 7, 0 } },
    { { -7, 0 } },
    { { -7, 1 } },
    { { 0, 0 } },
};

dream_sys_mood_graph_point_t STG09_CHUNK_MOODS[] = {
    { { 0, -6 } },
    { { -2, -8 } },
};

dream_sys_mood_graph_point_t STG10_CHUNK_MOODS[] = {
    { { 5, -7 } },
    { { 4, -7 } },
    { { -4, -7 } },
    { { 0, 0 } },
};

dream_sys_mood_graph_point_t STG11_CHUNK_MOODS[] = {
    { { 9, 0 } },  { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } }, { { -4, 8 } },
    { { -3, 8 } }, { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } },
};

dream_sys_mood_graph_point_t STG12_CHUNK_MOODS[] = {
    { { 9, 0 } },   { { 9, 0 } },   { { 9, 0 } },  { { 9, 0 } }, { { 9, 0 } }, { { 6, 5 } }, { { 6, -5 } },
    { { 9, 0 } },   { { -6, -5 } }, { { -6, 5 } }, { { 0, 6 } }, { { 9, 0 } }, { { 9, 0 } }, { { 4, -3 } },
    { { -4, -3 } }, { { 9, 0 } },   { { 9, 0 } },  { { 9, 0 } }, { { 9, 0 } }, { { 9, 0 } },
};

dream_sys_mood_graph_point_t STG13_CHUNK_MOODS[] = {
    { { -1, 3 } },
    { { 9, 0 } },
    { { -1, 2 } },
    { { -2, 2 } },
};

dream_sys_mood_graph_point_t *STAGE_CHUNK_MOODS[] = {
    STG00_CHUNK_MOODS, STG01_CHUNK_MOODS, STG02_CHUNK_MOODS, STG03_CHUNK_MOODS, STG04_CHUNK_MOODS,
    STG05_CHUNK_MOODS, STG06_CHUNK_MOODS, STG07_CHUNK_MOODS, STG08_CHUNK_MOODS, STG09_CHUNK_MOODS,
    STG10_CHUNK_MOODS, STG11_CHUNK_MOODS, STG12_CHUNK_MOODS, STG13_CHUNK_MOODS,
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
        rows = *(s16 *) ((s8 *) &g_STAGE_GRID_DIMENSIONS[0].rows + dim_offset);
        columns = *(s16 *) ((s8 *) g_STAGE_GRID_DIMENSIONS + dim_offset);
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
