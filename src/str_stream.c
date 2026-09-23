#include <psx/libcd.h>
#include <psx/libspu.h>

#include "str_stream.h"

extern long CdControlF(unsigned char, unsigned char *);
extern long CdRead2(long);
extern void StSetStream(unsigned long, unsigned long, unsigned long, void *, void *);
#include "base_class.h"

// CD related class?

extern str_stream_vtable_t D_800817E0;

extern str_stream_t *D_8008A950;

str_stream_t *func_80046F0C(s32 Unk1, s32 Unk2, s32 Unk3) {
    str_stream_t *allocated = (str_stream_t *) memory_allocate_mem(0x5C);

    if (allocated) {
        func_80047900()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80046F88(str_stream_t *This, u32 Unk2, s32 Unk3, s32 Unk4) {
    base_class_get_vtable()->base_class_construct(This);
    This->vtable = func_80047900();
    This->m_Unk12 = Unk2;

    This->m_Unk11 = 0;

    if (Unk2 < 4) {
        This->m_Unk13 = 2054 * (300 / Unk3 / 2);
    } else {
        This->m_Unk13 = 2054 * (150 / Unk3 / 2);
    }

    This->m_Unk14 = Unk4;
    This->m_Unk19 = 0;
    This->m_Unk18 = 0;
    This->m_Unk17 = 0;
    This->m_Unk20 = 0;
    This->m_Unk10 = 0;
}

void func_80047074(str_stream_t *This) {
    This->vtable->Unk17(This);
    base_class_get_vtable()->base_class_cleanup(This);
}

void func_800470C8(str_stream_t *This, s32 Unk2, u32 Unk3) {
    if (!This->m_Unk10) {
        StSetRing(Unk2, Unk3 >> 11);
        This->m_Unk19 = Unk2;
    }
}

INCLUDE_ASM("asm/nonmatchings/str_stream", func_80047114);

s32 func_80047240(str_stream_t *This) {
    spu_common_attr_t attributes;
    attributes.mask = (SPU_COMMON_MVOLL | SPU_COMMON_MVOLR | SPU_COMMON_CDVOLL | SPU_COMMON_CDVOLR | SPU_COMMON_CDMIX);

    attributes.m_vol.left = 0x3FFF;
    attributes.m_vol.right = 0x3FFF;

    attributes.cd.volume.left = 0x7FFF;
    attributes.cd.volume.right = 0x7FFF;

    attributes.cd.mix = SPU_ON;

    SpuSetCommonAttr(&attributes);
    return 1;
}

void func_8004728C(str_stream_t *This) {
    str_stream_t *cur;

    if (This->m_Unk10 != 0) {
        cur = D_8008A950;
        if (cur == This) {
            cur->vtable->Unk20(cur);
            cur->m_Unk10 = 0;
            D_8008A950 = NULL;
        }
    }
}

// gp
void func_80047388(str_stream_t *This);

void func_800472EC(str_stream_t *This, void *arg1) {
    if (This->m_Unk10 != 2) {
        if (D_8008A950 == This) {
            if (This->m_Unk20 != 0) {
                CdSyncCallback((void *)func_80047388);
                CdControlF(0x15, arg1);
            } else {
                do {
                } while (CdControl(0x15, arg1, 0) == 0);
            }
            This->m_Unk10 = 1;
        }
    }
}

void func_80047388(str_stream_t *This) {
    if ((D_8008A950 != NULL) && ((u8) This == 2)) {
        CdSyncCallback(0);
        
        if (D_8008A950->m_Unk20) {
            ((void (*)(s32)) D_8008A950->m_Unk20)(D_8008A950->m_Unk16);
        }
    }
}

// gp
void func_800473E4(str_stream_t *This, s32 arg1, s32 arg2) {
    s32 mode;

    if (This->m_Unk10 == 1) {
        if (D_8008A950 == This) {
            mode = 0x140;
            if (This->m_Unk12 < 4) {
                mode = 0x1C0;
            }
            if (arg2 != 0) {
                This->m_Unk15 = arg2;
            }
            This->m_Unk21 = 0;
            StSetStream(0, arg1, -1, NULL, NULL);
            This->vtable->Unk24(This);
            do {
                while (CdControl(2, (unsigned char *)This + 0xC, 0) == 0) {
                }
            } while (CdRead2(mode) == 0);
            This->vtable->Unk25(This);
            This->m_Unk10 = 2;
        }
    }
}

// gp
void func_800474C8(str_stream_t *This) {
    if (This->m_Unk10 == 2) {
        if (D_8008A950 == This) {
            This->vtable->Unk24(This);
            This->vtable->Unk29(This);
            This->vtable->Unk28(This);
            do {
            } while (CdControl(9, 0, 0) == 0);
            This->m_Unk10 = 4;
        }
    }
}

void func_80047574(str_stream_t *This) {
    if ((This->m_Unk10 == 4) && (D_8008A950 == This)) {
        D_8008A950->m_Unk10 = 0;
        D_8008A950->vtable->Unk18(D_8008A950, &D_8008A950->m_Unk2);
    }
}

void func_800475C8(void) {
}

void func_800475D0(void) {
}

void func_800475D8(str_stream_t *This) {
    if (This->m_Unk11 == 0) {
        if (D_8008A950 == This) {
            do {
            } while (CdControl(0xB, 0, 0) == 0);
            This->m_Unk11 = 1;
        }
    }
}

void func_80047638(str_stream_t *This) {
    if ((This->m_Unk11 != 0) && (D_8008A950 == This)) {
        do {

        } while (CdControl(0xC, 0, 0) == 0);
        This->m_Unk11 = 0;
    }
}

extern int StGetNext(u32 *ring, u32 **header);
void func_800477B0(str_stream_t *This, s32 Unk);
void func_80047810(str_stream_t *This);

s32 func_80047694(str_stream_t *This, u32 *ring, s32 *out, s32 count) {
    u32 *header;
    s32 result;
    s32 value;

    if (count < 0) {
        count = 0x800000;
    }
    do {
        result = StGetNext(ring, &header);
        count -= 1;
    } while (result != 0 && count >= 0);
    if (result != 0) {
        This->vtable->Unk27(This, ring);
        return 0;
    }
    value = header[2];
    *out = value;
    if (This->m_Unk15 <= 0) {
        goto accept;
    }
    if ((u32)value >= (u32)This->m_Unk15) {
        goto reject;
    }
    if ((u32)value >= (u32)This->m_Unk21) {
        goto store;
    }
reject:
    if ((u32)value < (u32)This->m_Unk21) {
        *out = 0;
    }
    ((void (*)(str_stream_t *, s32, s32))func_800477B0)(This, ring[0], *out);
    func_80047810(This);
    return -1;
store:
    This->m_Unk21 = value;
accept:
    ((void (*)(str_stream_t *, s32, s32))func_800477B0)(This, ring[0], *out);
    return 1;
}

void func_800477B0(str_stream_t *This, s32 Unk) {
    if (This->m_Unk17) {
        ((void (*)(s32))This->m_Unk17)(This->m_Unk16);
        ((void (*)(void *, s32))This->vtable->Unk27)(This, Unk);
    }
}

void func_80047810(str_stream_t *This) {
    if (This->m_Unk18) {
        ((void (*)(s32))This->m_Unk17)(This->m_Unk16);
    This->vtable->Unk17(This);
    }
}

u32 func_80047870(str_stream_t *This, u32 Base) {
    return StFreeRing(Base);
}

void func_80047890() {
    StUnSetRing();
}

void func_800478B0(void) {
    StClearRing();
}

s32 func_800478D0(str_stream_t *This, s32 Mode) {
    return CdSync(Mode, &This->m_Unk8);
}

void func_800478F8(void) {
}

str_stream_vtable_t *func_80047900(void) {
    return &D_800817E0;
}
