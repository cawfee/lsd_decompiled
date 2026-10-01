#include "file/object_model_list.h"

#include "file/object_model.h"
#include "file/file_buf.h"

extern class_object_model_list_vtable_t D_8006F40C;

void file_buf_set_triple(void *, void *, s32, s32);
class_object_model_t *func_8004468C(s32);

class_object_model_list_t *func_80044A0C(s32 Unk1) {
    class_object_model_list_t *allocated = (class_object_model_list_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        if (func_80044CC4()->Construct(allocated, Unk1)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

class_object_model_list_t *func_80044A7C(class_object_model_list_t *This, s32 *pDword) {
    class_object_model_vtable_t *base_vtable;
    class_object_model_list_vtable_t *new_vtable;

    base_vtable = func_800449FC();
    base_vtable->Construct(This, (s32)pDword, 0);

    new_vtable = func_80044CC4();
    This->vtable = new_vtable;

    if (*pDword != 0) {
        if (new_vtable->Unk24(This) != 0) {
            return NULL;
        }
    }

    return This;
}

void func_80044B04(class_object_model_list_t *This) {
    This->vtable->Unk30(This);
  (*(void ( **)(class_object_model_list_t *))((s32) func_800449FC() + 12))(This);
}

void func_80044B58(class_object_model_list_t *This) {
    This->vtable->Unk29(This);
}

s32 func_80044B88(class_object_model_list_t *This) {
    s32 data[3];
    s32 i;
    s32 *entries;
    s32 count;
    s32 result;

    file_buf_set_triple(data, 0, 0, 1);
    i = 0;
    count = *(s32 *)(This->m_Unk3 + 4);
    entries = (s32 *)(This->m_Unk3 + 8);
    This->m_Unk13 = 0;
    for (i = 0; i < count; i++) {
        data[0] = This->m_Unk3 + *(s32 *)(This->m_Unk3 + 8 + i * 4);
        result = (s32)func_8004468C((s32)data);
        *entries = result;
        if (result == 0) {
            goto fail;
        }
        This->m_Unk13++;
        entries++;
    }
    return 0;
fail:
    This->vtable->Unk30(This);
    return 1;
}

s32 func_80044C58(class_object_model_list_t *This) {
    s32 result = destroy_list((s32 *)(This->m_Unk3 + 8), This->m_Unk13);
    This->m_Unk13 = 0;
    return result;
}

s32 func_80044C90(class_object_model_list_t *This, u32 Unk) {
    s32 m_Unk3;

  m_Unk3 = This->m_Unk3;
  if ( Unk < *(s32 *)(m_Unk3 + 4) )
    return *(s32 *)(4 * Unk + m_Unk3 + 8);
  else
    return 0;
}

class_object_model_list_vtable_t *func_80044CC4() {
    return &D_8006F40C;
}
