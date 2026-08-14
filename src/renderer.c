#include "renderer.h"
#include "base_class.h"
#include "305B0.h"
#include "D294.h"

#include <psx/libgte.h>

extern renderer_vtable_t *g_RENDERER_VTABLE;
extern s32 D_8008A904;
extern s32 D_8008A90C;

class_D294_t *func_8001CA94(void);

renderer_t *renderer_create(void) {
    renderer_t *memory = (renderer_t *) memory_allocate_mem(0xBC);

    if (memory != 0) {
        renderer_get_vtable()->Construct(memory);
        return memory;
    }

    return NULL;
}

extern s32 D_8008A904;
extern s32 D_8008A90C;

void func_8003E628(renderer_t *This) {
    class_305B0_t *temp_v0;

    base_class_get_vtable()->Construct(This);
    This->vtable = renderer_get_vtable();
    This->m_Unk2 = 0;
    This->m_Unk3 = 0;
    This->m_Unk42 = (s32)func_8001CA94();
    temp_v0 = class_305B0_create((s32)&D_8008A90C, 0, 0);
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

    base_class_get_vtable()->Unk3(This, arg1);
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
    base_class_get_vtable()->Unk4(This, Unk);
}

void func_8003E874(renderer_t *This) {
    This->m_Unk11 = 0;
  This->m_Unk3 = 0;
  This->m_Unk2 = 0;
  base_class_get_vtable()->Unk5(This);
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E8B8);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E968);

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

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EACC);

void func_8003EB84(renderer_t *This) {
    if (This->m_Unk3) {
        This->vtable->Unk4(This, This->m_Unk3);
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

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EC2C);

void func_8003ECC0(void) {
}

void func_8003ECC8(void) {
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003ECD0);

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

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EEC0);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F04C);

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
