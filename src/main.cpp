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
    // int count = 0;
    Mat3 rot = {-1,0,0, 0,1,0, 0,0,-1}; // matrix rotation

    for(auto& it : model.faces){
        Vec3 a = rot.multiply({model.vertices[it.v1].x, model.vertices[it.v1].y, model.vertices[it.v1].z});
        Vec3 b = rot.multiply({model.vertices[it.v2].x, model.vertices[it.v2].y, model.vertices[it.v2].z});
        Vec3 c = rot.multiply({model.vertices[it.v3].x, model.vertices[it.v3].y, model.vertices[it.v3].z});

        Vec3 edge1 = b - a;
        Vec3 edge2 = c - a;
        Vec3 normal = edge1.cross(edge2).normalize();
        
        Vec3 light = {0, 0, -1};

        // float brightness = normal.dot(light);
        // int col = brightness*255;

        Vec3 na = rot.multiply(model.normals[it.n1]);
        Vec3 nb = rot.multiply(model.normals[it.n2]);
        Vec3 nc = rot.multiply(model.normals[it.n3]);

        float b1 = na.dot(light);
        float b2 = nb.dot(light);
        float b3 = nc.dot(light);

        // implementing viewport transform
    
        int ax = (a.x + 1) * width/2;
        int ay = (1 - a.y) * height/2; // vertical flip
        int bx = (b.x + 1) * width/2;
        int by = (1 - b.y) * height/2;
        int cx = (c.x + 1) * width/2;
        int cy = (1 - c.y) * height/2;

        // std::cout << b1 << " " << b2 << " " << b3 << "\n";
        // if(++count >= 10) break;  // just print first face
        
        drawFilledTriangle(f, ax, ay, a.z, bx, by, b.z, cx, cy, c.z, b1, b2, b3);
    }

    f.writePPM("../images/image12.ppm");
    
    return 0;
}