#ifndef _PEN_
#define _PEN_

#include <stdlib.h>
#include "tgaimage.h"

using namespace std;

void drawLine(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

void drawCircle(int x, int y, int r, TGAImage &image, TGAColor color);

#endif // _PEN_