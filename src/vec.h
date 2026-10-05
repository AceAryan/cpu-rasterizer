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
