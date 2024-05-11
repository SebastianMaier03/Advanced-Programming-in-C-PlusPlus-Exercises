#pragma once
#include <iostream>

struct int2
{
    int x;
    int y;

    int2();
    int2(int _x, int _y);

    int2 operator+(const int2& other) const;
    int2 operator-(const int2& other) const;
    int2 operator*(const int2& other) const;
    int2 operator/(const int2& other) const;
    int2& operator+=(const int2& other);
    int2& operator-=(const int2& other);
    int2& operator*=(const int2& other);
    int2& operator/=(const int2& other);
    int2 operator*(int scalar) const;
    int2& operator*=(int scalar);
    bool operator==(const int2& other) const;
    bool operator!=(const int2& other) const;
    friend std::ostream& operator<<(std::ostream& os, const int2& vec);
};

