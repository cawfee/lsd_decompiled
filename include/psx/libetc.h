#ifndef PSX_LBIETC_H
#define PSX_LBIETC_H

#define getScratchAddr(offset)  ((u_long *)(0x1f800000+(offset)*4))

int VSync(int mode);

#endif // PSX_LBIETC_H