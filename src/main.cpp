#include <iostream>

int main(){
    int width = 800;
    int height = 600;

    // usign \n instead of std::endl because endl flushes buffer every call making it slower

    std::cout << "P3\n";
    std::cout << width << " " << height << "\n";
    std::cout << "255\n";

    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            std::cout << "255 100 0\n";
        }
    }

    return 0;
}