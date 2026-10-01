#include "gfx/renderer.h"
#include "base/base_class.h"
#include "gfx/effect.h"
#include "base/transform.h"

#include <psx/libgte.h>

extern renderer_vtable_t g_RENDERER_VTABLE;
extern s32 D_8008A904[];
extern s32 D_8008A90C[];
extern s8 D_8008A8F8[];
extern s32 D_8008A8FC;
extern s32 D_8008A900;
extern s32 D_8008A8F4[];

transform_t *func_8001CA94(void);
s32 GsSetRefView2(void *);

renderer_t *renderer_create(void) {
    renderer_t *memory = (renderer_t *) memory_allocate_mem(0xBC);

    if (memory != 0) {
        renderer_get_vtable()->Construct(memory);
        return memory;
    }

    return NULL;
}

void func_8003E628(renderer_t *This) {
    effect_t *temp_v0;

    base_class_get_vtable()->Construct(This);
    This->vtable = renderer_get_vtable();
    This->m_Unk2 = 0;
    This->m_Unk3 = 0;
    This->m_Unk42 = (s32)func_8001CA94();
    temp_v0 = effect_create((s32)&D_8008A90C, 0, 0);
    This->m_Unk43 = (s32)temp_v0;
    temp_v0->vtable->Unk18(temp_v0, (entity_t *)This->m_Unk42, (s32)&D_8008A904);
    This->vtable->Unk15(This);
}

void func_8003E6CC(renderer_t *This) {
    void *temp_a0;

    This->vtable->Unk35(This);
    This->vtable->Unk28(This);
    temp_a0 = (void *)This->m_Unk42;
    (*(void (**)(void *))(*(s32 *)temp_a0 + 4))(temp_a0);
    ((void (*)(void *, s32))This->vtable->Unk41)(This, 0);
    base_class_get_vtable()->Cleanup(This);
}

void func_8003E770(renderer_t *This, void **arg1) {
    s32 temp_v1;

    base_class_get_vtable()->Attach(This, arg1);
    temp_v1 = *(s32 *)*arg1 & 0xF;
    if (temp_v1 == 4) {
        This->m_Unk3 = (s32)arg1;
        This->m_Unk11 = ((s32 *)arg1)[5];
        return;
    }
    if (temp_v1 == 1) {
        This->m_Unk2 = (s32)arg1;
    }
}

void func_8003E7F4(renderer_t *This, void **Unk) {
    s32 kind;

    kind = *(u32 *)*Unk & 0xF;
    if (kind == 4) {
        This->m_Unk11 = 0;
        This->m_Unk3 = 0;
    } else if (kind == 1) {
        This->m_Unk2 = 0;
    }
    base_class_get_vtable()->Detach(This, Unk);
}

void func_8003E874(renderer_t *This) {
    This->m_Unk11 = 0;
  This->m_Unk3 = 0;
  This->m_Unk2 = 0;
  base_class_get_vtable()->DetachAll(This);
}

void func_8003E8B8(renderer_t *This, void **Unk1, s32 Unk2) {
    s32 kind;

    ((void (*)(void *, void **, s32))base_class_get_vtable()->OnNotify)(This, Unk1, Unk2);
    kind = *(u32 *)*Unk1 & 0xF;
    if (kind == 5) {
        ((void (*)(void *, void **, s32))This->vtable->Unk36)(This, Unk1, Unk2);
    } else if (kind == 1) {
        ((void (*)(void *, void **, s32))This->vtable->Unk37)(This, Unk1, Unk2);
    }
}

typedef struct {
    s32 w;
    s32 h;
} renderer_wh_t;

#if 0
/* Best match (39/41 insns): insns 1-19 are byte-identical to the stub.  The
 * residual is GCC 2.6.3 scheduling/regalloc, not source shape:
 *   - target keeps `sw zero,0x54` before `sw v0,0x60` and before the
 *     D_8008A8F8 address materialization; gcc sinks the zero store past both.
 *   - target re-materializes the D_8008A8F8 base into $a2 for each 3-byte copy
 *     (two `lui/addiu` pairs); gcc keeps a single base in $v0.
 * The u8 pointer form and the 2-word struct copy are required to stop gcc
 * hoisting the %gp_rel scalar loads above the leading stores and to keep the
 * byte copies as signed `lb`.  renderer.c was moved to -G8 for this stub's
 * %gp_rel loads of D_8008A8FC/D_8008A900. */
void func_8003E968(renderer_t *This) {
    u8 *p;

    p = (u8 *)This;
    *(s32 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x70) = 0;
    *(renderer_wh_t *)(p + 0x34) = *(renderer_wh_t *)&D_8008A8FC;
    *(s32 *)(p + 0x3C) = 0xD;
    *(s32 *)(p + 0x44) = 0x7D0;
    *(s32 *)(p + 0x48) = 0x40;
    *(s32 *)(p + 0x40) = 0x100;
    *(s32 *)(p + 0x4C) = 0xA;
    *(s32 *)(p + 0x50) = 0x10000;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x60) = 0x4E20;
    __builtin_memcpy(p + 0x5B, D_8008A8F8, 3);
    __builtin_memcpy(p + 0x58, D_8008A8F8, 3);
    *(s32 *)(p + 0xB4) = 0;
    *(s32 *)(p + 0xB8) = 1;
}
#endif

INCLUDE_ASM("asm/nonmatchings/gfx/renderer", func_8003E968);

void func_8003EA0C(renderer_t *This, s32 *Unk) {
    __builtin_memcpy(This->m_Unk12, Unk, 8);
}

void func_8003EA24(renderer_t *This, s32 Unk) {
    This->m_Unk14 = Unk;
}

void func_8003EA2C(renderer_t *This, s32 Value) {
    if (!This->m_Unk27) {
        This->m_Unk16 = Value;
    }
}

void func_8003EA48(renderer_t *This, s32 Value) {
    if (!This->m_Unk27) {
        This->m_Unk17 = Value;
    }
}

void func_8003EA64(renderer_t *This, void (*Unk)(void)) {
    This->m_Unk15 = Unk;
}

void func_8003EA6C(void) {
}

void func_8003EA74(void) {
}

void func_8003EA7C(renderer_t *This, s32 Unk) {
    This->m_Unk20 = Unk;
}

void func_8003EA84(renderer_t *This, s8 *Data) {
    __builtin_memcpy(This->m_Unk21, Data, 3);
}

void func_8003EAA4(renderer_t *This, s8 *Data) {
    __builtin_memcpy(This->m_Unk21 + 3, Data, 3);
}

void func_8003EAC4(renderer_t *This, s32 Unk) {
    This->m_Unk23 = Unk;
}

void func_8003EACC(renderer_t *This, s32 unused, s32 arg2, s32 arg3, s32 *arg4) {
    renderer_vtable_t *vt;
    s32 *view_arg;

    vt = This->vtable;
    if (This->m_Unk3 == 0) {
        ((void (*)(renderer_t *))vt->Attach)(This);
        ((void (*)(renderer_t *, s32))vt->Unk29)(This, arg2);
        ((void (*)(renderer_t *, s32))vt->Unk30)(This, arg3);
        view_arg = arg4;
        if (view_arg == NULL) {
            view_arg = &D_8008A8F4;
        }
        ((void (*)(renderer_t *, s32 *))vt->Unk31)(This, view_arg);
        GsSetRefView2(&This->m_Unk4);
    }
}

void func_8003EB84(renderer_t *This) {
    if (This->m_Unk3) {
        This->vtable->Detach(This, This->m_Unk3);
    }
}

void func_8003EBC4(renderer_t *This, s32 *Unk) {
    if (This->m_Unk3) {
        __builtin_memcpy(&This->m_Unk4, Unk, 12);
    }
}

void func_8003EBF8(renderer_t *This, s32 *Unk) {
    if (This->m_Unk3) {
        __builtin_memcpy(&This->m_Unk7, Unk, 12);
    }
}

void func_8003EC2C(renderer_t *This, s16 *arg1) {
    s16 num;
    s16 den;
    s32 quot;
    s32 rem;

    if (This->m_Unk3 != 0) {
        num = arg1[0];
        den = arg1[1];
        quot = num / den;
        rem = num % den;
        This->m_Unk10 = (quot << 12) + ((rem << 12) / den);
    }
}

void func_8003ECC0(void) {
}

void func_8003ECC8(void) {
}

extern void GsClearOt(unsigned short offset, unsigned short point, void *otp);

void func_8003ECD0(renderer_t *This) {
    s32 four;
    s32 area;
    s32 bytes;
    u8 *buf;

    four = 4;
    if (This->m_Unk27 == 0) {
        area = (This->m_Unk17 * This->m_Unk16) + 0x14;
        bytes = (four << This->m_Unk14) + area;
        buf = memory_allocate_mem(bytes << 1);
        if (buf != 0) {
            This->m_Unk29 = (s32)buf;
            This->m_Unk31 = (s32)buf + 0x14;
            This->m_Unk33 = This->m_Unk31 + (four << This->m_Unk14);
            This->m_Unk30 = This->m_Unk29 + bytes;
            This->m_Unk32 = This->m_Unk31 + bytes;
            This->m_Unk34 = This->m_Unk33 + bytes;
            *(s32 *)This->m_Unk29 = This->m_Unk14;
            *(s32 *)(This->m_Unk29 + 4) = This->m_Unk31;
            *(s32 *)This->m_Unk30 = This->m_Unk14;
            *(s32 *)(This->m_Unk30 + 4) = This->m_Unk32;
            GsClearOt(0, 0, (void *)This->m_Unk29);
            GsClearOt(0, 0, (void *)This->m_Unk30);
            This->m_Unk27 = 1;
            This->m_Unk28 = 0;
        }
    }
}

void func_8003EDF4(renderer_t *This) {
    if ( This->m_Unk27 )
  {
    DrawSync(0);
    memory_free_mem(This->m_Unk29);
    This->m_Unk27 = 0;
  }
}

void func_8003EE40(renderer_t *This, s32 Unk1, s32 Unk2) {
    ++This->m_Unk35;
  if ( (unsigned int)(Unk2 - 2) < 2 ) {
    This->vtable->Unk38(This);
  }
}

void func_8003EE88(renderer_t *This, s32 Unk, s32 Unk2) {
    if (Unk2 == 2) {
        This->vtable->Unk40(This, Unk);
    }
}

void GsSetLightMode(s32 mode);
void SetFarColor(s32 r, s32 g, s32 b);
void SetFogNear(s32 near, s32 dist);
void func_8003FB0C(s32 arg);
void func_8003FBE4(s32 arg);
void func_8003F28C(s32 distance);
void *func_8003F25C(s32 *unk);

void func_8003EEC0(renderer_t *This) {
    u8 *rgb;
    u32 span;
    u32 step;

    if (This->m_Unk27 == 0) {
        return;
    }
    if (*(s32 *)((u8 *)This->m_Unk3 + 0xC) != 0) {
        This->vtable->Unk39(This, This->m_Unk3);
    }
    func_8003F28C((s32)This->m_Unk15);
    func_8003FB0C(This->m_Unk18);
    GsSetLightMode(This->m_Unk20);
    if (This->m_Unk20 == 1 || This->m_Unk20 == 3) {
        rgb = (u8 *)This->m_Unk21;
        SetFarColor(rgb[3], rgb[4], rgb[5]);
        SetFogNear(This->m_Unk23, (s32)This->m_Unk15);
    }
    GsSetRefView2(&This->m_Unk4);
    *(s32 *)This->m_Unk11 = 0;
    span = This->m_Unk19 - This->m_Unk18;
    step = 1 << This->m_Unk14;
    This->m_Unk37 = (span / step) + 1;
    func_8003FBE4(((s32 *)&This->m_Unk33)[This->m_Unk28]);
    GsClearOt(0, 0, (void *)(&This->m_Unk29)[This->m_Unk28]);
    This->vtable->Unk39(This, This->m_Unk42);
    if (This->m_Unk3 != 0) {
        This->vtable->Unk39(This, (s32)func_8003F25C((s32 *)This->m_Unk3));
    }
}

int ResetGraph(int mode);
void GsSortClear(u8, u8, u8, void *);
void GsDrawOt(void *);

void func_8003F04C(renderer_t *This) {
    void **obj;
    u8 *rgb;

    if (This->m_Unk27 == 0) {
        return;
    }
    obj = (void **)This->m_Unk2;
    This->m_Unk28 = ((s32 (*)(void **))(*(u32 *)((u8 *)*obj + 0x54)))(obj);
    if (This->m_Unk45 == 0) {
        goto flip;
    }
    ResetGraph(1);
    obj = (void **)This->m_Unk2;
    ((void (*)(void **))(*(u32 *)((u8 *)*obj + 0x50)))(obj);
    if (This->m_Unk44 == 0) {
        goto draw;
    }
    if (This->m_Unk28 != 0) {
        goto draw;
    }
    obj = (void **)This->m_Unk2;
    ((void (*)(void **))(*(u32 *)((u8 *)*obj + 0x50)))(obj);
draw:
    rgb = (u8 *)This->m_Unk21;
    GsSortClear(rgb[0], rgb[1], rgb[2], (void *)(&This->m_Unk29)[This->m_Unk28]);
    GsDrawOt((void *)(&This->m_Unk29)[This->m_Unk28]);
    if (This->m_Unk44 == 0) {
        goto flip;
    }
    if (This->m_Unk28 != 0) {
        goto store;
    }
    obj = (void **)This->m_Unk2;
    ((void (*)(void **))(*(u32 *)((u8 *)*obj + 0x50)))(obj);
flip:
    This->m_Unk28 = This->m_Unk28 == 0;
    return;
store:
    This->m_Unk28 = This->m_Unk28 == 0;
}

s32 func_8003F1A8(renderer_t *This, void *obj) {
    void *old;

    if (This->m_Unk3 == 0) {
        old = (void *)This->m_Unk43;
        if (old != 0) {
            (*(void (**)(void *))(*(u32 *)old + 4))(old);
        }
        This->m_Unk43 = (s32)obj;
        if (obj != 0) {
            return ((s32 (*)(void *, s32, void *))(*(u32 *)(*(u32 *)obj + 0x4C)))(
                obj, This->m_Unk42, &D_8008A904);
        }
    }
#ifdef NON_MATCHING
    return This->m_Unk3;
#endif
}

s32 func_8003F230(renderer_t *This) {
    return This->m_Unk43;
}

void func_8003F23C(renderer_t *This, s32 Unk) {
    This->m_Unk44 = Unk;
}

void func_8003F244(renderer_t *This, s32 Unk) {
    This->m_Unk45 = Unk;
}

renderer_vtable_t *renderer_get_vtable(void) {
    return &g_RENDERER_VTABLE;
}

void *func_8003F25C(s32 *Unk) {
    for (; Unk[3]; Unk = (s32 *) Unk[3]) {
    }

    return Unk;
}

void func_8003F28C(s32 Distance) {
    SetGeomScreen(Distance);
}
