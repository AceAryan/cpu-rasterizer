#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <vector>
#include <fstream>
#include <cfloat>

class Framebuffer{

    int width, height;
    std::vector<int> array;
    std::vector<float> zbuffer;

    public:
        Framebuffer(int w, int h): width(w), height(h), array(w*h*3), zbuffer(w*h, FLT_MAX) {};

        void setPixel(int x, int y, float z, int r, int g, int b){
            if(z < zbuffer[y*width + x]){
                array[(y*width + x)*3] = r;
                array[(y*width + x)*3 + 1] = g;
                array[(y*width + x)*3 + 2] = b;

                zbuffer[y*width + x] = z;
            }
        }

        void writePPM(std::string filename){
            std::ofstream file(filename);
            file << "P3\n";
            file << width << " " << height << "\n";
            file << "255\n";
            
            for(int y=0; y<height; y++){
                for(int x=0; x<width; x++){
                    file << array[(y*width + x)*3] << " " << array[(y*width + x)*3 + 1] << " " << array[(y*width + x)*3 + 2] << "\n";
                }
            } 
        }

        void clearBackground(int r, int g, int b){
            for(int y=0; y<height; y++){
                for(int x=0; x<width; x++){
                    array[(y*width + x)*3] = r;
                    array[(y*width + x)*3 + 1] = g;
                    array[(y*width + x)*3 + 2] = b;
                }
            }
        }
};

#endif