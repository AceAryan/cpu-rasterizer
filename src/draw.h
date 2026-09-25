#include <string>
#include "framebuffer.h"

void drawLine(Framebuffer &f, int x0, int y0, int x1, int y1, int r, int g, int b){
    // using Bresenham's line drawing algorithm

    bool steep = abs(y1-y0) > abs(x1-x0);
    if(steep){
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if(x0 > x1){
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int delx = x1 - x0;
    int dely = y1 - y0;

    int yi = 1;
    if(dely < 0){
        yi = -1;
        dely = -dely;
    }

    int p = 2*dely - delx;

    while(x0 <= x1){
        if(steep) f.setPixel(y0, x0, r, g, b);
        else f.setPixel(x0, y0, r, g, b);
        x0++;
        if(p < 0) p += 2*dely;
        else{
            y0 += yi;
            p += 2*dely - 2*delx;
        }
    }
}

void drawTriangle(Framebuffer &f, int x0, int y0, int x1, int y1, int x2, int y2, int r, int g, int b){
    drawLine(f, x0, y0, x1, y1, r, g, b);
    drawLine(f, x1, y1, x2, y2, r, g, b);
    drawLine(f, x2, y2, x0, y0, r, g, b);
}