#include "City.h"
#include <cmath>

City::City(float x, float y) : x(x), y(y) {}

void City::calculateDistances(const std::vector<City>& cities) {
    distances.resize(cities.size());
    for (size_t i = 0; i < cities.size(); ++i) {
        float dx = cities[i].x - x;
        float dy = cities[i].y - y;
        distances[i] = std::sqrt(dx * dx + dy * dy);
    }
}
