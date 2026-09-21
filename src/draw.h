#include <string>
#include "framebuffer.h"

void drawLine(Framebuffer &f, int x0, int y0, int x1, int y1, int r, int g, int b){
    // using Bresenham's line drawing algorithm

    int delx = x1 - x0;
    int dely = y1 - y0;
    int p = 2*dely - delx;

    while(x0 <= x1){
        f.setPixel(x0, y0, r, g, b);
        x0++;
        if(p < 0) p += 2*dely;
        else{
            y0++;
            p += 2*dely - 2*delx;
        }
    }
}