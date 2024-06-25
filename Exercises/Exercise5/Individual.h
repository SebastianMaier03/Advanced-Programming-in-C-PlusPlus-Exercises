#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include "City.h"

class Individual {
public:
    std::vector<int> path;
    float fitness;

    Individual(const std::vector<int>& path);
    void calculateFitness(const std::vector<City>& cities);

    bool operator<(const Individual& other) const;
};

#endif // INDIVIDUAL_H
