#include <iostream>
#include <algorithm>
#include <numeric>
#include "City.h"
#include "Individual.h"
#include "GeneticAlgorithm.h"

void printPath(const std::vector<int>& path) {
    for (int city : path) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<City> cities = {
            {3, 10.5}, {-2, 8.5}, {-4, 6}, {-1, 5}, {-3.5, 4}, {-5.5, 2},
            {-1.5, 1.5}, {5, 7}, {2.5, 2.5}, {7, 2}, {4, -1}, {8.5, -1.5},
            {7, -4.5}, {4, -4.5}, {-1, -1.5}, {-1.5, -4}, {-4.5, -2.5}, {-2.5, -5.5}
    };

    for (auto& city : cities) {
        city.calculateDistances(cities);
    }

    int populationSize = 5000;
    int generations = 100;
    float mutationChance = 0.03f;

    geneticAlgorithm(cities, populationSize, generations, mutationChance);

    return 0;
}

