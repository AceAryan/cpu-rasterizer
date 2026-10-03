#include <string>
#include "framebuffer.h"
#include <algorithm>

void drawLine(Framebuffer &f, int x0, int y0, float z0, int x1, int y1, float z1, int r, int g, int b){
    // using Bresenham's line drawing algorithm

    bool steep = abs(y1-y0) > abs(x1-x0);
    if(steep){
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if(x0 > x1){
        std::swap(x0, x1);
        std::swap(y0, y1);
        std::swap(z0, z1);
    }

    int delx = x1 - x0;
    int dely = y1 - y0;

    int yi = 1;
    if(dely < 0){
        yi = -1;
        dely = -dely;
    }

    int p = 2*dely - delx;
    int xstart = x0;

    while(x0 <= x1){
        float t = (float)(x0 - xstart) / delx;
        float z = z0 + t*(z1 - z0);

        if(steep) f.setPixel(y0, x0, z, r, g, b);
        else f.setPixel(x0, y0, z, r, g, b);
        x0++;
        if(p < 0) p += 2*dely;
        else{
            y0 += yi;
            p += 2*dely - 2*delx;
        }
    }
}

void drawTriangle(Framebuffer &f, int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, int r, int g, int b){
    drawLine(f, x0, y0, z0, x1, y1, z1, r, g, b);
    drawLine(f, x1, y1, z1, x2, y2, z2, r, g, b);
    drawLine(f, x2, y2, z2, x0, y0, z0, r, g, b);
}

void drawFilledTriangle(Framebuffer &f, int x0, int y0, float z0, int x1, int y1, float z1, int x2, int y2, float z2, int r, int g, int b){
    // drawLine(f, x0, y0, x1, y1, r, g, b);
    // drawLine(f, x1, y1, x2, y2, r, g, b);
    // drawLine(f, x2, y2, x0, y0, r, g, b);
 
    // using Barycentric coordinates

    int xmin = std::min({x0,x1,x2});
    int xmax = std::max({x0,x1,x2});

    int ymin = std::min({y0,y1,y2});
    int ymax = std::max({y0,y1,y2});

    double denom = (y1 - y2) * (x0 - x2) + (x2 - x1) * (y0 - y2);
    if(denom == 0.0) return; // Degenerate triangle

    for(int i=xmin; i<=xmax; ++i){
        for(int j=ymin; j<=ymax; ++j){
            double a = (((y1-y2)*(i-x2)) + ((x2-x1)*(j-y2))) / denom;
            double b = (((y2-y0)*(i-x2)) + ((x0-x2)*(j-y2))) / denom;
            double c = 1.0 - a - b;

            float z = a*z0 + b*z1 + c*z2;

            if((a > 0.0) && (b > 0.0) && (c > 0.0)) f.setPixel(i,j,z,r,g,b);
        }
    }
}