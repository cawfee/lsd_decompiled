#include "map_scene.h"
#include "dream_sys.h"
#include "stage_grid.h"

extern s32 D_8008AB34;
extern s32 D_8008715C[];
extern s32 D_80087168[];
extern s32 D_8008710C[];

void func_8005C650(s32, void *, dream_sys_t *, void *, void *);

void func_800534C8(map_scene_t *This) {
    void *obj5;
    s32 *link;
    void *inner;
    s32 *valp;
    s32 scaled;
    void *obj4;

    obj5 = This->m_Unk5;
    link = (s32 *)This->m_Unk19;
    (*(void (**)(void *))(*(s32 *)obj5 + 0x74))(obj5);
    inner = *(void **)(void *)This->m_Unk2;
    valp = (*(s32 * (**)(void *, s32))(*(s32 *)inner + 0x7C))(inner, 0);
    scaled = (((*valp / 2) * 5) / 3) + D_8008AB34;
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0x54))(obj5, scaled);
    (*(void (**)(void *, dream_sys_t *, s32 *, s32 *, s32))(*(s32 *)obj5 + 0x70))(
        obj5, This->m_Unk14, D_8008715C, D_80087168, 0);
    func_8005C650(This->m_Unk13, This->m_Unk4, This->m_Unk14, This->m_Unk12, This->m_Unk3);
    obj4 = This->m_Unk4;
    This->vtable->Attach(This, obj4);
    (*(void (**)(void *, s32, s32))(*(s32 *)obj4 + 0xBC))(obj4, link[2], 0);
    (*(void (**)(void *, s32, s32, s32))(*(s32 *)obj4 + 0xC4))(obj4, 3, link[0], link[1]);
    (*(void (**)(void *, void *))(*(s32 *)obj4 + 0xE0))(
        obj4, stage_grid_get_dimension(This->m_Unk13));
    This->m_Unk14->vtable->dream_sys_unk18(This->m_Unk14, obj4);
    (*(void (**)(void *, s32))(*(s32 *)obj4 + 0xDC))(obj4, This->m_Unk17);
    (*(void (**)(void *, s32 *))(*(s32 *)obj4 + 0xCC))(obj4, D_8008710C);
}
