#ifndef PSX_LIBGTE_H
#define PSX_LIBGTE_H

void SetGeomScreen(long h);
void ApplyMatrixSV(void *mtx, void *v0, void *v1);
void ApplyMatrixLV(void *mtx, void *v0, void *v1);
long ratan2(long x, long y);

#endif // PSX_LIBGTE_H