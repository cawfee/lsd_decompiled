#include "graph_screen.h"
#include "ui_screen.h"
#include "dream_sys.h"

extern graph_screen_vtable_t **D_80087AAC;

graph_screen_t *graph_screen_create(s32 Unk1) {
    graph_screen_t *allocated = (graph_screen_t *) memory_allocate_mem(0x244);

    if (allocated) {
        func_80058764()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80057FC8(graph_screen_t *This, void *Unk) {
    func_8003DFBC()->Construct(This, NULL, "ETC\\ETCSE", 0);
    This->vtable = func_80058764();
    (*(void (**)(s32, int))(*(u32 *) This->m_Unk17 + 156))(This->m_Unk17, -1);
    This->m_Unk40 = Unk;
    This->vtable->Unk53(This, 0);
    This->vtable->show_graph(This, Unk);
}

void show_graph(graph_screen_t *This) {
    This->m_Unk32 = 5;
    This->m_Unk10 = 400;
    This->vtable->Unk52(This, "ETC\\HGRAPH.TIM", 0);
    This->vtable->Unk26(This, 10);
}

void func_800580E0(graph_screen_t *This, s32 Unk2, s32 Unk3) {
    void *unk;

    func_8003DFBC()->Unk22(This, Unk2, Unk3);

    if (This->m_Unk14 == 1) {
        unk = (void *) (*(int (**)(void *, u32))(*(u32 *) This->m_Unk40 + 432))(This->m_Unk40, 0);

        if (*((u32 *) unk + 1) || *((u32 *) unk + 2)) {
            (*(void (**)(s32, int))(*(u32 *) This->m_Unk41 + 96))(This->m_Unk41, This->m_Unk6 & 1);
        }
    }

    This->vtable->Unk72(This);
}

void func_800581C4(graph_screen_t *This) {
    if (!This->m_Unk141) {
        This->vtable->Unk27(This, 16);
        This->vtable->Unk36(This);
    }
}

INCLUDE_ASM("asm/nonmatchings/graph_screen", func_80058228);

void func_80058308(graph_screen_t *This) {
    s32 i;
    u8 *cursor;
    void *obj;

    i = 0;
    cursor = (u8 *)This;
    memory_free_mem(This->m_Unk143);
    do {
        obj = *(void **)(cursor + 0xA8);
        cursor += 4;
        i++;
        (*(void (**)(void *))(*(u32 *)obj + 4))(obj);
    } while (i < 100);
    func_8003DFBC()->Unk54(This);
}

s32 func_80058390(graph_screen_t *This, void *Unk1, s32 Unk2) {
    s32 var_v1;

    func_8003DFBC()->Run(This, Unk1, Unk2);
    var_v1 = 2;
    if (This->m_Unk141 == 0) {
        var_v1 = This->m_Unk13;
    }
    return var_v1;
}

typedef struct func_80058404_slot func_80058404_slot_t;

typedef struct func_80058404_slot_vtable {
    /* 0x00 */ u8 pad[0xC4];
    /* 0xC4 */ void (*Unk48)(func_80058404_slot_t *, s32, s32 *, s32);
} func_80058404_slot_vtable_t;

typedef struct func_80058404_slot {
    /* 0x00 */ func_80058404_slot_vtable_t *vtable;
} func_80058404_slot_t;

typedef struct func_80058404_rec {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 field4;
    /* 0x08 */ s32 count;
    /* 0x0C */ u8 pad[0xC];
    /* 0x18 */ s8 bytes[2];
} func_80058404_rec_t;

typedef struct func_80058404_pt {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
} func_80058404_pt_t;

void func_80058404(graph_screen_t *This, s32 arg) {
    func_80058404_rec_t *rec;
    s32 limit;
    s32 flag;
    s32 i;
    s32 idx;
    u8 *cursor;
    func_80058404_pt_t cur;
    func_80058404_pt_t saved;
    func_80058404_slot_t *slot;
    char pad[8];

    if (&pad[0] == &pad[7]) {
    }
    func_8003DFBC()->Unk55(This, arg);
    rec = ((dream_sys_t *)This->m_Unk40)->vtable->GetRegionCode(This->m_Unk40, NULL);
    This->m_Unk141 = func_800585B4(This, (u8 *)rec);
    flag = 0;
    if (rec->field4 != 0) {
        limit = 100;
    } else {
        limit = rec->count;
        if (limit >= 101) {
            limit = 100;
        }
    }
    i = 0;
    idx = rec->count - 1;
    if (limit > 0) {
        cursor = (u8 *)This;
        do {
            if (idx < 0) {
                idx = 0x16C;
            }
            cur.x = *(s8 *)((u8 *)rec + (idx << 1) + 0x18) * 10 - 5;
            cur.y = -*(s8 *)((u8 *)rec + (idx << 1) + 0x19) * 10 - 5;
            if (i == 0) {
                saved = cur;
                flag = 1;
            } else {
                slot = *(func_80058404_slot_t **)(cursor + 0xA8);
                slot->vtable->Unk48(slot, arg, &cur.x, 0);
            }
            cursor += 4;
            i += 1;
            idx -= 1;
        } while (i < limit);
    }
    if (flag != 0) {
        slot = (func_80058404_slot_t *)This->m_Unk41;
        slot->vtable->Unk48(slot, arg, &saved.x, 0);
    }
}

extern s16 D_80087BD4[];

s32 func_800585B4(graph_screen_t *This, u8 *obj) {
    s32 limit;
    u32 slot;
    char dummy[8];

    if (&dummy[0] == &dummy[7]) {
    }
    if (((s8 *)obj)[0x467] == 0) {
        limit = 100;
        if (*(s32 *)(obj + 4) == 0) {
            limit = *(s32 *)(obj + 8);
            if (limit >= 101) {
                limit = 100;
            }
        }
        for (slot = 0; slot < 4; slot++) {
            s32 hits;
            s32 i;
            s32 base;
            s32 idx;

            i = 0;
            base = *(s32 *)(obj + 8);
            idx = base - 1;
            hits = 0;
            if (limit > 0) {
                do {
                    if (idx < 0) {
                        idx = 0x16C;
                    }
                    if (*(s16 *)((u8 *)D_80087BD4 + (slot << 1)) == *(s16 *)(obj + (idx << 1) + 0x18)) {
                        ((u8 *)This->m_Unk143)[slot] = i;
                        hits += 1;
                    }
                    idx -= 1;
                    i += 1;
                } while (i < limit);
            }
            if (hits == 0) {
                return 0;
            }
        }
        ((s8 *)obj)[0x467] = 1;
        This->m_Unk142 = 0;
        return 1;
    }
    return 0;
}

extern s32 D_8008ABBC;

void func_80058694(graph_screen_t *This) {
    u32 unk6;
    u32 unk142;
    void *obj;
    s32 idx;

    if (This->m_Unk141 != 0) {
        unk6 = (u32)This->m_Unk6;
        if (unk6 >= 0x1FU) {
            unk142 = (u32)This->m_Unk142;
            if ((unk142 < 4U) && (unk6 == ((unk6 / 24) * 0x18))) {
                idx = *((s8 *)This->m_Unk143 + unk142);
                obj = *(void **)((u8 *)This + 0xA8 + (idx * 4));
                (*(void (**)(void *, s32, s32 *))(*(s32 *)obj + 0xB8))(obj, 1, &D_8008ABBC);
                This->m_Unk142++;
            }
        }
    }
}

graph_screen_vtable_t *func_80058764(void) {
    return &D_80087AAC;
}
