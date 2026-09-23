#include "movie_screen.h"

#include "ui_screen.h"

extern movie_screen_vtable_t **g_MOVIE_SCREEN_VTABLE;

s32 *func_8003DFCC(void);
s32 func_80045438(s32, s32, s32);

movie_screen_t *movie_screen_create(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    movie_screen_t *allocated = (movie_screen_t *) memory_allocate_mem(0xDC);

    if (allocated) {
        movie_screen_get_vtable()->movie_screen_construct(allocated, Unk1, Unk2, Unk3, Unk4);
        return allocated;
    }

    return NULL;
}

void movie_screen_construct(movie_screen_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 *arg4) {
    func_8003DFBC()->Construct(This, (char **)Unk1, (char *)Unk2, Unk3);
    This->vtable = movie_screen_get_vtable();
    if (arg4 != NULL) {
        __builtin_memcpy(&This->m_Unk41, arg4, 12);
    } else {
        __builtin_memcpy(&This->m_Unk41, func_8003DFCC(), 12);
    }
    This->m_Unk44 = func_80045438((s32)func_8003DFCC(), 0, 0);
    This->m_Unk45 = 0;
    This->vtable->Unk15(This);
}

void movie_screen_cleanup(movie_screen_t *This) {
    (*(void ( **)(s32))(*(s32 *)This->m_Unk44 + 4))(This->m_Unk44);
  func_8003DFBC()->Cleanup(This);
}

void func_8003BA38(movie_screen_t *This) {
    This->m_Unk49 = -1;
    This->m_Unk48 = 0;
    This->m_Unk50 = 1;
    This->m_Unk51 = 0;
    This->m_Unk52 = 1;
}

void func_8003BA58(movie_screen_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    This->m_Unk45 = Unk3;
    This->m_Unk46 = Unk4;
    This->m_Unk47 = Unk5;

    func_8003DFBC()->Run(This, Unk2, 0);
}

s32 func_8003BAB4(movie_screen_t *This) {
    s32 result;
    void *obj;

    func_8003DFBC()->Unk18(This);
    obj = (void *)This->m_Unk44;
    This->m_Unk40 = 0;
    (*(void (**)(void *, s32))(*(u32 *)obj + 0x6C))(obj, This->m_Unk47);
    result = (*(s32 (**)(void *, s32, s32, s32, s32))(*(u32 *)This->m_Unk44 + 0x40))(
        (void *)This->m_Unk44, This->m_Unk45, This->m_Unk46, This->m_Unk48, This->m_Unk49);
    if (result != 0) {
        result = ((s32 (*)(void *, s32))This->vtable->Unk26)(This, 0);
    }
    return result;
}

void func_8003BB5C(movie_screen_t *This, s32 arg1, s32 arg2) {
    void *obj;
    s32 temp;

    ((void (*)(void *, s32, s32))func_8003DFBC()->Unk22)(This, arg1, arg2);
    if (This->m_Unk40 == 0) {
        obj = (void *)This->m_Unk44;
        temp = (*(s32 (**)(void *))(*(s32 *)obj + 0x48))(obj);
        This->m_Unk40 = temp;
        if ((temp != 0) && (This->m_Unk53 == 0)) {
            This->vtable->Unk23(This, 7);
        }
    }
}

void func_8003BC14(movie_screen_t *This, s32 arg1) {
    void *obj;
    void (*callback)(void *);

    func_8003DFBC()->Unk23(This, arg1);
    switch (arg1) {
    case 5:
        This->m_Unk53 = 0;
        break;
    case 7:
        This->m_Unk53 = 1;
        break;
    case 8:
        if (This->m_Unk52 == 0) {
            obj = (void *)This->m_Unk44;
            callback = *(void (**)(void *))(*(s32 *)obj + 0x4C);
            goto call;
        }
        break;
    case 0x12:
        callback = This->vtable->Unk36;
        obj = This;
    call:
        callback(obj);
        break;
    }
}

void func_8003BCF4(movie_screen_t *This, s32 Unk) {
    This->m_Unk15 = Unk;

    if (Unk >= 0) {
        This->m_Unk15 = 15 * Unk;
    }
}

void func_8003BD10(movie_screen_t *This) {
    func_8003DFBC()->Unk29(This);

    if (This->m_Unk50) {
        This->m_Unk13 = 2;
        This->vtable->Unk23(This, 18);
    }
}

void func_8003BD74(movie_screen_t *This) {
    func_8003DFBC()->Unk31(This);
}

void func_8003BDAC(movie_screen_t *This) {
    func_8003DFBC()->Unk32(This);
}

void func_8003BDE4(void) {
}

void func_8003BDEC(void) {
}

void func_8003BDF4(movie_screen_t *This) {
    if (This->m_Unk52) {
        (*(void (**)(s32))(*(s32 *)This->m_Unk44 + 0x4C))(This->m_Unk44);
    } else {
        This->vtable->Unk23(This, 7);
    }
}

void func_8003BE5C(movie_screen_t *This, s32 Value) {
    This->m_Unk48 = Value;
}

void func_8003BE64(movie_screen_t *This, s32 Value) {
    This->m_Unk49 = Value;
}

void func_8003BE6C(movie_screen_t *This, s32 Value) {
    This->m_Unk50 = Value;
}

void func_8003BE74(movie_screen_t *This, s32 Value) {
    This->m_Unk51 = Value;
}

void func_8003BE7C(movie_screen_t *This, s32 Value) {
    This->m_Unk52 = Value;
}

movie_screen_vtable_t *movie_screen_get_vtable(void) {
    return &g_MOVIE_SCREEN_VTABLE;
}
