#include "common.h"

extern void GsLinkObject4(u8 *obj, void *coord, s32 offset);
extern void ApplyMatrixSV(void *mtx, void *v0, void *v1);
extern void ApplyMatrixLV(void *mtx, void *v0, void *v1);
extern s16 ratan2(s32, s32);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} sv6_t;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} vec_t;

typedef struct {
    s16 min_x;
    s16 min_y;
    s16 min_z;
    s16 max_x;
    s16 max_y;
    s16 max_z;
} box_t;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} pt_t;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} sv8_t;

typedef struct e7bc_obj {
    void *vtable;
    s32 m_Unk0;
    s32 m_Unk1;
    s32 m_Unk2;
    s32 m_Unk3;
    void *m_Unk4;
    s32 m_Unk5;
    s32 m_Unk6;
    s32 m_Unk7;
} e7bc_obj_t;

extern s32 func_8001F8B8(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4, void *arg5);
void func_8001EA8C(s32 *arg0, s16 *arg1, s16 *arg2);
void func_8001EE98(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3);

void func_8001E58C(void *arg0, s32 *arg1, s16 *arg2) {
    s32 buf[8];
    void (*method)(void *, void *, s32);

    method = *(void (**)(void *, void *, s32))((u8 *)*(void **)arg0 + 0x84);
    method(arg0, buf, 0);
    arg1[0] = arg2[0];
    arg1[1] = arg2[1];
    arg1[2] = arg2[2];
    func_8001EE98((u8 *)arg1, (u8 *)arg1, 1, (u8 *)buf);
}

void func_8001E600(void *arg0, s32 *arg1, void *arg2) {
    s32 buf[8];
    void (*method)(void *, void *, s32);

    method = *(void (**)(void *, void *, s32))((u8 *)*(void **)arg0 + 0x84);
    method(arg0, buf, 0);
    func_8001EE98((u8 *)arg1, (u8 *)arg2, 1, (u8 *)buf);
    arg1[0] += ((vec_t *)(*(s32 *)((u8 *)arg0 + 0xC) ? (u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x38 : 0))->x;
    arg1[1] += ((vec_t *)(*(s32 *)((u8 *)arg0 + 0xC) ? (u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x38 : 0))->y;
    arg1[2] += ((vec_t *)(*(s32 *)((u8 *)arg0 + 0xC) ? (u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x38 : 0))->z;
}

void func_8001E6F8(void *arg0, s16 *arg1) {
    s16 *src;

    src = *(s16 **)((u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x44);
    arg1[0] = (src[8] * 45) >> 9;
    arg1[1] = 1;
    arg1[2] = (src[9] * 45) >> 9;
    arg1[3] = 1;
    arg1[4] = (src[10] * 45) >> 9;
    arg1[5] = 1;
}

void func_8001E770(void *arg0, void *arg1) {
    void *obj;

    *(void **)((u8 *)arg0 + 0x20) = arg1;
    *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)arg1 + 0x10);
    obj = *(void **)((u8 *)arg0 + 0x20);
    GsLinkObject4((u8 *)*(void **)((u8 *)obj + 0xC) + 0xC, (u8 *)arg0 + 0x10, 0);
}

void func_8001E7B0(void *arg0) {
    ((s32 *)arg0)[6] = 0;
    ((s32 *)arg0)[8] = 0;
}

s32 func_8001E7BC(e7bc_obj_t *arg0, s32 *arg1, u16 *arg2) {
    sv8_t vecA, vecB, vecC, vecD;
    s32 *a3;
    e7bc_obj_t *node;

    if (arg0->m_Unk7 != 0) {
        if (arg0->m_Unk3 < 0) {
            if (arg0->m_Unk2 != 0) {
                a3 = arg0->m_Unk4;
                if ((u8 *)a3 + 0x38 != 0) {
                    a3[0x38 / 4] = a3[0x18 / 4];
                    a3[0x3C / 4] = a3[0x1C / 4];
                    a3[0x40 / 4] = a3[0x20 / 4];
                    node = (e7bc_obj_t *)arg0->m_Unk2;
                    if (node != 0) {
                        do {
                            ((vec_t *)(arg0->m_Unk2 ? (u8 *)arg0->m_Unk4 + 0x38 : 0))->x +=
                                *(s32 *)((u8 *)node->m_Unk4 + 0x18);
                            ((vec_t *)(arg0->m_Unk2 ? (u8 *)arg0->m_Unk4 + 0x38 : 0))->y +=
                                *(s32 *)((u8 *)node->m_Unk4 + 0x1C);
                            ((vec_t *)(arg0->m_Unk2 ? (u8 *)arg0->m_Unk4 + 0x38 : 0))->z +=
                                *(s32 *)((u8 *)node->m_Unk4 + 0x20);
                            node = (e7bc_obj_t *)node->m_Unk2;
                        } while (node != 0);
                    }
                }
            } else {
                a3 = 0;
                goto body;
            }
        }
        a3 = arg0->m_Unk2 ? (s32 *)((u8 *)arg0->m_Unk4 + 0x38) : 0;
body:
        vecB.x = ((u16 *)arg2)[0] - ((u16 *)a3)[0];
        vecB.y = ((u16 *)arg2)[2] - ((u16 *)a3)[2];
        vecB.z = ((u16 *)arg2)[4] - ((u16 *)a3)[4];
        ((void (*)(void *, s32, sv8_t *, sv8_t *, s32))((*(void ***)arg0)[0xA4 / 4]))(arg0, 0, &vecA, &vecB, 1);
        vecB.x = vecA.x;
        vecB.y = vecA.y - 0x400;
        vecB.z = vecA.z;
        if (func_8001F8B8(arg0->m_Unk7, &vecD, &vecC, 0, &vecA, &vecB) != 0) {
            func_8001EA8C(arg1, (s16 *)&vecA, (s16 *)&vecC);
            return 1;
        }
        vecB.y = vecA.y + 0x400;
        if (func_8001F8B8(arg0->m_Unk7, &vecD, &vecC, 0, &vecA, &vecB) != 0) {
            func_8001EA8C(arg1, (s16 *)&vecA, (s16 *)&vecC);
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

    src = (s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x18);
    if (*(s32 *)((u8 *)arg1 + 0xC) != 0) {
        dst = (s32 *)((u8 *)*(void **)((u8 *)arg1 + 0x14) + 0x38);
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
    vec[0] = (s16)(((vec[0] + 0x400) * 360) / 4096);
    vec[2] = (s16)((vec[2] * 360) / 4096);
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
    ((void (*)(void *, s32, s16 *))((*(void ***)arg0)[0x44 / 4]))(arg0, 1, vec);
    if (arg4 != 0) {
        ((void (*)(void *, s32, s16 *))((*(void ***)arg0)[0x44 / 4]))(arg0, 0, (s16 *)arg4);
    }
}

s32 func_8001EC84(void *arg0) {
    s16 a = ((s16 *)arg0)[0];
    s16 b = ((s16 *)arg0)[1];

    return ((a / b) << 12) + (((a % b) << 12) / b);
}

s32 func_8001ECFC(box_t *box, pt_t *pt) {
    s32 flags = 0;

    if (box->max_x < pt->x) {
        flags = 8;
    } else if (pt->x < box->min_x) {
        flags = 4;
    }
    if (box->max_y < pt->y) {
        flags |= 2;
    } else if (pt->y < box->min_y) {
        flags |= 1;
    }
    if (box->max_z < pt->z) {
        flags |= 0x20;
    } else if (pt->z < box->min_z) {
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

    (void)pad;
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
    return (u32)(var_t0 & temp_v0) >> arg1;
}

void func_8001EE04(void *arg0, void *arg1, s32 arg2, void *arg3) {
    u8 *end = (u8 *)arg0 + arg2 * 6;

    while ((u8 *)arg0 < end) {
        sv6_t v = *(sv6_t *)arg1;
        ApplyMatrixSV(arg3, &v, arg0);
        arg0 = (u8 *)arg0 + 6;
        arg1 = (u8 *)arg1 + 6;
    }
}

void func_8001EE98(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    s32 pad[2];
    u8 *end = arg0 + arg2 * 12;

    (void)pad;
    while (arg0 < end) {
        ApplyMatrixLV(arg3, arg1, arg0);
        arg0 += 12;
        arg1 += 12;
    }
}

s32 func_8001EF14(s32 *arg0, s32 arg1, s32 *arg2) {
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
