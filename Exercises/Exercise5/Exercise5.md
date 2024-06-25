# Exercise 5

## Travelling Salesman Problem

The TSP is a very popular maths problem.
The idea is that a travelling salesman starts at a certain city and travels to a number of other cities, before returning to the starting city. He visits each town exactly once. The goal is to find the shortest possible path the salesman can take. This problem cannot be solved by some clever algorithm, the only approach that works is to explore by brute-force every combination of cities to find the shortest overall path. This leads however to an insane time complexity that is !N. So if there are 10 cities to explore, then there are `10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2` possibilities. If we have 50 cities this is so much computational effort, that we simply cant do it. However, even though we cannot solve the problem, we can still find a good approximation using heuristic methods, e.g. a genetic algorithm.

## Step 1: Cities

Before we look at that however, we will first take a look at how to represent the cities and their distances to each other in code.
For this exercise you will get the positions of the cities as 2D coordinates:

```
City 1: (3, 10.5)
City 2: (-2,8.5)
City 3: (-4,6)
City 4: (-1,5)
City 5: (-3.5,4)
City 6: (-5.5,2)
City 7: (-1.5,1.5)
City 8: (5,7)
City 9: (2.5,2.5)
City 10: (7,2)
City 11: (4,-1)
City 12: (8.5, -1.5)
City 13: (7, -4.5)
City 14: (4, -4.5)
City 15: (-1, -1.5)
City 16: (-1.5,-4)
City 17: (-4.5, -2.5)
City 18: (-2.5, -5.5)
```

Essentially we just need a way to store how far each city is from every other city. Since we have our cities as 2D coordinates, this is relatively easy to do. We can just create a class `City` and store in it its coordinates, as well as a `vector<float> distances` storing the distances to every other city. To calculate these distances, we can put our cities into a `vector<City>` and each city can calculate its distances to every other city using that vector and store the results in `distances`. The distance between two points is simply `sqrt(xDistance * xDistance + yDistance * yDistance)`, the pythagorean theorem.

In the TSP each of the these cities has to be visited once. For this exercise we excluded the city you start and return to from the list of cities. Instead each of the cities coordinates are relative to that starting city, so we basically start from (0,0) and return to (0,0) at the end of our travel.

## Genetic Algorithm

Since this problem can not be solved without brute force our best approach is to settle for a solution that comes close to the best possible solution.

For this we can use a genetic algorithm. Genetic algorithms essentially work on the concept of natural selection. In the nature, creatures that are more capable of survival, or have a high "fitness", have a higher chance to find a partner and pass on their genes to offspring. Thus over many generations, the population of creatures becomes more capable of survival, since the creatures that are not capable of survival die out and the ones that are fit live on. Eventually the genetic pool stagnates and most creatures are made up of very similar genes. To overcome this stagnation in rare cases Mutations occur, which alter a creature significantly, potentially evolving useful traits in the process.

This might seem very abstract and unrelated, but these concepts translate very well to computer science. If we have a problem that cannot be solved analytically, we can apply this technique to heuristically search for a solution.

The implementation varies greatly depending on the problem, but in general the structure of such a "genetic algorithm" is always similar:

- Step 1: Initialize a population at random. Each individual of the population represents a possible solution to the problem
- Step 2: Evaluate how good each random solution is.
- Step 3: Repeat in a loop:
  - 3.1: Select out of the population some individuals based on their fitness
  - 3.2: Generate new individuals using the selected ones. These new individuals needs to somehow involve parts of the selected individuals
  - 3.3: Apply random mutations to the the new individuals.
  - 3.4: Reavaluate all current solutions and remove those that are bad.

Here is pesudo code illustrating the entire algorithm:

```
populationSize = 50
crossAmount = 8
generations = 200
mutationChance = 0.03f

population = initialize()
calculateFitness(population)

sort population

for x generations:
    parents = selectParents(population)
    children = crossover(parents)
    mutate(children)
    calculateFitness(children)
    population.add(children)
    sort(population)
    remove_bad(population)
```

Since this is still a very complex topic and for each of the components there are many nuances and design choices that ultimately determine how well the algorithm works, here is a description of each component of the algorithm:

## The Individuals

Each individual in the population represents one possible solution to the TSP, so we have to think of what a valid solution to our problem is.
A valid solution of the TSP is one, in which each city is visited exactly once. (We can exclude the city in which we start and in which we end, because this always stays the same, regardless of our solution) Let's say our cities are stored in an array, then a valid solution would be an array of integers, each representing one of our cities in the array in a random order. Each index in the cities array needs to be present exactly once, since each city in the TSP is only allowed to be visited once!

`Cities array with size 10`

`Possible Solution: 7 6 5 1 2 0 4 9 3 8 //each number represents an index into the cities array!`

`Invalid Solution: 7 6 5 1 2 2 4 9 3 8 //index 2 is present twice, which is not allowed!`

## Fitness Function

Now that we can represent a possible solution as an array of integers, we need a way to evaluate the fitness of that individual. This is fairly straight forward. In the TSP we want to find the path that results in the smallest distance travelled. Therefore we can just calculate how long the distance between each of the entries in our `solution` array is and sum them up. We know how far apart each city is from each other. Be careful however: In the TSP we start at some city and then need to return to it at the end. Since we defined that startcity as the origin of our coordinate system, we need to find the distance to the origin of the first and last entry of our `solution` array and then add them to our calculated sum.

## Crossover and Mutation

Next we need crossover and mutation functions. For the crossover we want to take two individuals and using their solutions create a new individual. In this context we will call the two individuals used for the crossover "Parents" and the resulting individual "Child".

Consider this example:

`Parent 1: 7 6 5 1 2 0 4 9 3 8`

`Parent 2: 1 0 4 2 9 8 7 5 6 3`

One idea would be to take the first half of Parent 1 and the second half from Parent 2. This does not work however, since the resulting child:

`Child: 7 6 5 1 2 8 7 5 6 3`

visits some cities twice and some not at all. Therefore we need a more sophisticated solution:

- Choose a random integer `r` from 0 to `numberOfCities - 1`. (0 - 9 in this case).
- From 0 to `r` all values are taken from Parent1.
- From `r` to `numberOfCities - 1` all values are taken from Parent2.

Example:

`r = 4`

`Child:  7 6 5 1 2 ? ? ? ? ? //values at indizes 0 - 4 are taken from Parent 1`

`Child:  7 6 5 1 2 8 ? ? ? ? //8 was taken from Parent 2`

The next value would also be taken from parent 2, but can't because the 7 is already present in the child. Therefore we skip it, until we find a value that is not yet present. The 5 is the next value but will also be skipped, as well as the 6. Finally, the 3 is not yet present:

`Child:  7 6 5 1 2 8 3 ? ? ? //3 was taken from Parent 2`

We have reached the end of Parent 2, but we still need three values in the child. Therefore we will cycle to the beginning of parent 2 and continue from there. The first number in Parent 2 is 1, which is already present, thereafter comes 0, which is not present yet:

`Child:  7 6 5 1 2 8 3 0 ? ? //0 was taken from Parent 2`

The next digit is 4, which is also not present yet:

`Child:  7 6 5 1 2 8 3 0 4 ? //0 was taken from Parent 2`

Next up is 2, which will be skipped, since it is already present and finally 9, which completed our child:

`Child:  7 6 5 1 2 8 3 0 4 9 //0 was taken from Parent 2`

---

There are many different approaches to the crossover function, but we will use this one for now.

For every child there is also a small chance that it is mutated.

The mutation function we will keep rather simple: 
We will choose two indizes in our child at random and swap the values at these indizes:

`Idx 1: 3, Idx 2: 6`

`Child after mutation:  7 6 5 3 2 8 1 0 4 9`

## Selection

Every generation we need to select a few individuals for crossover. This selection cannot happen arbitrary, since we want to model natural selection. Therefore fit individuals should be selected for crossover. Just choosing the most fit ones is also a bad solution however, since then every generation the same individuals will crossover, and the children will be very similar, resulting in quick stagnation in genetic diversity and suptoptimal results.

Therefore a good way to do this is by using weighted chances. In our case it makes a lot of sense to choose the individual based on how fit they are. Our fitness score at the moment directly represents the summed distance the salesman has to travel, which means for us a low fitness score (so a smaller distance) means that the solution is better. So for weighted chances to work we can not use the fitness directly as weights, but rather the inverse. `(1 / fitness)`

- Create a copy of the population. This is useful, since we do not want to select the same parent multiple times for crossover.

- While there are still parents left to be chosen:
  - Sum up the inverse fitnesses of the copied population.
  - Create a random number `r` from 0 to that calculated sum.
  - Loop through the copied population in reverse.
    - In every iteration first decrease the sum by the inverse fitness of the current individual.
    - Check, if `r` is smallert han the inverse fitness of the current individual
    - If so, the current individual will be chosen for crossover and the loop terminates. The chosen individual will also be removed from the copied population, so it cannot be picked again.
    - If not, decrease `r` by the inverse fitness of the current individual

Pseudocode for weighted random numbers can also be found here for reference:

https://stackoverflow.com/questions/1761626/weighted-random-numbers

## Sorting our population and removing the worst members

At the end of each population we want to remove the worst individuals and reduce the population size back to what it was before the crossover. The following code does exactly that.

```cpp
#include <algorithm>

constexpr int populationSize = 20;

sort(population.begin(), population.end());
population.erase(next(population.begin(), populationSize), population.end());
```

However for the `sort` function to work the class that represents our individual needs to override the `<` operator, so it can be compared to other references to itself:
```cpp
//should return true, if other has a worse fitness score than this.
bool operator <(const Class& other);
```

# Implementation Tips

This is a rather big exercise, with a lot of things you probably are not familiar with.
Therefore it is important to be strategic in how you approach this. The best way to solve such problems is usually to subdivide them into their parts. In the exercise description we did exactly that, by dividing the algorithm into its components. You dont have to stop there though, you can subdivide the problem further until the problems at hand have a size you are comfortable with.
Then once you have the individual parts and are comfortable that they work (debug them often and carefully!), you can start putting them together. If something breaks immediately stop and analyze why it broke!
Also, the exercise will run for multiple weeks, so make sure to start early and ask questions if something is unclear!

As you can see in the pseudo code at the top of the exercise, there are a few parameters, such as the population size and the amount of generations to run the algorithm for. These greatly determine how well your algorithm will work. Feel free to experiment with them, but the values given in the pesudo code should yield good results.

How do you know if your algorithm works? This is tricky, since we do not know what the optimal solution is. In our implementation the algorithm got to a fitness score of around 80 over the runtime of the algorithm, so take that as a benchmark.

Also since the TSP and Genetic Algorithms in general might be new to you, do some further reading to familiarize yourself with the domains:
- https://www.geeksforgeeks.org/genetic-algorithms/
- https://de.wikipedia.org/wiki/Problem_des_Handlungsreisenden
- 
# Submission

Submission is due until 30.06.2024 23:59. Upload an .exe which shows the algorithm working and upload a .zip with the source files!