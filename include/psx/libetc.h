#ifndef PSX_LBIETC_H
#define PSX_LBIETC_H

#define GET_SCRATCH_ADDR(offset) ((u_long *) (0x1f800000 + (offset) * 4))

int VSync(int Mode);

#endif // PSX_LBIETC_H