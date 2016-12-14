#include "pen.h"

#include <iostream>

void drawLine(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {

    int width = abs(x0 - x1);
    int height = abs(y0 - y1);

    if(width > height)
    {
        for(int x = x0; x <= x1; x++)
        {
            int y = ((x + y0) * height / width);
            image.set(x, y, color);
        }

        cout << 1 << std::endl;
    }
    else
    {
        for(int y = y0; y <= y1; y++)
        {
            int x = ((y + x0) * width / height);
            image.set(x, y, color);
        }

        cout << 2 << std::endl;
    }
    

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

    // for(int x = x0; x < x1; x++) {
    //     float t = (x - x0) / (float)(x1 - x0);
    //     int y = y0  * (1. - t) + y1 * t;
    //     if(steep) {
    //         image.set(y, x, color);
    //     } else {
    //         image.set(x, y, color);
    //     }
    // }



    // int deltaX = abs(x1 - x0);
    // int deltaY = abs(y1 - y0);
    // int error = 0;
    // int deltaError = deltaY;
    // int y = y0;

    // for(int x = x0; x < x1; x++) {
    //     image.set(x, y, color);
    //     error += deltaError;

    //     if(2 * error >= deltaX) {
    //         y -= 1;
    //         error -= deltaX;
    //     }
    // }
}

void drawRect(int x, int y, int width, int height, TGAImage &image, TGAColor color)
{
    drawLine(x, y, width - x, y, image, color);
    drawLine(x, y, x, height - y, image, color);
    drawLine(width, y, width - x, height - y, image, color);
    drawLine(x, height, width - x, height - y, image, color);
}

void drawSquare(int x, int y, int width, TGAImage &image, TGAColor color)
{
    drawRect(x, y, width, width, image, color);
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
