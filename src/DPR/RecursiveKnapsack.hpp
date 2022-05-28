#ifndef RECURSIVE_KNAPSACK_HPP
#define RECURSIVE_KNAPSACK_HPP

#include "../Problem/Problem.hpp"

using namespace std;

class RecursiveKnapsack {
   private:
    int weight;         // Backpack current weight
    int value;          // Backpack monetary value
    vector<int> items;  // Binary array representing each item. 1  means it is part of the solution.
                        // The position means the item index.

    int** memo;  // Memoization matrix

   public:
    RecursiveKnapsack(int nitems, int weight);
    ~RecursiveKnapsack();

    /**
     * For a given instance, solve the Knapsack problem recursively using memoization.
     * @param instance is the instance data.
     */
    void solve(const Problem* instance);

    /**
     * For a given instance, display the solution for the Knapsack problem.
     * @param instance is the instance data.
     */
    void printSolution(const Problem* instance);

   private:
    int _solve(const Problem* instance, int nItems, int currentCapacity);
};

#endif