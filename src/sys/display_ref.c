#include "common.h"

void *g_Display = NULL;

void *get_display(void) {
    return g_Display;
}

void set_display(void *value) {
    g_Display = value;
}
