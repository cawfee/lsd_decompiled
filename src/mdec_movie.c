#include "mdec_movie.h"
#include "str_stream.h"
#include "base_class.h"

extern mdec_movie_vtable_t D_8006F614;

extern s32 D_8008A940;
extern s32 D_8008A948;
extern s32 D_8008A93C;

void DecDCTReset(s32 mode);
s32 DecDCToutCallback(void (*func)());
void DecDCTout(s32, s32);
void DecDCTin(s32, s32);
s32 DrawSync(s32);
void *get_display(void);
void func_8004575C(mdec_movie_t *This);
s32 func_8004564C(mdec_movie_t *This, s32 Unk1, s32 Unk2);
void func_80045DE0(void);
void func_8004593C(mdec_movie_t *This);
void func_80046568(s32, s32);

mdec_movie_t *func_80045438(s32 Unk1, s32 Unk2, s32 Unk3) {
    mdec_movie_t *allocated = (mdec_movie_t *) memory_allocate_mem(0x6C);

    if (allocated) {
        ;
        if (!func_80045E44()->Construct(allocated, Unk1, Unk2, Unk3)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

s32 func_800454C4(mdec_movie_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    void **obj;
    void (*cb)(void);

    base_class_get_vtable()->base_class_construct(This);
    This->vtable = func_80045E44();
    This->m_Unk23 = (s32)func_80046F0C(Unk2, 0xF, 0);
    if (This->m_Unk23 != 0) {
        if (func_8004564C(This, Unk1, Unk3) == 0) {
            if (D_8008A93C == 0) {
                DecDCTReset(0);
            }
            cb = func_80045DE0;
            D_8008A93C = 1;
            DecDCToutCallback(cb);
            obj = (void **)This->m_Unk23;
            (*(void (**)(void *, s32, s32))(*(u32 *)obj + 0x40))(obj, This->m_Unk3, 0x12000);
            This->m_Unk19 = 0;
            ((void (*)(void *, s32))This->vtable->Unk26)(This, 1);
            return 0;
        }
        return 1;
    }
    return 1;
}

void func_800455D4(mdec_movie_t *This) {
    void **temp_a0;

    temp_a0 = (void **)This->m_Unk23;
    This->m_Unk23 = (s32)((void *(*)(void **))(*(void **)((s8 *)*temp_a0 + 4)))(temp_a0);
    DecDCToutCallback(0);
    DecDCTReset(0);
    func_8004575C(This);
    base_class_get_vtable()->base_class_cleanup(This);
}

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} mdec_movie_triple_t;

s32 func_8004564C(mdec_movie_t *This, s32 arg1, s32 arg2) {
    mdec_movie_triple_t *src;
    s32 size;
    void *mem;
    char pad[8];

    if (&pad[0] == &pad[7]) {
    }
    src = (mdec_movie_triple_t *)arg1;
    This->m_Unk2 = arg2;
    if (arg2 == 0) {
        This->m_Unk6 = 0;
        This->m_Unk5 = 0;
        This->m_Unk4 = 0;
        This->m_Unk3 = 0;
        size = ((src->b * src->c) << 1) + 0x1000;
        mem = memory_allocate_mem(size);
        This->m_Unk4 = (s32)mem;
        if (mem == NULL) {
            goto fail;
        }
        mem = memory_allocate_mem(size);
        This->m_Unk5 = (s32)mem;
        if (mem == NULL) {
            goto fail;
        }
        mem = memory_allocate_mem(0x12000);
        This->m_Unk3 = (s32)mem;
        if (mem == NULL) {
            goto fail;
        }
        mem = memory_allocate_mem(src->c << 5);
        This->m_Unk6 = (s32)mem;
        if (mem == NULL) {
            goto fail;
        }
    }
    *(mdec_movie_triple_t *)&This->m_Unk10 = *src;
    *(mdec_movie_triple_t *)&This->m_Unk7 = *(mdec_movie_triple_t *)&This->m_Unk10;
    This->m_Unk11 = 0x10;
    This->m_Unk13 = (This->m_Unk12 << 4) >> 1;
    return 0;
fail:
    func_8004575C(This);
    return 1;
}

void func_8004575C(mdec_movie_t *This) {
    if (This->m_Unk2 == 0) {
        memory_free_mem(This->m_Unk4);
        memory_free_mem(This->m_Unk5);
        memory_free_mem(This->m_Unk3);
        memory_free_mem(This->m_Unk6);
    }
}

INCLUDE_ASM("asm/nonmatchings/mdec_movie", func_800457C0);

void func_800458AC(mdec_movie_t *This) {
    This->m_Unk19 = 1;
}

void func_800458B8(mdec_movie_t *This) {
    void **obj;
    mdec_movie_t *g;

    g = (mdec_movie_t *)D_8008A940;
    if (g == This) {
        obj = (void **)g->m_Unk23;
        g->m_Unk15 = 0;
        g->m_Unk14 = 0;
        g->m_Unk18 = 1;
        g->m_Unk17 = 0;
        g->m_Unk16 = 0;
        (*(void (**)(void **, void (*)(mdec_movie_t *), mdec_movie_t *))(*(u32 *)obj + 0x7C))(
            obj, func_8004593C, g);
        obj = (void **)g->m_Unk23;
        g->m_Unk24 = 0;
        (*(void (**)(void **))(*(u32 *)obj + 0x58))(obj);
    }
}

void func_8004593C(mdec_movie_t *This) {
    This->m_Unk19 = -1;
}

INCLUDE_ASM("asm/nonmatchings/mdec_movie", func_80045948);

void func_80045A38(mdec_movie_t *This) {
    void **obj;
    mdec_movie_t *g;
    s32 one;

    g = (mdec_movie_t *)D_8008A940;
    if (g == This) {
        obj = (void **)g->m_Unk23;
        one = 1;
        g->m_Unk17 = one;
        g->m_Unk20 = 0;
        (*(void (**)(void **))(*(u32 *)obj + 0x48))(obj);
        g->m_Unk16 = one;
        if (g->m_Unk24 == 0) {
            obj = (void **)g->m_Unk23;
            (*(void (**)(void **, s32, s32))(*(u32 *)obj + 0x7C))(obj, 0, 0);
            g->m_Unk24 = one;
            g->m_Unk16 = one;
        }
    }
}

void func_80045AC8(void) {
}

void func_80045AD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/mdec_movie", func_80045AD8);

void func_80045BC0(void) {
}

void func_80045BC8(mdec_movie_t *This) {
    void **obj;
    u16 temp;
    s16 cmp;

    obj = (void **)get_display();
    (*(void (**)(void **, u8 *, s32))(*(u32 *)obj + 0x58))(obj, (u8 *)This + 0x2C, This->m_Unk6);
    temp = *(u16 *)((u8 *)This + 0x2C) + *(u16 *)((u8 *)This + 0x30);
    *(u16 *)((u8 *)This + 0x2C) = temp;
    cmp = (s16)temp;
    if (cmp < *(s16 *)((u8 *)This + 0x20) + This->m_Unk8) {
        if (This->m_Unk12 < 0x80) {
            DrawSync(0);
        }
        DecDCTout(This->m_Unk6, This->m_Unk13);
        return;
    }
    This->m_Unk18 = 1;
    *(u16 *)((u8 *)This + 0x2C) = *(u16 *)((u8 *)This + 0x20);
    *(u16 *)((u8 *)This + 0x2E) = *(u16 *)((u8 *)This + 0x22);
    if (This->m_Unk17 != 0) {
        This->m_Unk16 = 1;
    }
}

s32 func_80045C94(mdec_movie_t *This) {
    if (This->m_Unk20 != 0) {
        s32 temp_v0;

        temp_v0 = D_8008A948 < 0x65;
        D_8008A948 += 1;
        if (temp_v0 == 0) {
            D_8008A948 = 1;
            This->vtable->Unk16(This);
        }
        return 0;
    }
    D_8008A940 = 0;
    return 1;
}

s32 func_80045CFC(mdec_movie_t *This) {
    mdec_movie_t *g;

    g = (mdec_movie_t *)D_8008A940;
    if (g == This) {
        if (g->m_Unk16 == 0) {
            if (g->m_Unk15 != 0) {
                func_80045E18(g);
                g->m_Unk18 = 0;
                if (g->m_Unk12 < 0x80) {
                    DrawSync(0);
                }
                DecDCTin(*(s32 *)((u8 *)g + 0x14 + (g->m_Unk14 * 4)), 2);
                DecDCTout(g->m_Unk6, g->m_Unk13);
            }
            This->m_Unk15 = ((s32 (*)(void *))This->vtable->Unk21)(This) == 0;
            return 0;
        }
        ((void (*)(void *))g->vtable->Unk24)(g);
    }
#ifdef NON_MATCHING
    return 0;
#endif
}

void func_80045DE0(void) {
    if (D_8008A940 != NULL) {
        (*(void ( **)(int))(*(s32 *)D_8008A940 + 96))(D_8008A940);
    }
}

void func_80045E18(mdec_movie_t *This) {
    while (!This->m_Unk18) {
    }
}

void func_80045E3C(mdec_movie_t *This, s32 Unk) {
    This->m_Unk25 = Unk;
}

mdec_movie_vtable_t *func_80045E44(void) {
    return &D_8006F614;
}
