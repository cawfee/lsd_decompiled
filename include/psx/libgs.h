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

typedef struct {
    int vx, vy, vz;
    unsigned char r, g, b;
} gs_light_t;

void GsDefDispBuff(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
void GsInitGraph(
    unsigned short x, unsigned short y, unsigned short intmode, unsigned short dith, unsigned short varmmode);
void GsGetTimInfo(unsigned long *im, gs_image_t *tim);
void GsSetAmbient(unsigned long r, unsigned long g, unsigned long b);
void GsMapModelingData(unsigned long address);
void GsSetFlatLight(unsigned int id, gs_light_t *lt);

#endif // PSX_LIBGS_H