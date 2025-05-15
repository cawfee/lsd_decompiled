#ifndef PSX_LIBSPU_H
#define PSX_LIBSPU_H

#define SPU_OFF 0
#define SPU_ON 1

#define SPU_COMMON_MVOLL (1 << 0)
#define SPU_COMMON_MVOLR (1 << 1)
#define SPU_COMMON_MVOLMODEL (1 << 2)
#define SPU_COMMON_MVOLMODER (1 << 3)
#define SPU_COMMON_RVOLL (1 << 4)
#define SPU_COMMON_RVOLR (1 << 5)
#define SPU_COMMON_CDVOLL (1 << 6)
#define SPU_COMMON_CDVOLR (1 << 7)
#define SPU_COMMON_CDREV (1 << 8)
#define SPU_COMMON_CDMIX (1 << 9)
#define SPU_COMMON_EXTVOLL (1 << 10)
#define SPU_COMMON_EXTVOLR (1 << 11)
#define SPU_COMMON_EXTREV (1 << 12)
#define SPU_COMMON_EXTMIX (1 << 13)

typedef struct {
    short left;
    short right;
} spu_volume_t;

typedef struct {
    spu_volume_t volume;
    long reverb;
    long mix;
} spu_ext_attr_t;

typedef struct {
    unsigned long mask;

    spu_volume_t m_vol;
    spu_volume_t m_vol_mode;
    spu_volume_t m_vol_x;
    spu_ext_attr_t cd;
    spu_ext_attr_t ext;
} spu_common_attr_t;

extern void SpuSetCommonAttr(spu_common_attr_t *attr);

#endif