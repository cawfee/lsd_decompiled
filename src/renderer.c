#include "renderer.h"
#include "base_class.h"

#include <psx/libgte.h>

extern renderer_vtable_t *g_RENDERER_VTABLE;

renderer_t *renderer_create(void) {
    renderer_t *memory = (renderer_t *) memory_allocate_mem(0xBC);

    if (memory != 0) {
        renderer_get_vtable()->Construct(memory);
        return memory;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E628);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E6CC);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E770);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E7F4);

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

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F1A8);

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
