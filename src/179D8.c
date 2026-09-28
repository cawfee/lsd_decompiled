#include "common.h"

#include "file_buf.h"
#include "memory.h"
#include "display.h"

typedef struct unk_list_node {
    /* 0x00 */ s32 m_Unk0;
    /* 0x04 */ s32 m_Unk1;
    /* 0x08 */ s32 m_Unk2;
    /* 0x0C */ s32 m_Unk3;
    /* 0x10 */ s32 m_Unk4;
    /* 0x14 */ s32 m_Unk5;
    /* 0x18 */ s32 m_Unk6;
    /* 0x1C */ struct unk_list_node *m_Prev;
    /* 0x20 */ struct unk_list_node *m_Next;
} unk_list_node_t;

extern void VSyncCallback();
display_t *get_display(void);
extern s32 get_current_data_folder();
extern char *strcpy(char *, char *);
extern char *strcat(char *, char *);
extern char *strstr(char *, char *);
extern s32 CdSetDebug(s32);
extern s32 CdControlB(s32, u8 *, s32 *);

s32 func_800280EC(void);
void func_800280D0(void);
void func_800280E0(void);
void func_80028218(void);
void func_8002858C(void);
void func_800286E4(void);
s32 func_80018458(void);

extern s32 D_8008A858;
extern s32 D_8008A89C;
extern char D_8008A8A8[];
extern s32 D_8008A85C;
extern s32 D_8008A860;
extern s32 D_8008A864;
extern s32 D_8008A868;
extern s32 D_8008A86C;
extern s32 D_8008A870;
extern s32 D_8008A874;
extern s32 D_8008A878;
extern s32 D_8008A87C;
extern s32 D_8008A888;
extern s32 D_8008A88C;
extern s32 D_8008A890;
extern unk_list_node_t *D_8008A894;
extern s32 D_8008A898;
extern s32 D_8008A8A0;
extern s32 D_8008A8A4;
extern s32 D_8006D4E8[];

void *func_800271D8(void) {
    void *mem = memory_allocate_mem(0x2C);

    if (mem != NULL) {
        ((file_buf_vtable_t *)func_80027E68())->Construct(mem);
        return mem;
    }
    return NULL;
}

void func_80027228(file_buf_t *This) {
    file_buf_get_vtable()->Construct(This);
    This->vtable = func_80027E68();
    This->m_Unk9 = 0;
    func_80027E78();
}

void func_80027274(file_buf_t *This) {
    This->vtable->Unk28(This);
    This->vtable->file_buf_release(This);
}

void func_800272C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_800272D0);

void func_80027480(file_buf_t *arg0) {
    if (D_8008A85C == 0 && D_8008A860 == 0) {
        func_80028A34();
    } else {
        func_800280D0();
        if (arg0->m_Unk9 != 0) {
            if (D_8008A864 == 0) {
                func_80028844(0, 0);
                arg0->m_Unk2 = 0;
                func_80028864();
            }
        } else {
            func_800282AC(arg0, 0, 3, 0, 0);
        }
        func_800280E0();
    }
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_80027528);

void func_800276C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_800276D0);

INCLUDE_ASM("asm/nonmatchings/179D8", func_80027800);

INCLUDE_ASM("asm/nonmatchings/179D8", func_80027A24);

INCLUDE_ASM("asm/nonmatchings/179D8", func_80027C80);

void func_80027D40(void) {
    func_800280D0();
    func_80028218();
    func_800280E0();
}

void func_80027D70(file_buf_t *arg0) {
    unk_list_node_t *node;
    unk_list_node_t *next;

    func_800280D0();
    if (D_8008A894 != NULL && arg0->m_Unk7_2 != 0) {
        arg0->m_Flags = 0;
        if (D_8008A894->m_Unk3 == (s32)arg0 && D_8008A894->m_Unk0 != 0 && D_8008A870 == 0) {
            CdFlush();
            func_80028864();
            D_8008A87C = D_8008A888;
            D_8008A888 = 0;
        }
        node = D_8008A894;
        if (node != NULL) {
            do {
                next = node->m_Next;
                if (node->m_Unk3 == (s32)arg0) {
                    func_800283C4(node);
                    arg0->m_Unk7_2 = arg0->m_Unk7_2 - 1;
                }
                node = next;
            } while (node != NULL);
        }
    }
    func_800280E0();
}

void *func_80027E68(void) {
    return D_8006D4E8;
}

void func_80027E78(void) {
    u8 param;

    if (D_8008A858 == 0) {
        CdSetDebug(0);
        param = 0x80;
        do {
        } while (CdControlB(0xE, &param, 0) == 0);
        D_8008A858 = 1;
    }
}

s32 func_80027EC8(void) {
    return D_8008A864;
}

s32 func_80027ED4(void) {
    return D_8008A870;
}

s32 func_80027EE0(void) {
    return D_8008A874;
}

s32 func_80027EEC(void) {
    return D_8008A878;
}

s32 func_80027EF8(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = D_8008A860;
    }
    return D_8008A85C;
}

s32 func_80027F18(s32 arg0, s32 arg1, s32 arg2) {
    display_t *disp;

    if (D_8008A864 == 0) {
        if (arg2 == 0) {
            disp = get_display();
            if (D_8008A85C == 0) {
                if (arg0 != 0) {
                    disp->vtable->display_set_vsync_callback(disp, func_800280EC);
                }
            } else {
                if (arg0 == 0) {
                    disp->vtable->display_set_vsync_callback(disp, NULL);
                }
            }
        }
        D_8008A8A4 = arg2;
        D_8008A85C = arg0;
        D_8008A860 = arg1;
        return 1;
    }
    return 0;
}

void func_80027FD8(s32 arg0) {
    D_8008A868 = arg0;
}

void func_80027FE4(s32 arg0) {
    D_8008A86C = arg0;
}

s32 func_80027FF0(void) {
    return D_8008A86C;
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_80027FFC);

void func_800280D0(void) {
    D_8008A88C = 1;
}

void func_800280E0(void) {
    D_8008A88C = 0;
}

s32 func_800280EC(void) {
    if (D_8008A88C != 0) {
        return 0;
    }
    if (func_80018458() != 0) {
        return 0;
    }
    if (D_8008A8A4 != 0) {
        VSyncCallback(0);
    }
    if (D_8008A898 == 1) {
        func_8002858C();
    } else if (D_8008A898 == 2) {
        func_800286E4();
    }
    if (D_8008A890 != 0) {
        ((void (*)(void))((void **)func_80027E68())[26])();
    }
    if (D_8008A8A4 != 0) {
        VSyncCallback(func_800280EC);
    }
    return 0;
}

void func_800281B0(void) {
    func_800280D0();
    if (D_8008A89C == 0) {
        if (D_8008A8A4 != 0) {
            VSyncCallback(func_800280EC);
        }
        D_8008A89C = 1;
    }
    D_8008A890 = 1;
    func_800280E0();
}

void func_80028218(void) {
    func_800280D0();
    if (D_8008A898 == 0) {
        if (D_8008A89C != 0) {
            if (D_8008A8A4 != 0) {
                VSyncCallback(0);
            }
            D_8008A89C = 0;
            D_8008A890 = 0;
        }
    }
    func_800280E0();
}

void func_80028280(void) {
    func_800280D0();
    D_8008A890 = 0;
    func_800280E0();
}

void func_800282AC(file_buf_t *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    unk_list_node_t *node = func_8002832C();

    node->m_Unk2 = arg2;
    node->m_Unk5 = arg3;
    node->m_Unk3 = (s32)arg0;
    node->m_Unk4 = arg1;
    node->m_Unk6 = arg4;
    arg0->m_Flags = 0;
    arg0->m_Unk7_2 = arg0->m_Unk7_2 + 1;
    func_800281B0();
}

unk_list_node_t *func_8002832C(void) {
    unk_list_node_t *node;
    unk_list_node_t *cur;

    func_800280D0();
    node = memory_allocate_mem(0x24);
    if (node != NULL) {
        node->m_Prev = NULL;
        node->m_Next = NULL;
        node->m_Unk0 = 0;
        node->m_Unk1 = 0;
        if (D_8008A894 != NULL) {
            cur = D_8008A894;
            if (cur->m_Next != NULL) {
                do {
                    cur = cur->m_Next;
                } while (cur->m_Next != NULL);
            }
            cur->m_Next = node;
            node->m_Prev = cur;
        } else {
            D_8008A894 = node;
        }
    }
    func_800280E0();
    return node;
}

void func_800283C4(unk_list_node_t *node) {
    func_800280D0();
    if (node != NULL) {
        if (node->m_Prev != NULL) {
            node->m_Prev->m_Next = node->m_Next;
        } else {
            D_8008A894 = node->m_Next;
        }
        if (node->m_Next != NULL) {
            node->m_Next->m_Prev = node->m_Prev;
        }
        memory_free_mem(node);
    }
    func_800280E0();
}

s32 func_80028448(s32 arg0) {
    s32 p = D_8008A868;
    s32 i = 0;

    func_800280D0();
    while (1) {
        if (strstr((char *)p, (char *)arg0) != 0) {
            func_800280E0();
            return p;
        }
        i++;
        p += 0x1C;
        if (i >= D_8008A86C) {
            return 0;
        }
    }
}

s32 func_800284C4(s32 arg0) {
    s32 p = D_8008A868;
    s32 i = 0;

    func_800280D0();
    while (1) {
        if (strstr((char *)p, (char *)arg0) != 0) {
            break;
        }
        i++;
        if (i >= D_8008A86C) {
            return -1;
        }
        p += 0x1C;
    }
    func_800280E0();
    return i;
}

s32 func_80028540(s32 arg0) {
    s32 base = D_8008A868;
    s32 result;

    func_800280D0();
    result = base + (arg0 * 0x1C);
    func_800280E0();
    return result;
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_8002858C);

INCLUDE_ASM("asm/nonmatchings/179D8", func_800286E4);

void func_80028844(s32 arg0, s32 arg1) {
    D_8008A864 = 1;
    D_8008A874 = arg0;
    D_8008A878 = arg1;
    D_8008A870 = 0;
    D_8008A894->m_Unk0 = 1;
}

void func_80028864(void) {
    D_8008A874 = 0;
    D_8008A878 = 0;
    D_8008A898 = 0;
    D_8008A870 = 1;
    D_8008A8A0 = 0;
    D_8008A864 = 0;
}

void func_80028888(s32 arg0) {
    D_8008A878 = arg0;
    D_8008A8A0 = 0;
}

void func_80028898(file_buf_t *This) {
    file_buf_get_vtable()->Construct(This);
    This->vtable = func_80027E68();
    This->m_Unk2 = 0;
}

void func_800288E0(file_buf_t *This) {
    file_buf_get_vtable()->Cleanup((base_class_t *)This);
}

void func_80028918(void) {
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_80028920);

s8 *func_800289CC(s8 *arg0, s8 *arg1) {
    *arg0 = 0x5C;
    strcpy(arg0 + 1, (char *)get_current_data_folder());
    strcat(arg0, arg1);
    strcat(arg0, D_8008A8A8);
    return arg0;
}

void func_80028A34(file_buf_t *This) {
    if (This->m_Unk2 != 0) {
        This->m_Unk2 = 0;
    }
}

s32 func_80028A50(file_buf_t *This) {
    if (This->m_Unk2 != 0) {
        return (((u32)This->m_Unk6 >> 11) + 1) << 11;
    }
    return 0;
}

void func_80028A7C(void) {
}

INCLUDE_ASM("asm/nonmatchings/179D8", func_80028A84);

void func_80028B64(void) {
}

s32 func_80028B6C(void) {
    return D_8008A8A4;
}
