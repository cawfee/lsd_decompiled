#ifndef LSD_MEMORY_H
#define LSD_MEMORY_H

#include <common.h>

void *memory_create_manager(s32, s32);
void memory_set_manager(void *Manager);
void *memory_allocate_mem(s32);
int memory_free_mem(void *);

#endif // LSD_MEMORY_H