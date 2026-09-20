#include <iostream>
#include "framebuffer.h"

int main(){
    int width = 800;
    int height = 600;

    // usign \n instead of std::endl because endl flushes buffer every call making it slower

    Framebuffer f(800, 600);

    for(int i=0; i<800; i++){
        for(int j=0; j<600; j++){
            f.setPixel(i, j , (1 - (float)i/800)*255, ((float)i/800)*255, 0);
        }
    }

    f.writePPM("image2.ppm");

    return 0;
}