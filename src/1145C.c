#include "common.h"

extern void *D_8008A83C;

void *get_display(void) {
    return D_8008A83C;
}

void set_display(void *value) {
    D_8008A83C = value;
}
