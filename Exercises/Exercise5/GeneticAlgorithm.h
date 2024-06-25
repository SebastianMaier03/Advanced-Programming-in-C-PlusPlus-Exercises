#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include "Individual.h"

std::vector<Individual> initializePopulation(int populationSize, int numCities);
std::vector<Individual> selectParents(const std::vector<Individual>& population);
Individual crossover(const Individual& parent1, const Individual& parent2);
void mutate(Individual& individual);
void geneticAlgorithm(const std::vector<City>& cities, int populationSize, int generations, float mutationChance);

#endif // GENETICALGORITHM_H
