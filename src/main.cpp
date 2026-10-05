#include <iostream>
#include "framebuffer.h"
#include "draw.h"
#include "model.h"

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
    
    Model model = objLoader("../assets/african_head.obj");
    for(auto& it : model.faces){
        Vertex a = model.vertices[it.v1];
        Vertex b = model.vertices[it.v2];
        Vertex c = model.vertices[it.v3];

        // implementing viewport transform

        int ax = (a.x + 1) * width/2;
        int ay = (1 - a.y) * height/2; // vertical flip
        int bx = (b.x + 1) * width/2;
        int by = (1 - b.y) * height/2;
        int cx = (c.x + 1) * width/2;
        int cy = (1 - c.y) * height/2;

        drawTriangle(f, ax, ay, a.z, bx, by, b.z, cx, cy, c.z, 255, 0, 0);
    }

    f.writePPM("../images/image9.ppm");
    
    return 0;
}