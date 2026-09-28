#include "common.h"

extern s32 GsCLIP3near;
extern s32 GsOUT_PACKET_P;

void func_8003FB0C(s32 arg0) {
    GsCLIP3near = arg0;
}

INCLUDE_ASM("asm/nonmatchings/3030C", Gssub_make_matrix);

void func_8003FBE4(s32 arg0) {
    GsOUT_PACKET_P = arg0;
}
