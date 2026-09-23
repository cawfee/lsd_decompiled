#include "common.h"

#include <psx/kernel.h>
#include <psx/libapi.h>

#include "base_class.h"
#include "memory_card.h"

extern memory_card_vtable_t *g_MEMORY_CARD_VTABLE;
extern s32 D_80086E78;
extern s32 D_8008AA30;
extern char D_8008AA9C[]; /* "bu10:" */
extern char D_8008AAA4[]; /* "bu00:" */
extern char D_8008AAAC[]; /* "TEMP" */

extern long InitCARD(long);
extern long StartCARD(void);
extern long _bu_init(void);
extern long format(char *);
extern long open(char *, unsigned long);
extern long close(long);
extern long delete(char *);
extern long read(long, void *, long);
extern long lseek(long, long, long);
extern long _card_info(long);
extern long _card_clear(long);
extern long _card_load(long);
extern char *strcat(char *, char *);
extern char *strcpy(char *, char *);
extern void *func_80050BA8(s32, s32);
extern void *func_80051A5C(s32, s32);
extern char *D_80086E80[];
extern s32 D_80086EC4;
extern s32 D_8008AA94;
extern char D_8008AAB4[]; /* "CARD\\" */
extern char D_8008AABC[]; /* ".TIM" */

#include "tim_image.h"

typedef struct class_3249C class_3249C_t;
class_3249C_t *func_80041C9C(void *, void *, s32);

s32 func_8004E77C(memory_card_t *, s32 *, s32 *, s32 *);
s32 func_8004E7D0(memory_card_t *, s32 *, s32 *);
s32 func_8004E890(memory_card_t *, s32 *, s32 *);
s32 func_8004EA38(memory_card_t *, char *, char *);
s32 func_8004EDC0(memory_card_t *, char *, void *, s32);
s32 func_8004ECCC(memory_card_t *, s32, s32);
s32 func_8004F40C(memory_card_t *, long (*)(long), s32);

memory_card_t *memory_card_create(u32 Unk1, u32 Unk2) {
    memory_card_t *allocated = (memory_card_t *) memory_allocate_mem(0x84);

    if (allocated) {
        memory_card_get_vtable()->memory_card_on_construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/memory_card", memory_card_on_construct);

void memory_card_state_reset(memory_card_t *This) {
    This->m_Unk23 = 0;
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
}

void func_8004E40C(memory_card_t *This) {
    base_class_get_vtable()->base_class_cleanup(This);
}

void func_8004E444(memory_card_t *This, void *Unk) {
    s32 unk;

    if (Unk) {
        base_class_get_vtable()->Unk3(This, Unk);

        unk = **(s32 **) Unk;

        if ((unk & 0xF) == 2) {
            This->m_Unk23 = Unk;
        } else {
            if ((unk & 0xF) == 5) {
                This->m_Unk24 = Unk;
            } else {
                if ((unk & 0xFF) == 16) {
                    This->m_Unk29 = Unk;
                } else if ((unk & 0xFF) == 32) {
                    This->m_Unk30 = Unk;
                }
            }
        }
    }
}

void func_8004E4E8(memory_card_t *This, void *Unk) {
    s32 unk;

    if (Unk) {
        unk = **(s32 **) Unk;

        if ((unk & 0xF) == 2) {
            This->m_Unk23 = NULL;
        } else {
            if ((unk & 0xF) == 5) {
                This->m_Unk24 = NULL;
            } else {
                if ((unk & 0xFF) == 16) {
                    This->m_Unk29 = NULL;
                } else if ((unk & 0xFF) == 32) {
                    This->m_Unk30 = NULL;
                }
            }
        }

        base_class_get_vtable()->Unk4(This, Unk);
    }
}

void func_8004E588(memory_card_t *This) {
    This->m_Unk23 = 0;
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
    base_class_get_vtable()->Unk5(This);
}

void func_8004E5D4(memory_card_t *This, s32 Count) {
    This->m_Unk2 = Count;
    This->m_Unk3 = 16 * Count;
}

s32 func_8004E5E4(memory_card_t *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 *var_s0 = NULL;
    memory_card_t *var_s1 = NULL;

    EnterCriticalSection();
    var_s2 = 0;
    var_s1 = arg0;
    var_s0 = &D_80086E78;
    do {
        temp_a1 = *var_s0;
        var_s1->m_Unk4 = OpenEvent(0xF4000001, temp_a1, 0x2000, 0);
        var_s0 += 1;
        var_s2 += 1;
        var_s1 = (memory_card_t *) ((u32) var_s1 + 4);
    } while (var_s2 < 4);
    ExitCriticalSection();
    func_8004F394(arg0);
    return 1;
}

int func_8004E678(memory_card_t *This) {
    func_8004F3BC(This);
    func_8004F40C(This, CloseEvent, 1);
    return 1;
}

s32 func_8004E6B8(memory_card_t *This, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 temp;
    s32 retries;
    s32 result;

    retries = 0xA;
    *arg2 = 0;
    result = func_8004E77C(This, arg1, &temp, arg3);
    while (result == 0 || *arg1 != 0 || *arg3 == 0) {
        result = func_8004E77C(This, arg1, arg2, arg3);
        if (retries-- == 0) {
            break;
        }
    }
    *arg2 |= temp;
    return result;
}

s32 func_8004E77C(memory_card_t *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    if (func_8004E7D0(arg0, arg1, arg2) != 0) {
        func_8004E890(arg0, arg1, arg3);
    }
#ifdef NON_MATCHING
    return 0;
#endif
}

s32 func_8004E7D0(memory_card_t *This, s32 *arg1, s32 *arg2) {
    s32 ok;
    s32 status;

    ok = 1;
    *arg1 = 0;
    *arg2 = 0;
    func_8004F3E4(This);
    do {
    } while (_card_info(This->m_Unk3) == 0);
    status = func_8004F4A4(This);
    if (status == 0x100) {
        ok = 0;
    } else if (status == 0x8000) {
        ok = 0;
        *arg1 = 1;
    } else if (status == 0x2000) {
        *arg2 = 1;
        _card_clear(This->m_Unk3);
    } else {
        return ok;
    }
    return ok;
}

s32 func_8004E890(memory_card_t *This, s32 *arg1, s32 *arg2) {
    s32 ok;
    s32 status;

    ok = 1;
    *arg1 = 0;
    *arg2 = 1;
    func_8004F3E4(This);
    do {
    } while (_card_load(This->m_Unk3) == 0);
    status = func_8004F4A4(This);
    if (status == 0x100) {
        ok = 0;
    } else if (status == 0x8000) {
        ok = 0;
        *arg1 = 1;
    } else if (status == 0x2000) {
        *arg2 = 0;
    } else {
        return ok;
    }
    return ok;
}

s32 func_8004E940(memory_card_t *This) {
    s32 retries;
    s32 result;
    char *dev;

    retries = 0xA;
    do {
        dev = D_8008AAA4;
        if (This->m_Unk2 != 0) {
            dev = D_8008AA9C;
        }
        result = format(dev);
    } while (result == 0 && retries--);
    return result;
}

s32 func_8004E9AC(memory_card_t *This, char *dst, char *name) {
    s32 retries;
    s32 result;

    retries = 0;
    if ((name == NULL) || (*name == 0)) {
        return 0;
    }
    do {
        result = func_8004EA38(This, dst, name);
    } while (result == 0 && retries--);
    return result;
}

s32 func_8004EA38(memory_card_t *This, char *dst, char *name) {
    char path[0x20];
    s32 fd;
    u8 *mem;

    fd = open(func_8004F32C(path, This->m_Unk2, name), 1);
    if (fd == -1) {
        return 0;
    }
    if (dst != 0) {
        mem = memory_allocate_mem(0x80);
        read(fd, mem, 0x80);
        strcpy(dst, (char *)(mem + 4));
        memory_free_mem(mem);
    }
    close(fd);
    return 1;
}


char *func_8004EADC(memory_card_t *This, char *buf, char *prefix, char **suffixes) {
    char **var_s0 = suffixes;

    if (*var_s0 != 0) {
        do {
            strcpy(buf, prefix);
            strcat(buf, *var_s0);
            if (This->vtable->Unk20(This, 0, buf) == 0) {
                return buf;
            }
            var_s0 += 1;
        } while (*var_s0 != 0);
    }
    return 0;
}

s32 func_8004EB88(memory_card_t *This, s32 *vals, char **out, char *prefix, char **suffixes) {
    char buf[0x20];
    s32 count;

    count = 0;
    if (*suffixes != 0) {
        do {
            strcpy(buf, prefix);
            strcat(buf, *suffixes);
            if (This->vtable->Unk20(This, *vals, buf) != 0) {
                count += 1;
                vals += 1;
                *out = *suffixes;
                out += 1;
            }
            suffixes += 1;
        } while (*suffixes != 0);
    }
    return count;
}

s32 func_8004EC5C(memory_card_t *This, u8 unused, s32 size) {
    s32 retries;
    s32 result;

    retries = 0xA;
    do {
        result = func_8004ECCC(This, unused, size);
    } while (result == 0 && retries--);
    return result;
}

s32 func_8004ECCC(memory_card_t *This, s32 unused, s32 size) {
    char path[0x20];
    s32 fd;
    u32 blocks;

    blocks = (u32)(size + 0x21FF) >> 13;
    fd = open(func_8004F32C(path, This->m_Unk2, D_8008AAAC), (blocks << 16) | 0x200);
    if (fd == -1) {
        return 0;
    }
    close(fd);
    delete(path);
    return 1;
}



s32 func_8004ED40(memory_card_t *This, char *name, void *buf, s32 size) {
    s32 retries;
    s32 result;

    retries = 0xA;
    do {
        result = func_8004EDC0(This, name, buf, size);
    } while (result == 0 && retries--);
    return result;
}

s32 func_8004EDC0(memory_card_t *This, char *name, void *buf, s32 size) {
    char path[0x20];
    s32 fd;
    u8 *hdr;
    s32 off;
    s32 result;

    fd = open(func_8004F32C(path, This->m_Unk2, name), 1);
    if (fd != -1) {
        hdr = memory_allocate_mem(0x80);
        read(fd, hdr, 0x80);
        off = (hdr[2] << 7) - 0x780;
        memory_free_mem(hdr);
        lseek(fd, off, 0);
        read(fd, buf, size);
        close(fd);
        result = 1;
        goto end;
    }
    result = 0;
end:
    return result;
}

s32 func_8004EF6C(memory_card_t *, char *, void *, s32, s32, s32, s32);
void func_800507F8(void *, void *);

s32 func_8004EEA0(memory_card_t *This, char *name, void *buf, u8 a3, s32 a4, s32 a5, s32 a6) {
    s32 retries;
    s32 result;

    retries = 0xA;
    func_800507F8(buf, name);
    do {
        result = func_8004EF6C(This, name, buf, a3, a4, a5, a6);
    } while (result == 0 && retries--);
    if (result == 0) {
        func_800507F8(buf, NULL);
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EF6C);

char *func_8004F32C(char *dst, s32 port, char *suffix) {
    char *prefix;

    prefix = D_8008AAA4;
    if (port != 0) {
        prefix = D_8008AA9C;
    }
    __builtin_memcpy(dst, prefix, 6);
    strcat(dst, suffix);
    return dst;
}

void func_8004F394(memory_card_t *This) {
    func_8004F40C(This, EnableEvent, 1);
}

void func_8004F3BC(memory_card_t *This) {
    func_8004F40C(This, DisableEvent, 1);
}

void func_8004F3E4(memory_card_t *This) {
    func_8004F40C(This, TestEvent, 0);
}

s32 func_8004F40C(memory_card_t *This, long (*fn)(unsigned long), s32 critical) {
    s32 i;
    s32 result;
    u8 *cursor;

    if (critical != 0) {
        EnterCriticalSection();
    }
    i = 0;
    cursor = (u8 *)This;
    do {
        result = fn(*(unsigned long *)(cursor + 0x14));
        if (result == 0) {
            break;
        }
        i++;
        cursor += 4;
    } while (i < 4);
    if (critical != 0) {
        ExitCriticalSection();
    }
    return result;
}

s32 func_8004F4A4(memory_card_t *This) {
    return func_8004F4C8(&This->m_Unk4, 4);
}

s32 func_8004F4C8(s32 *events, s32 count) {
    char dummy_stack_padding[8];
    s32 *var_s4;
    s32 var_s3;
    s32 *var_s5;
    s32 var_s0;
    s32 *var_s1;
    s32 var_s2;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[7]) {
    }

    var_s4 = events;
    var_s3 = count;
    var_s5 = &D_80086E78;
    do {
        var_s0 = 0;
        if (var_s3 > 0) {
            var_s1 = var_s4;
            do {
                var_s2 = var_s0 * 4;
                if (TestEvent(*var_s1) != 0) {
                    return *(s32 *)(var_s2 + (u32)var_s5);
                }
                var_s0 += 1;
                var_s1 += 1;
            } while (var_s0 < var_s3);
        }
    } while (1);
}

void func_8004F55C(memory_card_t *This, s32 a1, s32 a2, void *a3, void *a4, s32 a5, s32 a6) {
    This->m_Unk11 = a1;
    This->m_Unk12 = a2;
    This->m_Unk13 = 0;
    This->m_Unk25 = a5;
    This->m_Unk26 = a6;
    This->vtable->Unk3(This, a3);
    This->vtable->Unk3(This, a4);
    This->m_Unk27 = 0;
    This->m_Unk9 = 0;
    This->m_Unk8 = 0;
}

void func_8004F5DC(memory_card_t *This) {
  This->m_Unk26 = 0;
  This->m_Unk25 = 0;
  This->vtable->Unk4(This, This->m_Unk23);
  This->vtable->Unk4(This, This->m_Unk24);
}

void func_8004F638(memory_card_t *This, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 state;
    s32 temp_v0;

    This->m_Unk15 = a1;
    This->m_Unk16 = a2;
    This->m_Unk20 = a3;
    This->m_Unk8 = 1;
    This->m_Unk21 = a4;
    if (func_8004F9D8(This) != 0) {
        func_8004F810(This);
        func_8004F704(This);
        temp_v0 = This->vtable->Unk22(
            This, This->m_Unk13, This->m_Unk14, This->m_Unk11, This->m_Unk12);
        This->m_Unk10 = temp_v0;
        if (temp_v0 != 0) {
            func_8004F784(This);
            state = 0x12;
            if (This->m_Unk9 == 0xE) {
                state = 0xF;
            }
        } else {
            state = 0xD;
            This->m_Unk10 = 0xF;
        }
        This->vtable->Unk30(This, state);
    }
}

void func_8004F704(memory_card_t *This) {
    s32 i;

    if (This->m_Unk13 == 0) {
        This->m_Unk13 = (s32) memory_allocate_mem(0x40);
        i = 0;
        do {
            ((void **) This->m_Unk13)[i] = memory_allocate_mem(0x41);
            i += 1;
        } while (i < 0xF);
        This->m_Unk14 = (s32) memory_allocate_mem(0x40);
    }
}

void func_8004F784(memory_card_t *This) {
    s32 i;
    s32 off;

    i = This->m_Unk10;
    if (i < 0xF) {
        do {
            off = i * 4;
            i += 1;
            *(s32 *) (off + This->m_Unk13) = memory_free_mem(*(void **) (off + This->m_Unk13));
        } while (i < 0xF);
    }
    *(s32 *) ((i * 4) + This->m_Unk13) = 0;
}

void func_8004F810(memory_card_t *This) {
    char dummy_stack_padding[8];
    s32 i;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[7]) {
    }

    if (This->m_Unk13 != 0) {
        i = 0;
        memory_free_mem((void *)This->m_Unk14);
        if (This->m_Unk10 > 0) {
            do {
                memory_free_mem(*(void **)(This->m_Unk13 + (i * 4)));
                i += 1;
            } while (i < This->m_Unk10);
        }
        memory_free_mem((void *)This->m_Unk13);
        This->m_Unk13 = 0;
    }
}

s32 func_8004F9D8(memory_card_t *This);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F8A4);

s32 func_8004F9D8(memory_card_t *This) {
    s32 slot0;
    s32 slot1;
    s32 slot2;
    s32 flag;
    s32 mode;

    This->vtable->Unk16(This);
    flag = This->vtable->Unk18(This, &slot0, &slot1, &slot2);
    This->vtable->Unk17(This);
    if (flag == 0) {
        goto mode2;
    }
    if (slot1 != 0) {
        goto recheck;
    }
    if (slot2 != 0) {
        return 1;
    }
recheck:
    if (flag != 0) {
        goto chain;
    }
mode2:
    mode = 2;
    goto done;
chain:
    if (slot0 != 0) {
        mode = 3;
        goto done;
    }
    if (slot1 != 0) {
        mode = 4;
        goto done;
    }
    if (slot2 != 0) {
        goto done;
    }
    if (This->m_Unk8 == 1) {
        mode = 5;
    } else {
        mode = 6;
    }
done:
    This->vtable->Unk30(This, mode);
    return 0;
}

s32 func_8004FB04(memory_card_t *This, void *Unk, s32 a2) {
    memory_card_vtable_t *vtable;
    s32 unk;

    vtable = This->vtable;
    base_class_get_vtable()->Unk13(This, Unk, a2);
    unk = **(s32 **)Unk;
    if ((unk & 0xF) == 2) {
        return vtable->Unk33(This, Unk, a2);
    }
    if ((unk & 0xF) == 5) {
        return vtable->Unk37(This, Unk, a2);
    }
    if ((unk & 0xFF) == 16) {
        return vtable->Unk40(This, Unk, a2);
    }
    if ((unk & 0xFF) == 32) {
        return vtable->Unk43(This, Unk, a2);
    }
    return 0x20;
}


void func_8004FBE4(memory_card_t *This, s32 Unk) {
    char dummy_stack_padding[8];
    memory_card_vtable_t *vtable;
    s32 state;
    s32 result;
    void (*fn)(void *);
    s32 i;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[7]) {
    }

    state = Unk;
    vtable = This->vtable;
    if (This->m_Unk9 == Unk) {
        state = 0x17;
    }
    vtable->Unk11(This, state);
    vtable->Unk32(This);
    vtable->Unk31(This, state);
    This->m_Unk22 = 0;

    switch (state) {
        case 19:
            result = vtable->Unk19(This);
            state = 8;
            if (result) {
                state = 0x11;
            }
            goto call_unk30;
        case 20:
            if (*(u8 *)This->m_Unk15 == 0) {
                vtable->Unk21(This, This->m_Unk15, This->m_Unk11,
                                                                  This->m_Unk12);
            }
            result = vtable->Unk25(
                This, This->m_Unk15, This->m_Unk16, *(u8 *)&This->m_Unk18, This->m_Unk19, This->m_Unk20,
                This->m_Unk21);
            state = 0xC;
            goto check_result;
        case 21:
            result = vtable->Unk24(This, This->m_Unk15, This->m_Unk20,
                                                                    This->m_Unk21);
            state = 0x10;
        check_result:
            if (result) {
                state = 0x16;
            }
        call_unk30:
            vtable->Unk30(This, state);
            break;
        case 17:
            fn = vtable->Unk38;
            goto do_call;
        case 18:
            fn = vtable->Unk41;
        do_call:
            fn(This);
            break;
    }

    if ((u32)(state - 0x16) < 2U) {
        if (This->m_Unk8 == 1) {
            if (This->m_Unk13 != 0) {
                i = 0;
                memory_free_mem((void *)This->m_Unk14);
                if (This->m_Unk10 > 0) {
                    do {
                        memory_free_mem(*(void **)(This->m_Unk13 + (i * 4)));
                        i++;
                    } while (i < This->m_Unk10);
                }
                memory_free_mem((void *)This->m_Unk13);
                This->m_Unk13 = 0;
            }
        }
        This->m_Unk9 = 0;
        This->m_Unk8 = 0;
    } else {
        This->m_Unk9 = state;
    }
}

void func_8004FE24(memory_card_t *This, s32 idx) {
    char path[0x20];
    char *pathp;
    char *name;
    tim_image_t *tex;
    void *obj;

    if (idx < 0x11) {
        if (This->m_Unk25 != 0) {
            if (This->m_Unk27 == 0) {
                pathp = path;
                path[0] = 0;
                name = D_80086E80[idx];
                strcat(pathp, D_8008AAB4);
                strcat(pathp, name);
                strcat(pathp, D_8008AABC);
                tex = tim_image_create(pathp);
                tex->vtable->Unk14(tex);
                obj = func_80041C9C(tex, &D_80086EC4, 0);
                This->m_Unk27 = (s32)obj;
                tex->vtable->Destruct(tex);
                (*(void (**)(void *, s32, s32 *))(*(u32 *)obj + 0x4C))(obj, This->m_Unk25, &D_8008AA94);
            }
        }
    }
}

void func_8004FF40(memory_card_t *This) {
    s32 m_Unk27; // $a0

  m_Unk27 = This->m_Unk27;
  if ( m_Unk27 )
    This->m_Unk27 = (*(int ( **)(s32))(*(s32 *)m_Unk27 + 4))(m_Unk27);
}

s32 func_8004FF90(memory_card_t *This, s32 unused, s32 state) {
    void (*fn)(void *);

    (void)unused;
    if (This->m_Unk9 != 0) {
        if (state == 0x19) {
            fn = This->vtable->Unk35;
        } else {
            if (state != 0x17) {
                return 0x17;
            }
            fn = This->vtable->Unk36;
        }
        return ((s32(*)(void *))fn)(This);
    }
    return 0x19;
}

void func_8004FFF4(memory_card_t *This, s32 Unk) {
    s32 m_Unk26; // $a0

  m_Unk26 = This->m_Unk26;
  if ( m_Unk26 ) {
    (*(void ( **)(s32, int, int, int))(*(s32 *)m_Unk26 + 128))(m_Unk26, Unk, 127, 127);
  }
}

void func_80050034(memory_card_t *This) {
    memory_card_vtable_t *vtable;

    vtable = This->vtable;
    switch (This->m_Unk9) {
        case 2:
        case 4:
        case 10:
        case 14:
            vtable->Unk34(This, 0);
            if (This->m_Unk9 == 0xE) {
                strcpy((char *)This->m_Unk15, (char *)This->m_Unk11);
                strcat((char *)This->m_Unk15,
                       *(char **)(This->m_Unk14 + (This->m_Unk31 * 4)));
                strcpy((char *)This->m_Unk16,
                       *(char **)(This->m_Unk13 + (This->m_Unk31 * 4)));
            }
            if (This->m_Unk8 == 2) {
                vtable->Unk29(
                    This, This->m_Unk15, This->m_Unk16, This->m_Unk17, *(u8 *)&This->m_Unk18,
                    This->m_Unk19, This->m_Unk20, This->m_Unk21);
            } else if (This->m_Unk8 == 1) {
                vtable->Unk28(
                    This, This->m_Unk15, This->m_Unk16, This->m_Unk20, This->m_Unk21);
            }
            break;
        case 6:
            vtable->Unk34(This, 0);
            vtable->Unk30(This, 7);
            break;
        case 3:
        case 5:
        case 8:
        case 9:
        case 12:
        case 13:
        case 16:
            vtable->Unk34(This, 0x10);
            vtable->Unk30(This, 0x17);
            break;
    }
}

void func_800501F0(memory_card_t *This) {
    switch (This->m_Unk9) {
        case 4:
        case 6:
        case 0xA:
        case 0xE:
            This->vtable->Unk34(This, 0x10);
            This->vtable->Unk30(This, 0x17);
            break;
    }
}

void func_80050280(memory_card_t *This) {
    if (This->m_Unk9 == 7) {
        if (This->m_Unk22++ < 6) {
            return;
        }
        This->vtable->Unk30(This, 0x13);
    } else if (This->m_Unk9 == 0xB) {
        if (This->m_Unk22++ < 6) {
            return;
        }
        This->vtable->Unk30(This, 0x14);
    } else if (This->m_Unk9 == 0xF) {
        if (This->m_Unk22++ < 6) {
            return;
        }
        This->vtable->Unk30(This, 0x15);
    }
}

void func_80050340(memory_card_t *This) {
    void *obj;

    if (This->m_Unk25 != 0 && This->m_Unk23 != 0) {
        if (This->m_Unk29 == NULL) {
            This->m_Unk29 = func_80050BA8((This->m_Unk17 * 2) + This->m_Unk16, 1);
            This->m_Unk28 = 1;
        }
        This->vtable->Unk3(This, This->m_Unk29);
        obj = This->m_Unk29;
        (*(void (**)(void *, s32))(*(u32 *) obj + 0x44))(obj, This->m_Unk25);
        obj = This->m_Unk29;
        (*(void (**)(void *, s32, s32, s32))(*(u32 *) obj + 0x4C))(obj, (s32) This->m_Unk23,
                                                                   (s32) This->m_Unk24, This->m_Unk26);
    }
}

void func_80050410(memory_card_t *This) {
    void *obj;

    if (This->m_Unk25 != 0 && This->m_Unk23 != 0) {
        obj = This->m_Unk29;
        if (obj != NULL) {
            (*(void (**)(void *))(*(u32 *) obj + 0x50))(obj);
            obj = This->m_Unk29;
            (*(void (**)(void *))(*(u32 *) obj + 0x48))(obj);
            if (This->m_Unk28 != 0) {
                obj = This->m_Unk29;
                (*(void (**)(void *))(*(u32 *) obj + 4))(obj);
                This->m_Unk29 = NULL;
            }
        }
    }
}

void func_800504D0(memory_card_t *This, s32 unused, s32 Unk) {
    (void)unused;
    switch (Unk) {
        case 2:
            This->vtable->Unk39(This);
            This->vtable->Unk29(
                This, This->m_Unk15, This->m_Unk16, This->m_Unk17, *(u8 *)&This->m_Unk18, This->m_Unk19,
                This->m_Unk20, This->m_Unk21);
            break;
        case 3:
            This->vtable->Unk39(This);
            This->vtable->Unk30(This, 0x17);
            break;
    }
}

void func_800505A8(memory_card_t *This) {
    void *obj;

    if (This->m_Unk25 != 0 && This->m_Unk23 != 0) {
        if (This->m_Unk30 == NULL) {
            This->m_Unk30 = func_80051A5C(This->m_Unk13, 1);
            This->m_Unk28 = 1;
        }
        This->vtable->Unk3(This, This->m_Unk30);
        obj = This->m_Unk30;
        (*(void (**)(void *, s32))(*(u32 *) obj + 0x44))(obj, This->m_Unk25);
        obj = This->m_Unk30;
        (*(void (**)(void *, s32, s32, s32))(*(u32 *) obj + 0x4C))(obj, (s32) This->m_Unk23,
                                                                   (s32) This->m_Unk24, This->m_Unk26);
    }
}

void func_80050670(memory_card_t *This) {
    void *obj;

    if (This->m_Unk25 != 0 && This->m_Unk23 != 0) {
        obj = This->m_Unk30;
        if (obj != NULL) {
            (*(void (**)(void *))(*(u32 *) obj + 0x50))(obj);
            obj = This->m_Unk30;
            (*(void (**)(void *))(*(u32 *) obj + 0x48))(obj);
            if (This->m_Unk28 != 0) {
                obj = This->m_Unk30;
                (*(void (**)(void *))(*(u32 *) obj + 4))(obj);
                This->m_Unk30 = NULL;
            }
        }
    }
}

void func_80050730(memory_card_t *This, void *UnkClass, s32 Unk) {
    switch (Unk) {
        case 2:
            This->m_Unk31 = (*(s32(**)(void *))(*(u32 *) UnkClass + 156))(UnkClass);
            This->vtable->Unk42(This);
            This->vtable->Unk30(This, 14);
            break;

        case 3:
            This->vtable->Unk42(This);
            This->vtable->Unk30(This, 23);
            break;

        default:
            break;
    }
}

memory_card_vtable_t *memory_card_get_vtable(void) {
    return &g_MEMORY_CARD_VTABLE;
}
