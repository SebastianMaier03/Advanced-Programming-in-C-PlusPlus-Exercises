#ifndef CITY_H
#define CITY_H

#include <vector>

class City {
public:
    float x;
    float y;
    std::vector<float> distances;

    City(float x, float y);
    void calculateDistances(const std::vector<City>& cities);
};

#endif // CITY_H
