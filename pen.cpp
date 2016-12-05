#include "pen.h"

void drawLine(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    // bool steep = false;

    // if(abs(x0 - x1) < abs(y0 - y1)) {
    //     swap(x0, y0);
    //     swap(x1, y1);

    //     steep = true;
    // }

    // if(x0 > x1) {
    //     swap(x0, x1);
    //     swap(y0, y1);
    // }

    // for(int x = x0; x <= x1; x++) {
    //     float t = (x - x0) / (float)(x1 - x0);
    //     int y = y0  * (1. - t) + y1 * t;
    //     if(steep) {
    //         image.set(y, x, color);
    //     } else {
    //         image.set(x, y, color);
    //     }
    // }

    int deltaX = abs(x1 - x0);
    int deltaY = abs(y1 - y0);
    int error = 0;
    int deltaError = deltaY;
    int y = y0;

    for(int x = x0; x < x1; x++) {
        image.set(x, y, color);
        error += deltaError;

        if(2 * error >= deltaX) {
            y -= 1;
            error -= deltaX;
        }
    }
}

void drawCircle(int x1, int y1, int r, TGAImage &image, TGAColor color) {
    int x = 0;
    int y = r;
    int delta = 1 - 2 * r;
    int error = 0;
    
    while(y >= 0) {
       image.set(x1 + x, y1 + y, color);
       image.set(x1 + x, y1 - y, color);
       image.set(x1 - x, y1 + y, color);
       image.set(x1 - x, y1 - y, color); 
       
       error = 2 * (delta + y) - 1;

       if(delta < 0 && error <= 0) {
           delta += 2 * ++x + 1;
           continue;
       }
    
        error = 2 * (delta - x) - 1;

       if(delta > 0 && error > 0) {
           delta += 1 - 2 * --y;
           continue;
       }
       else
        x++;

       delta += 2 * (x - y);
       y--;
    }
}