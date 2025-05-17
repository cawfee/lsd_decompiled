#include "stage_grid.h"

// https://github.com/FirecatFG/lsddecomp/blob/main/src/lsdde/StageGrid.c

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

stage_grid_dimensions_t *stage_grid_get_dimension_table(s32 *Length) {
    if (Length) {
        *Length = STAGE_GRID_DIMENSION_COUNT;
    }

    return &g_STAGE_GRID_DIMENSIONS;
}

stage_grid_dimensions_t *stage_grid_get_dimension(s32 Index) {
    return &stage_grid_get_dimension_table(NULL)[Index];
}

INCLUDE_ASM("asm/nonmatchings/stage_grid", GetStageChunkFromMood);

INCLUDE_ASM("asm/nonmatchings/stage_grid", GetMoodFromStageChunk);
