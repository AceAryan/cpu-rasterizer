#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <vector>
#include <fstream>

class Framebuffer{

    int width, height;
    std::vector<int> array;

    public:
        Framebuffer(int w, int h): width(w), height(h), array(w*h*3) {};

        void setPixel(int x, int y, int r, int g, int b){
            array[(y*width + x)*3] = r;
            array[(y*width + x)*3 + 1] = g;
            array[(y*width + x)*3 + 2] = b;
        }

        void writePPM(std::string filename){
            std::ofstream file(filename);
            file << "P3\n";
            file << width << " " << height << "\n";
            file << "255\n";
            
            for(int x=0; x<width; x++){
                for(int y=0; y<height; y++){
                    file << array[(y*width + x)*3] << " " << array[(y*width + x)*3 + 1] << " " << array[(y*width + x)*3 + 2] << "\n";
                }
            } 
        }
};

#endif