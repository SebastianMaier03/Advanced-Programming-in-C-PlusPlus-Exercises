#include "Int2.h"

int2::int2() : x(0), y(0) {}

int2::int2(int _x, int _y) : x(_x), y(_y) {}

#include <iostream>

int main() {
    int2 point1;
    std::cout << point1.x << ", " << point1.y << std::endl;

    int2 point2(5, 8);
    std::cout <<  point2.x << ", "<< point2.y << std::endl;

    return 0;
}