#ifndef PSX_LIBGS_H
#define PSX_LIBGS_H

typedef struct {
    unsigned long pmode;
    short px, py;
    unsigned short pw, ph;
    unsigned long *pixel;
    short cx, cy;
    unsigned short cw, ch;
    unsigned long *clut;
} gs_image_t;

void GsDefDispBuff(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
void GsInitGraph(
    unsigned short x, unsigned short y, unsigned short intmode, unsigned short dith, unsigned short varmmode);
void GsGetTimInfo(unsigned long *im, gs_image_t *tim);

#endif