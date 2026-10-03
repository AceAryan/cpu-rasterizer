#include <iostream>
#include "framebuffer.h"
#include "draw.h"

int main(){
    int width = 800;
    int height = 600;

    // usign \n instead of std::endl because endl flushes buffer every call making it slower

    Framebuffer f(800, 600);

    // for(int j=0; j<600; j++){
    //     for(int i=0; i<800; i++){
    //         f.setPixel(i, j , 999.0f, (1 - (float)i/800)*255, ((float)i/800)*255, 0);
    //     }
    // }

    f.clearBackground(0, 0, 0);

    // drawLine(f, 100, 100, 500, 100, 255, 255, 255);     
    // drawLine(f, 500, 100, 100, 500, 255, 255, 255);       
    // drawLine(f, 100, 500, 100, 100, 255, 255, 255); 
    
    // B is farther (z=10), drawn FIRST
    drawFilledTriangle(f, 100, 100, 10.0f, 400, 100, 10.0f, 250, 400, 10.0f, 0, 0, 255);

    // A is closer (z=2), drawn SECOND
    drawFilledTriangle(f, 200, 150, 2.0f, 500, 150, 2.0f, 350, 450, 2.0f, 255, 0, 0);

    f.writePPM("image8.ppm");
    
    return 0;
}