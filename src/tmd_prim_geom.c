#include "common.h"

/* Non-zero while at least one class_FA50 (TMD primitive/object) instance is
   alive; see class_FA50_reset_flag / class_FA50_is_active. Address-only
   symbol (D_8008AC4C), defined via undefined_syms_auto.txt. */
extern s32 D_8008AC4C;

void class_FA50_reset_flag(void) {
    D_8008AC4C = 1;
}

s32 class_FA50_is_active(s32 arg0) {
    return D_8008AC4C;
}

typedef struct {
    s16 x, y, z;
} vec3s_t;

typedef struct {
    vec3s_t min;
    vec3s_t max;
} bbox_t;

typedef struct {
    s16 *verts;
    s32 count;
} vtx_list_t;

typedef struct {
    s32 unk0;
    s16 v[24];
} cube_t;

INCLUDE_ASM("asm/nonmatchings/tmd_prim_geom", func_8001F3B0);

/*
 * Best match attempt (from IDA; semantically exact). GCC 2.6.3 picks the y
 * pointer as the min/max induction-variable base and a 0x30 frame; the target
 * bases on the z pointer (y = a2-2, x = t0) with a 0x38 frame.
 *
 * void func_8001F3B0(s32 arg0, s16 *arg1) {
 *     vtx_list_t *list = *(vtx_list_t **)(arg0 + 0x10);
 *     s16 *src = list->verts;
 *     s16 *px = src + 4;
 *     s16 *v4 = arg1 + 1;
 *     s16 *v5 = arg1 + 2;
 *     s16 *v7 = arg1 + 3;
 *     s16 *v10 = arg1 + 4;
 *     s16 *v14 = arg1 + 5;
 *     s32 i = 0;
 *     s32 n = list->count - 1;
 *
 *     arg1[0] = src[0];
 *     arg1[1] = src[1];
 *     arg1[2] = src[2];
 *     ((vec3s_t *)arg1)[1] = ((vec3s_t *)arg1)[0];
 *     if (n > 0) {
 *         do {
 *             if (px[0] < arg1[0]) arg1[0] = px[0];
 *             if (px[1] < *v4) *v4 = px[1];
 *             if (px[2] < *v5) *v5 = px[2];
 *             if (*v7 < px[0]) *v7 = px[0];
 *             if (*v10 < px[1]) *v10 = px[1];
 *             if (*v14 < px[2]) *v14 = px[2];
 *             px += 4;
 *             i++;
 *         } while (i < n);
 *     }
 * }
 */

void func_8001F3B0(s32 arg0, s16 *arg1);

/* Shared 24-vertex source buffer (D_8008B21C; address-only symbol, rename
   pending a symbols.txt entry). */
extern s16 D_8008B21C[];

/* Copies the model geometry's bounding box into the shared vertex buffer. */
void refresh_source_vertices(s32 arg0) {
    func_8001F3B0(arg0, D_8008B21C);
}

/* Returns the shared 24-vertex source buffer. */
void *get_source_vertices(void) {
    return &D_8008B21C;
}

typedef struct {
    s32 one;
    s16 buf[6];
} tmp_t;

INCLUDE_ASM("asm/nonmatchings/tmd_prim_geom", func_8001F51C);

/*
 * Best match attempt (only the `one` local's register/spill differs: target
 * keeps it live in v1 and reloads nothing, this build puts it in v0 and
 * reloads it before the final store). No block-move opcodes exist in the
 * target, so __builtin_memcpy does not apply here.
 *
 * void func_8001F51C(s32 arg0, cube_t *arg1) {
 *     tmp_t tmp;
 *
 *     func_8001F3B0(arg0, tmp.buf);
 *     tmp.one = 1;
 *     arg1->v[0] = tmp.buf[0];
 *     arg1->v[1] = tmp.buf[1];
 *     arg1->v[2] = tmp.buf[2];
 *     arg1->v[3] = tmp.buf[0];
 *     arg1->v[4] = tmp.buf[4];
 *     arg1->v[5] = tmp.buf[2];
 *     arg1->v[6] = tmp.buf[3];
 *     arg1->v[7] = tmp.buf[4];
 *     arg1->v[8] = tmp.buf[2];
 *     arg1->v[9] = tmp.buf[3];
 *     arg1->v[10] = tmp.buf[1];
 *     arg1->v[11] = tmp.buf[2];
 *     arg1->v[12] = tmp.buf[0];
 *     arg1->v[13] = tmp.buf[1];
 *     arg1->v[14] = tmp.buf[5];
 *     arg1->v[15] = tmp.buf[0];
 *     arg1->v[16] = tmp.buf[4];
 *     arg1->v[17] = tmp.buf[5];
 *     arg1->v[18] = tmp.buf[3];
 *     arg1->v[19] = tmp.buf[4];
 *     arg1->v[20] = tmp.buf[5];
 *     arg1->v[21] = tmp.buf[3];
 *     arg1->v[22] = tmp.buf[1];
 *     arg1->unk0 = tmp.one;
 *     arg1->v[23] = tmp.buf[5];
 * }
 */

typedef struct {
    u16 vx, vy, vz;
} svec_t;

void func_8001F66C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    svec_t buf[8];

    for (i = 0; i < *(s32 *)arg0; i++) {
        svec_t *p = (svec_t *)((u8 *)arg0 + 4 + i * 0x30);

        if (arg1 != 0) {
            __builtin_memcpy(buf, p, 48);
            p[3] = buf[0];
            p[2] = buf[1];
            p[6] = buf[2];
            p[7] = buf[3];
            p[0] = buf[4];
            p[1] = buf[5];
            p[5] = buf[6];
            p[4] = buf[7];
            if (arg2 == 0) {
                s32 j;
                for (j = 0; j < 4; j++) p[j].vx = p[j].vx + arg3;
            } else {
                s32 j;
                for (j = 0; j < 4; j++) p[4 + j].vx = p[4 + j].vx + arg3;
            }
        } else if (arg2 == 0) {
            s32 j;
            for (j = 0; j < 4; j++) p[j].vz = p[j].vz + arg3;
        } else {
            s32 j;
            for (j = 0; j < 4; j++) p[4 + j].vz = p[4 + j].vz + arg3;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/tmd_prim_geom", func_8001F8B8);

INCLUDE_ASM("asm/nonmatchings/tmd_prim_geom", func_80020050);

void func_800204D0(s32 arg0, s32 *arg1) {
    u16 *p = *(u16 **)(*(u32 *)(arg0 + 0x10) + 0x10);
    s32 v;

    p[3] += arg1[0] / 16;
    v = arg1[1];
    p[3] += v << 6;
}

s32 func_80020510(s32 arg0, s16 *arg1) {
    u16 *p = *(u16 **)(*(u32 *)(arg0 + 0x10) + 0x10);
    s32 r;

    p[3] = arg1[0] / 16;
    r = arg1[1] << 6;
    p[3] += r;
    return r;
}
