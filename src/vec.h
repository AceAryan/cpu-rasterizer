#pragma once
#include <cmath>

struct Vec3{
    float x, y, z;

    Vec3 operator-(Vec3 other){
        return {x-other.x, y-other.y, z-other.z};
    }

    Vec3 cross(Vec3 other){
        return {y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x};
    }

    float dot(Vec3 other){
        return x*other.x + y*other.y + z*other.z;
    }

    Vec3 normalize(){
        float denom = sqrt(x*x + y*y + z*z);
        return {x/denom, y/denom, z/denom};
    }
};

struct Mat3{
    float matrix[3][3];

    Vec3 multiply(Vec3 v){
        return Vec3{
            matrix[0][0]*v.x + matrix[0][1]*v.y + matrix[0][2]*v.z,
            matrix[1][0]*v.x + matrix[1][1]*v.y + matrix[1][2]*v.z, 
            matrix[2][0]*v.x + matrix[2][1]*v.y + matrix[2][2]*v.z
        };
    }
};
