#pragma once

#include <fstream>
#include <vector>
#include <sstream>

struct Vertex{
    float x;
    float y;
    float z;
};

struct Face{
    int v1, v2, v3;
};

struct Model{
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};


Model objLoader(std::string filename){
    Model model;
    std::ifstream file(filename);
    std::string line;
    while(std::getline(file, line)){
        std::istringstream ss(line);
        std::string token;
        ss >> token;
        if(token == "v"){
            float x, y, z;
            ss >> x >> y >> z;
            model.vertices.push_back({x,y,z});
        }
        else if(token == "f"){
            std::string v1, v2, v3;
            ss >> v1 >> v2 >> v3;
            int i1 = std::stoi(v1.substr(0, v1.find('/')));
            int i2 = std::stoi(v2.substr(0, v2.find('/')));
            int i3 = std::stoi(v3.substr(0, v3.find('/')));
            model.faces.push_back({i1-1, i2-1, i3-1});
        }
    }

    return model;
}