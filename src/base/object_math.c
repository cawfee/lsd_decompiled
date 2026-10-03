#include "base/object_math.h"

#include <psx/libgs.h>
#include <psx/libgte.h>

#include "base/transform.h"
#include "scene/scene_node.h"

// todo cleanup file its a pain

extern s32 func_8001F8B8(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4, void *arg5);
void func_8001EA8C(s32 *arg0, s16 *arg1, s16 *arg2);
void func_8001EE98(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3);

void func_8001E58C(void *arg0, s32 *arg1, s16 *arg2) {
    s32 buf[8];
    void (*method)(void *, void *, s32);

    method = *(void (**)(void *, void *, s32))((u8 *) *(void **) arg0 + 0x84);
    method(arg0, buf, 0);
    arg1[0] = arg2[0];
    arg1[1] = arg2[1];
    arg1[2] = arg2[2];
    func_8001EE98((u8 *) arg1, (u8 *) arg1, 1, (u8 *) buf);
}

/* Transforms a local point by the object's matrix and adds the object's world
   position, writing the result to arg1. */
void transform_local_to_world(void *arg0, s32 *arg1, void *arg2) {
    s32 buf[8];
    void (*method)(void *, void *, s32);

    method = *(void (**)(void *, void *, s32))((u8 *) *(void **) arg0 + 0x84);
    method(arg0, buf, 0);
    func_8001EE98((u8 *) arg1, (u8 *) arg2, 1, (u8 *) buf);
    arg1[0] += ((vec3d_t *) (*(s32 *) ((u8 *) arg0 + 0xC) ? (u8 *) *(void **) ((u8 *) arg0 + 0x14) + 0x38 : 0))->x;
    arg1[1] += ((vec3d_t *) (*(s32 *) ((u8 *) arg0 + 0xC) ? (u8 *) *(void **) ((u8 *) arg0 + 0x14) + 0x38 : 0))->y;
    arg1[2] += ((vec3d_t *) (*(s32 *) ((u8 *) arg0 + 0xC) ? (u8 *) *(void **) ((u8 *) arg0 + 0x14) + 0x38 : 0))->z;
}

/* Reads the object's Euler rotation, converting GTE angle units (4096/rev) to
   degrees (360/rev), and writes three (angle, 1) pairs into arg1. */
void object_get_rotation_360(void *arg0, s16 *arg1) {
    s16 *src;

    src = *(s16 **) ((u8 *) *(void **) ((u8 *) arg0 + 0x14) + 0x44);
    arg1[0] = (src[8] * 45) >> 9;
    arg1[1] = 1;
    arg1[2] = (src[9] * 45) >> 9;
    arg1[3] = 1;
    arg1[4] = (src[10] * 45) >> 9;
    arg1[5] = 1;
}

void func_8001E770(void *arg0, void *arg1) {
    void *obj;

    *(void **) ((u8 *) arg0 + 0x20) = arg1;
    *(s32 *) ((u8 *) arg0 + 0x18) = *(s32 *) ((u8 *) arg1 + 0x10);
    obj = *(void **) ((u8 *) arg0 + 0x20);
    GsLinkObject4((u8 *) *(void **) ((u8 *) obj + 0xC) + 0xC, (u8 *) arg0 + 0x10, 0);
}

void func_8001E7B0(transform_t *This) {
    This->m_Unk5 = 0;
    This->m_Unk7 = 0;
}

s32 func_8001E7BC(scene_node_t *This, s32 *arg1, u16 *arg2) {
    vec4d_16_t vecA, vecB, vecC, vecD;
    s32 *a3;
    scene_node_t *scene_node;

    if (This->m_Unk7 != 0) {
        if (This->m_Unk3 < 0) {
            if (This->m_Unk2 != 0) {
                a3 = This->m_Unk4;
                if ((u8 *) a3 + 0x38 != 0) {
                    a3[0x38 / 4] = a3[0x18 / 4];
                    a3[0x3C / 4] = a3[0x1C / 4];
                    a3[0x40 / 4] = a3[0x20 / 4];
                    scene_node = This->m_Unk2;
                    if (scene_node != 0) {
                        do {
                            ((vec3d_t *) (This->m_Unk2 ? (u8 *) This->m_Unk4 + 0x38 : 0))->x +=
                                *(s32 *) ((u8 *) scene_node->m_Unk4 + 0x18);
                            ((vec3d_t *) (This->m_Unk2 ? (u8 *) This->m_Unk4 + 0x38 : 0))->y +=
                                *(s32 *) ((u8 *) scene_node->m_Unk4 + 0x1C);
                            ((vec3d_t *) (This->m_Unk2 ? (u8 *) This->m_Unk4 + 0x38 : 0))->z +=
                                *(s32 *) ((u8 *) scene_node->m_Unk4 + 0x20);
                            scene_node = scene_node->m_Unk2;
                        } while (scene_node != 0);
                    }
                }
            } else {
                a3 = 0;
                goto body;
            }
        }
        a3 = This->m_Unk2 ? (s32 *) ((u8 *) This->m_Unk4 + 0x38) : 0;
    body:
        vecB.x = ((u16 *) arg2)[0] - ((u16 *) a3)[0];
        vecB.y = ((u16 *) arg2)[2] - ((u16 *) a3)[2];
        vecB.z = ((u16 *) arg2)[4] - ((u16 *) a3)[4];
        ((void (*)(void *, s32, vec4d_16_t *, vec4d_16_t *, s32))((*(void ***) This)[0xA4 / 4]))(This, 0, &vecA, &vecB, 1);
        vecB.x = vecA.x;
        vecB.y = vecA.y - 0x400;
        vecB.z = vecA.z;
        if (func_8001F8B8(This->m_Unk7, &vecD, &vecC, 0, &vecA, &vecB) != 0) {
            func_8001EA8C(arg1, (s16 *) &vecA, (s16 *) &vecC);
            return 1;
        }
        vecB.y = vecA.y + 0x400;
        if (func_8001F8B8(This->m_Unk7, &vecD, &vecC, 0, &vecA, &vecB) != 0) {
            func_8001EA8C(arg1, (s16 *) &vecA, (s16 *) &vecC);
            return 1;
        }
    }
    return 0;
}

void func_8001EA8C(s32 *arg0, s16 *arg1, s16 *arg2) {
    arg0[0] = arg2[0] - arg1[0];
    arg0[1] = arg2[1] - arg1[1];
    arg0[2] = arg2[2] - arg1[2];
}

void func_8001EACC(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s16 vec[6];
    s32 *src;
    s32 *dst;

    src = (s32 *) ((u8 *) *(void **) ((u8 *) arg0 + 0x14) + 0x18);
    if (*(s32 *) ((u8 *) arg1 + 0xC) != 0) {
        dst = (s32 *) ((u8 *) *(void **) ((u8 *) arg1 + 0x14) + 0x38);
    } else {
        dst = 0;
    }
    if (dst[0] != src[0]) {
        vec[2] = ratan2(dst[0] - src[0], dst[2] - src[2]);
    } else {
        vec[2] = ratan2(1, dst[2] - src[2]);
    }
    if (dst[2] != src[2]) {
        vec[0] = ratan2(dst[2] - src[2], dst[1] - src[1]);
    } else {
        vec[0] = ratan2(1, dst[1] - src[1]);
    }
    vec[0] = (s16) (((vec[0] + 0x400) * 360) / 4096);
    vec[2] = (s16) ((vec[2] * 360) / 4096);
    vec[4] = 0;
    vec[5] = 1;
    vec[3] = 1;
    vec[1] = 1;
    if (arg2 != 0) {
        vec[0] = 0;
    }
    if (arg3 == 0) {
        vec[2] = vec[2] + 0xB4;
    }
    ((void (*)(void *, s32, s16 *))((*(void ***) arg0)[0x44 / 4]))(arg0, 1, vec);
    if (arg4 != 0) {
        ((void (*)(void *, s32, s16 *))((*(void ***) arg0)[0x44 / 4]))(arg0, 0, (s16 *) arg4);
    }
}

s32 func_8001EC84(void *arg0) {
    s16 a = ((s16 *) arg0)[0];
    s16 b = ((s16 *) arg0)[1];

    return ((a / b) << 12) + (((a % b) << 12) / b);
}

s32 func_8001ECFC(box3d_16_t *box, vec3d_16_t *pt) {
    s32 flags = 0;

    if (box->max.x < pt->x) {
        flags = 8;
    } else if (pt->x < box->min.x) {
        flags = 4;
    }

    if (box->max.y < pt->y) {
        flags |= 2;
    } else if (pt->y < box->min.y) {
        flags |= 1;
    }

    if (box->max.z < pt->z) {
        flags |= 0x20;
    } else if (pt->z < box->min.z) {
        flags |= 0x10;
    }

    return flags;
}

s32 func_8001EDAC(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad[2];
    s32 temp_t0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_t0;

    (void) pad;
    var_t0 = 1;
    var_a0 = 0;
    if (arg2 > 0) {
        do {
            var_a0 += 1;
            var_t0 *= 2;
        } while (var_a0 < arg2);
    }
    var_t0 -= 1;
    var_t0 <<= arg1;
    temp_v0 = *arg0;
    temp_t0 = ~var_t0 & temp_v0;
    *arg0 = (arg3 << arg1) | temp_t0;
    return (u32) (var_t0 & temp_v0) >> arg1;
}

void func_8001EE04(void *arg0, void *arg1, s32 arg2, void *arg3) {
    u8 *end = (u8 *) arg0 + arg2 * 6;

    while ((u8 *) arg0 < end) {
        vec3d_16_t v = *(vec3d_16_t *) arg1;
        ApplyMatrixSV(arg3, &v, arg0);
        arg0 = (u8 *) arg0 + 6;
        arg1 = (u8 *) arg1 + 6;
    }
}

void func_8001EE98(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    s32 pad[2];
    u8 *end = arg0 + arg2 * 12;

    (void) pad;
    while (arg0 < end) {
        ApplyMatrixLV(arg3, arg1, arg0);
        arg0 += 12;
        arg1 += 12;
    }
}

/* Returns non-zero when arg2 lies within +/- arg1 on every axis of arg0. */
s32 is_point_within_radius(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++, arg0++, arg2++) {
        if (*arg2 < *arg0 - arg1) {
            return 0;
        }
        if (*arg0 + arg1 < *arg2) {
            return 0;
        }
    }
    return 1;
}

extern s32 D_8008A838;

s32 func_8001EF60(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8008A838;
    D_8008A838 = arg0;
    return temp_v0;
}
