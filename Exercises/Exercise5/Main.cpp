#include <iostream>
#include <algorithm>
#include "City.h"
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

    std::vector<Individual> population = initializePopulation(populationSize, cities.size());

    for (auto& ind : population) {
        ind.calculateFitness(cities);
    }

    std::sort(population.begin(), population.end());

    std::cout << "Initial best path fitness: " << population.front().fitness << std::endl;
    std::cout << "Path: ";
    printPath(population.front().path);

    for (int gen = 0; gen < generations; ++gen) {
        std::vector<Individual> parents = selectParents(population);
        std::vector<Individual> newGeneration;

        for (size_t i = 0; i < population.size(); ++i) {
            int idx1 = rand() % parents.size();
            int idx2 = rand() % parents.size();
            Individual child = crossover(parents[idx1], parents[idx2]);

            if (static_cast<float>(rand()) / RAND_MAX < mutationChance) {
                mutate(child);
            }

            child.calculateFitness(cities);
            newGeneration.push_back(child);
        }

        population.insert(population.end(), newGeneration.begin(), newGeneration.end());
        std::sort(population.begin(), population.end());
        population.erase(population.begin() + populationSize, population.end());

        std::cout << "Generation " << gen + 1 << " Best Fitness: " << population.front().fitness << std::endl;
    }

    std::cout << "Final best path fitness: " << population.front().fitness << std::endl;
    std::cout << "Path: ";
    printPath(population.front().path);

    return 0;
}
