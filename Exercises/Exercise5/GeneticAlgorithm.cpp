#include "GeneticAlgorithm.h"
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>

std::vector<Individual> initializePopulation(int populationSize, int numCities) {
    std::vector<Individual> population;
    std::vector<int> path(numCities);
    std::iota(path.begin(), path.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = 0; i < populationSize; ++i) {
        std::shuffle(path.begin(), path.end(), g);
        population.emplace_back(path);
    }

    return population;
}

std::vector<Individual> selectParents(const std::vector<Individual>& population) {
    std::vector<Individual> parents;
    float fitnessSum = std::accumulate(population.begin(), population.end(), 0.0f,
                                       [](float sum, const Individual& ind) { return sum + (1.0f / ind.fitness); });

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<> dist(0.0, fitnessSum);

    for (size_t i = 0; i < population.size(); ++i) {
        float r = dist(g);
        float partialSum = 0.0f;

        for (const auto& ind : population) {
            partialSum += (1.0f / ind.fitness);
            if (partialSum >= r) {
                parents.push_back(ind);
                break;
            }
        }
    }

    return parents;
}

Individual crossover(const Individual& parent1, const Individual& parent2) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, parent1.path.size() - 1);

    int r = dist(g);
    std::vector<int> childPath = parent1.path;

    size_t currentIdx = r + 1;
    for (int city : parent2.path) {
        if (std::find(childPath.begin(), childPath.begin() + r + 1, city) == childPath.begin() + r + 1) {
            childPath[currentIdx] = city;
            currentIdx = (currentIdx + 1) % childPath.size();
        }
    }

    return Individual(childPath);
}

void mutate(Individual& individual) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, individual.path.size() - 1);

    int idx1 = dist(g);
    int idx2 = dist(g);

    std::swap(individual.path[idx1], individual.path[idx2]);
}

void geneticAlgorithm(const std::vector<City>& cities, int populationSize, int generations, float mutationChance) {
    std::vector<Individual> population = initializePopulation(populationSize, cities.size());

    for (auto& ind : population) {
        ind.calculateFitness(cities);
    }

    std::sort(population.begin(), population.end());

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
    for (int city : population.front().path) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}
