#include "pen.h"

void drawLine(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    bool steep = false;

    if(abs(x0 - x1) < abs(y0 - y1)) {
        swap(x0, y0);
        swap(x1, y1);

        steep = true;
    }

    if(x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }

    for(int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float)(x1 - x0);
        int y = y0  * (1. - t) + y1 * t;
        if(steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
    }
}
