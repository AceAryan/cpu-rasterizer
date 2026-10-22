    #pragma once

    #include <fstream>
    #include <vector>
    #include <sstream>
    #include "vec.h"

    struct Vertex{
        float x;
        float y;
        float z;
    };

    struct Face{
        int v1, v2, v3;
        int n1, n2, n3;
    };

    struct Model{
        std::vector<Vertex> vertices;
        std::vector<Vec3> normals;
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
            else if(token == "vn"){
                float x, y, z;
                ss >> x >> y >> z;
                model.normals.push_back({x,y,z});
            }
            else if(token == "f"){
                // f has format of v / vt / vn
                std::string v1, v2, v3;
                ss >> v1 >> v2 >> v3;

                size_t first = v1.find('/');
                size_t second = v1.find('/', first + 1);
                int i1 = std::stoi(v1.substr(0, first));
                int n1 = std::stoi(v1.substr(second + 1));

                first = v2.find('/');
                second = v2.find('/', first + 1);
                int i2 = std::stoi(v2.substr(0, first));
                int n2 = std::stoi(v2.substr(second + 1));

                first = v3.find('/');
                second = v3.find('/', first + 1);
                int i3 = std::stoi(v3.substr(0, first));
                int n3 = std::stoi(v3.substr(second + 1));

                model.faces.push_back({i1-1, i2-1, i3-1, n1-1, n2-1, n3-1});
            }
        }

        return model;
    }