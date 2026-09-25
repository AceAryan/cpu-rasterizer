#include <iostream>
#include "framebuffer.h"
#include "draw.h"

int main(){
    int width = 800;
    int height = 600;

    // usign \n instead of std::endl because endl flushes buffer every call making it slower

    Framebuffer f(800, 600);

    for(int j=0; j<600; j++){
        for(int i=0; i<800; i++){
            f.setPixel(i, j , (1 - (float)i/800)*255, ((float)i/800)*255, 0);
        }
    }

    // drawLine(f, 100, 100, 500, 100, 255, 255, 255);     
    // drawLine(f, 500, 100, 100, 500, 255, 255, 255);       
    // drawLine(f, 100, 500, 100, 100, 255, 255, 255); 
    
    drawTriangle(f, 100, 100, 500, 100, 100, 500, 255, 255, 255);

    f.writePPM("image5.ppm");
    
    return 0;
}