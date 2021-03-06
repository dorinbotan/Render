#ifndef _PEN_
#define _PEN_

#include <stdlib.h>
#include "tgaimage.h"

using namespace std;

void drawLine(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

void drawRect(int x, int y, int width, int height, TGAImage &image, TGAColor color);

void drawSquare(int x, int y, int width, TGAImage &image, TGAColor color);

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);

void drawCircle(int x, int y, int r, TGAImage &image, TGAColor color);

#endif // _PEN_