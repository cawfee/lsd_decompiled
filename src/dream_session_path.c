#include "common.h"

s32 D_8008A978 = 0;
s32 D_8008A97C = 0;

const char *get_path_table(s32 *Count);
s32 func_80027024(s32 arg0, s32 arg1);

s32 func_8004A070(s32 arg0) {
    s32 count;
    s32 path_table;
    s32 prev;
    s32 step;
    s32 result;

    path_table = (s32)get_path_table(&count);
    prev = D_8008A978;
    step = prev + 1;
    D_8008A978 = step;
    switch (step) {
    case 1:
        if (arg0 != 0) {
            D_8008A978 = prev + 2;
        } else {
            count = count / 2;
            D_8008A97C = count;
        }
        break;
    case 2:
        count -= D_8008A97C;
        break;
    default:
        count = 0;
        break;
    }
    do {
        result = func_80027024(path_table, count);
    } while (result == 0);
    return result;
}
