#include <iostream>
#include "framebuffer.h"
#include "draw.h"
#include "model.h"
#include "vec.h"

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
        Vec3 a = {model.vertices[it.v1].x, model.vertices[it.v1].y, model.vertices[it.v1].z};
        Vec3 b = {model.vertices[it.v2].x, model.vertices[it.v2].y, model.vertices[it.v2].z};
        Vec3 c = {model.vertices[it.v3].x, model.vertices[it.v3].y, model.vertices[it.v3].z};

        Vec3 edge1 = b - a;
        Vec3 edge2 = c - a;
        Vec3 normal = edge1.cross(edge2).normalize();
        
        Vec3 light = {0, 0, 1};
        float brightness = normal.dot(light);

        // implementing viewport transform
    
        int ax = (a.x + 1) * width/2;
        int ay = (1 - a.y) * height/2; // vertical flip
        int bx = (b.x + 1) * width/2;
        int by = (1 - b.y) * height/2;
        int cx = (c.x + 1) * width/2;
        int cy = (1 - c.y) * height/2;

        if(brightness>0){
            int col = brightness*255;
            drawFilledTriangle(f, ax, ay, a.z, bx, by, b.z, cx, cy, c.z, col, col, col);
        }
    }

    f.writePPM("../images/image10.ppm");
    
    return 0;
}