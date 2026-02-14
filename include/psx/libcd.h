#ifndef PSX_LIBCD_H
#define PSX_LIBCD_H

void StSetRing(unsigned long *ring_addr, unsigned long ring_size);
unsigned long StFreeRing(unsigned long *base);
void StUnSetRing(void);
void StClearRing(void);
int CdSync(int mode, unsigned char *result);
unsigned long CdSyncCallback(void (*func)(int status, unsigned char *result));

#endif // PSX_LIBCD_H