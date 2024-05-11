#include "Int2.h"

int2::int2() : x(0), y(0) {}

int2::int2(int _x, int _y) : x(_x), y(_y) {}

int2 int2::operator+(const int2& other) const {
    return int2(x + other.x, y + other.y);
}

int2 int2::operator-(const int2& other) const {
    return int2(x - other.x, y - other.y);
}

int2 int2::operator*(const int2& other) const {
    return int2(x * other.x, y * other.y);
}

int2 int2::operator/(const int2& other) const {
    return int2(x / other.x, y / other.y);
}

int2& int2::operator+=(const int2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

int2& int2::operator-=(const int2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

int2& int2::operator*=(const int2& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

int2& int2::operator/=(const int2& other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

int2 int2::operator*(int scalar) const {
    return int2(x * scalar, y * scalar);
}

int2& int2::operator*=(int scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

bool int2::operator==(const int2& other) const {
    return x == other.x && y == other.y;
}

bool int2::operator!=(const int2& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const int2& vec) {
    return os << "(" << vec.x << "|" << vec.y << ")";
}
