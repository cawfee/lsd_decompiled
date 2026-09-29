#include "common.h"

#include "dream_session_path.h"

/* Cursor state for dream_session_path_advance: current step and the half-table
   count captured on the first (arg0 == 0) call. */
s32 g_DreamPathStep = 0;
s32 g_DreamPathHalfCount = 0;

const char *get_path_table(s32 *Count);
s32 file_driver_lookup_path(s32 arg0, s32 arg1);

s32 dream_session_path_advance(s32 arg0) {
    s32 count;
    s32 path_table;
    s32 prev;
    s32 step;
    s32 result;

    path_table = (s32)get_path_table(&count);
    prev = g_DreamPathStep;
    step = prev + 1;
    g_DreamPathStep = step;
    switch (step) {
    case 1:
        if (arg0 != 0) {
            g_DreamPathStep = prev + 2;
        } else {
            count = count / 2;
            g_DreamPathHalfCount = count;
        }
        break;
    case 2:
        count -= g_DreamPathHalfCount;
        break;
    default:
        count = 0;
        break;
    }
    do {
        result = file_driver_lookup_path(path_table, count);
    } while (result == 0);
    return result;
}
