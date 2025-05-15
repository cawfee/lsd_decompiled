#ifndef LSD_BASE_CLASS_H
#define LSD_BASE_CLASS_H

typedef struct base_class_vtable {
    /* 0x000 8006b58c */ u32 value;
    /* 0x004 8006b590 */ void (*Destroy)(void *);
    /* 0x008 8006b594 */ void (*Construct)(void *);
    /* 0x00C 8006b598 */ void (*Cleanup)(void *);
    /* 0x010 8006b59c */ void (*Unk3)(void *, void *);
    /* 0x014 8006b5a0 */ void (*Unk4)(void *, void *);
    /* 0x018 8006b5a4 */ void (*Unk5)(void *);
    /* 0x01C 8006b5a8 */ void (*Unk6)(void *, void *, void **);
    /* 0x020 8006b5ac */ void (*Unk7)(void *, void *);
    /* 0x024 8006b5b0 */ void (*Unk8)(void *, void *);
    /* 0x028 8006b5b4 */ void (*Unk9)(void *);
    /* 0x02C 8006b5b8 */ void (*Unk10)(void *, void *, void **);
    /* 0x030 8006b5bc */ void (*Unk11)(void *, s32);
    /* 0x034 8006b5c0 */ void (*Unk12)(void *);
    /* 0x038 8006b5c4 */ void (*Unk13)(void *, void *, s32);
} base_class_vtable_t;

typedef struct base_class {
    /* 0x00 */ base_class_vtable_t *vtable;
    /* 0x04 */ void *m_Unk0;
    /* 0x08 */ s32 m_Unk1;
} base_class_t;

base_class_vtable_t *base_class_get_vtable(void);

#endif