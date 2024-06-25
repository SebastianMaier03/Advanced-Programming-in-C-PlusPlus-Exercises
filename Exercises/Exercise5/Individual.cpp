#include "Individual.h"
#include <algorithm>
#include <numeric>

Individual::Individual(const std::vector<int>& path) : path(path), fitness(0.0f) {}

void Individual::calculateFitness(const std::vector<City>& cities) {
    fitness = 0.0f;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        fitness += cities[path[i]].distances[path[i+1]];
    }
    fitness += cities[path.back()].distances[path.front()]; // Return to start
}

bool Individual::operator<(const Individual& other) const {
    return fitness < other.fitness;
}
