#include "asset_player.h"

#include "2C694.h"

extern asset_player_vtable_t **g_ASSET_PLAYER_VTABLE;

asset_player_t *asset_player_create(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    asset_player_t *allocated = (asset_player_t *) memory_allocate_mem(0xDC);

    if (allocated) {
        asset_player_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3, Unk4);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/asset_player", asset_player_construct);

void asset_player_cleanup(asset_player_t *This) {
    (*(void ( **)(s32))(*(s32 *)This->m_Unk44 + 4))(This->m_Unk44);
  func_8003DFBC()->Cleanup(This);
}

void func_8003BA38(asset_player_t *This) {
    This->m_Unk49 = -1;
    This->m_Unk48 = 0;
    This->m_Unk50 = 1;
    This->m_Unk51 = 0;
    This->m_Unk52 = 1;
}

void func_8003BA58(asset_player_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    This->m_Unk45 = Unk3;
    This->m_Unk46 = Unk4;
    This->m_Unk47 = Unk5;

    func_8003DFBC()->Unk16(This, Unk2, 0);
}

INCLUDE_ASM("asm/nonmatchings/asset_player", func_8003BAB4);

INCLUDE_ASM("asm/nonmatchings/asset_player", func_8003BB5C);

INCLUDE_ASM("asm/nonmatchings/asset_player", func_8003BC14);

void func_8003BCF4(asset_player_t *This, s32 Unk) {
    This->m_Unk15 = Unk;

    if (Unk >= 0) {
        This->m_Unk15 = 15 * Unk;
    }
}

void func_8003BD10(asset_player_t *This) {
    func_8003DFBC()->Unk29(This);

    if (This->m_Unk50) {
        This->m_Unk13 = 2;
        This->vtable->Unk23(This, 18);
    }
}

void func_8003BD74(asset_player_t *This) {
    func_8003DFBC()->Unk31(This);
}

void func_8003BDAC(asset_player_t *This) {
    func_8003DFBC()->Unk32(This);
}

void func_8003BDE4(void) {
}

void func_8003BDEC(void) {
}

INCLUDE_ASM("asm/nonmatchings/asset_player", func_8003BDF4);

void func_8003BE5C(asset_player_t *This, s32 Value) {
    This->m_Unk48 = Value;
}

void func_8003BE64(asset_player_t *This, s32 Value) {
    This->m_Unk49 = Value;
}

void func_8003BE6C(asset_player_t *This, s32 Value) {
    This->m_Unk50 = Value;
}

void func_8003BE74(asset_player_t *This, s32 Value) {
    This->m_Unk51 = Value;
}

void func_8003BE7C(asset_player_t *This, s32 Value) {
    This->m_Unk52 = Value;
}

asset_player_vtable_t *asset_player_get_vtable(void) {
    return &g_ASSET_PLAYER_VTABLE;
}
