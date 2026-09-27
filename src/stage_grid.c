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

/* Per-stage mood grids, one entry per grid cell in row-major order.
 * Initialized through the union's first member: the low byte is
 * axis.dynamic and the high byte is axis.upper. */
dream_sys_mood_graph_point_t STG00_CHUNK_MOODS[] = {
    { 0xFD00 }, { 0x0101 }, { 0x01FF }, { 0x0000 }, { 0xF9FB }, { 0x0000 },
};

dream_sys_mood_graph_point_t STG01_CHUNK_MOODS[] = {
    { 0x0107 }, { 0x0201 }, { 0xFA08 }, { 0x0009 }, { 0xF700 }, { 0xFAF8 },
};

dream_sys_mood_graph_point_t STG02_CHUNK_MOODS[] = {
    { 0x0900 }, { 0x0501 }, { 0x0502 }, { 0x0402 }, { 0x0302 }, { 0x0303 }, { 0x0203 }, { 0x0204 },
    { 0x0104 }, { 0x0103 }, { 0x0003 }, { 0x0002 }, { 0xFF02 }, { 0xFF01 }, { 0xFE01 }, { 0xFC01 },
    { 0x0009 }, { 0xFB01 }, { 0xFB00 }, { 0xFBFF }, { 0xFCFF }, { 0xFEFF }, { 0xFFFF }, { 0xFFFE },
    { 0x00FE }, { 0x00FD }, { 0x01FD }, { 0x01FC }, { 0x02FC }, { 0x02FD }, { 0x03FD }, { 0x03FE },
    { 0x04FE }, { 0x05FE }, { 0x05FF }, { 0x0301 },
};

dream_sys_mood_graph_point_t STG03_CHUNK_MOODS[] = {
    { 0x0009 }, { 0x0009 }, { 0x0706 }, { 0x0606 }, { 0x0009 }, { 0x0009 }, { 0x0607 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0507 }, { 0x0009 }, { 0x0508 }, { 0x0509 }, { 0x0009 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0409 }, { 0x0309 }, { 0x0209 }, { 0x0109 }, { 0x0009 },
    { 0xFF09 }, { 0x0009 }, { 0xFE09 }, { 0xFD09 }, { 0xFC09 }, { 0xFB09 }, { 0xFB08 }, { 0xFB07 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0xFA07 }, { 0xFA06 }, { 0xF906 },
    { 0xF9FA }, { 0xFAFA }, { 0x0009 }, { 0xFAF9 }, { 0xFBF9 }, { 0xFBF8 }, { 0xFBF7 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0xFCF7 }, { 0xFDF7 }, { 0xFEF7 }, { 0xFFF7 }, { 0x00F7 },
    { 0x01F7 }, { 0x02F7 }, { 0x03F7 }, { 0x04F7 }, { 0x05F7 }, { 0x05F8 }, { 0x05F9 }, { 0x06F9 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x06FA }, { 0x07FA }, { 0x07FF }, { 0x0700 },
    { 0x0701 }, { 0x0601 }, { 0x0602 }, { 0x0603 }, { 0x0604 }, { 0x0605 }, { 0x0505 }, { 0x0009 },
    { 0x0009 }, { 0x0405 }, { 0x0406 }, { 0x0407 }, { 0x0408 }, { 0x0308 }, { 0x0208 }, { 0x0108 },
    { 0x0008 }, { 0xFF08 }, { 0xFE08 }, { 0xFD08 }, { 0xFC08 }, { 0xFC07 }, { 0xFC06 }, { 0x0009 },
    { 0x0009 }, { 0xFC05 }, { 0xFB05 }, { 0xFA05 }, { 0xFA04 }, { 0xFA03 }, { 0xFA02 }, { 0xFA01 },
    { 0xFAFF }, { 0xFAFE }, { 0xFAFD }, { 0xFAFC }, { 0xFAFB }, { 0x0009 }, { 0xFBFB }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0xFCFB }, { 0xFCFA }, { 0xFCF9 }, { 0xFCF8 }, { 0xFDF8 }, { 0xFEF8 },
    { 0xFFF8 }, { 0x00F8 }, { 0x01F8 }, { 0x02F8 }, { 0x03F8 }, { 0x04F8 }, { 0x04F9 }, { 0x0009 },
    { 0x0009 }, { 0x04FA }, { 0x04FB }, { 0x05FB }, { 0x06FB }, { 0x06FC }, { 0x06FD }, { 0x0009 },
    { 0x06FE }, { 0x06FF }, { 0x0503 }, { 0x0504 }, { 0x0404 }, { 0x0304 }, { 0x0305 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0306 }, { 0x0009 }, { 0x0307 }, { 0x0207 }, { 0xFF07 }, { 0xFE07 },
    { 0xFD07 }, { 0xFD06 }, { 0xFD05 }, { 0xFC04 }, { 0xFB04 }, { 0xFB03 }, { 0x0009 }, { 0x0009 },
    { 0x0009 }, { 0xFB02 }, { 0xFBFE }, { 0xFBFD }, { 0xFBFC }, { 0xFCFC }, { 0x0009 }, { 0xFDFB },
    { 0xFDFA }, { 0xFDF9 }, { 0xFEF9 }, { 0xFFF9 }, { 0x02F9 }, { 0x0009 }, { 0x0009 }, { 0x0009 },
    { 0x0009 }, { 0x03F9 }, { 0x03FA }, { 0x03FB }, { 0x03FC }, { 0x04FC }, { 0x05FC }, { 0x05FD },
    { 0x0500 }, { 0x0403 }, { 0x0205 }, { 0x0206 }, { 0x0106 }, { 0x0006 }, { 0xFF06 }, { 0x0009 },
    { 0x0009 }, { 0xFE06 }, { 0xFE05 }, { 0xFE04 }, { 0xFE03 }, { 0xFD03 }, { 0xFC03 }, { 0xFC02 },
    { 0xFCFE }, { 0xFCFD }, { 0xFDFD }, { 0x0009 }, { 0xFEFD }, { 0xFEFC }, { 0xFEFB }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0xFEFA }, { 0xFFFA }, { 0x00FA }, { 0x01FA }, { 0x02FA }, { 0x02FB },
    { 0x04FD }, { 0x04FF }, { 0x0400 }, { 0x0401 }, { 0x0105 }, { 0x0005 }, { 0xFF05 }, { 0x0009 },
    { 0x0009 }, { 0xFF04 }, { 0xFF03 }, { 0xFE02 }, { 0xFD02 }, { 0xFD01 }, { 0xFDFF }, { 0xFDFE },
    { 0xFEFE }, { 0xFFFD }, { 0xFFFC }, { 0xFFFB }, { 0x00FB }, { 0x01FB }, { 0x0009 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0004 }, { 0x00FC }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0000 }, { 0x0000 }, { 0x0009 },
};

dream_sys_mood_graph_point_t STG04_CHUNK_MOODS[] = {
    { 0x0905 }, { 0x0805 }, { 0x0707 }, { 0x0704 }, { 0x0703 }, { 0x0009 }, { 0x0702 }, { 0x07FE },
    { 0x07FD }, { 0x07FC }, { 0x07FB }, { 0x08FB }, { 0x09FB }, { 0x09FC }, { 0x09FD }, { 0x09FE },
    { 0x09FF }, { 0x0009 }, { 0x0901 }, { 0x0902 }, { 0x0903 }, { 0x0904 }, { 0x0804 }, { 0x0803 },
    { 0x0802 }, { 0x0801 }, { 0x0800 }, { 0x08FF }, { 0x08FE }, { 0x0009 },
};

dream_sys_mood_graph_point_t STG05_CHUNK_MOODS[] = {
    { 0xF903 }, { 0xF803 }, { 0xF804 }, { 0xF805 }, { 0xF705 }, { 0x0009 }, { 0xF704 }, { 0xF703 },
    { 0xF702 }, { 0xF701 }, { 0xF8FF }, { 0xF7FF }, { 0xF7FE }, { 0xF7FD }, { 0xF7FC }, { 0x0009 },
    { 0xF7FB }, { 0xF8FB }, { 0xF8FC }, { 0xF8FD }, { 0x0009 }, { 0xF9FD }, { 0xF9FE }, { 0xF9FF },
    { 0xF900 }, { 0xF901 }, { 0xF902 }, { 0xF802 }, { 0xF801 }, { 0xF800 },
};

dream_sys_mood_graph_point_t STG06_CHUNK_MOODS[] = {
    { 0xFC00 }, { 0xFE00 }, { 0xFF00 }, { 0x0100 }, { 0x0200 }, { 0x0201 },
};

dream_sys_mood_graph_point_t STG07_CHUNK_MOODS[] = {
    { 0x0202 }, { 0x0102 }, { 0x0001 }, { 0x00FF }, { 0x01FE }, { 0x0000 },
};

dream_sys_mood_graph_point_t STG08_CHUNK_MOODS[] = {
    { 0x0007 }, { 0x00F9 }, { 0x01F9 }, { 0x0000 },
};

dream_sys_mood_graph_point_t STG09_CHUNK_MOODS[] = {
    { 0xFA00 }, { 0xF8FE },
};

dream_sys_mood_graph_point_t STG10_CHUNK_MOODS[] = {
    { 0xF905 }, { 0xF904 }, { 0xF9FC }, { 0x0000 },
};

dream_sys_mood_graph_point_t STG11_CHUNK_MOODS[] = {
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x08FC }, { 0x08FD }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 },
};

dream_sys_mood_graph_point_t STG12_CHUNK_MOODS[] = {
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0506 }, { 0xFB06 }, { 0x0009 },
    { 0xFBFA }, { 0x05FA }, { 0x0600 }, { 0x0009 }, { 0x0009 }, { 0xFD04 }, { 0xFDFC }, { 0x0009 },
    { 0x0009 }, { 0x0009 }, { 0x0009 }, { 0x0009 },
};

dream_sys_mood_graph_point_t STG13_CHUNK_MOODS[] = {
    { 0x03FF }, { 0x0009 }, { 0x02FF }, { 0x02FE },
};

dream_sys_mood_graph_point_t *STAGE_CHUNK_MOODS[] = {
    STG00_CHUNK_MOODS, STG01_CHUNK_MOODS, STG02_CHUNK_MOODS, STG03_CHUNK_MOODS,
    STG04_CHUNK_MOODS, STG05_CHUNK_MOODS, STG06_CHUNK_MOODS, STG07_CHUNK_MOODS,
    STG08_CHUNK_MOODS, STG09_CHUNK_MOODS, STG10_CHUNK_MOODS, STG11_CHUNK_MOODS,
    STG12_CHUNK_MOODS, STG13_CHUNK_MOODS,
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
