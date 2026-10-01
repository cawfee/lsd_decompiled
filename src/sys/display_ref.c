#include "graphics/display.h"

display_t *g_Display = NULL;

display_t *get_display(void) {
    return g_Display;
}

void set_display(display_t *value) {
    g_Display = value;
}
