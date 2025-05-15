#ifndef PSX_LIBCD_H
#define PSX_LIBCD_H

void StSetRing(unsigned long *ring_addr, unsigned long ring_size);
unsigned long StFreeRing();
void StUnSetRing(void);

#endif