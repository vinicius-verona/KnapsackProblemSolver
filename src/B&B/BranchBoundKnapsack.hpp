#ifndef BRANCH_BOUND_KNAPSACK_HPP
#define BRANCH_BOUND_KNAPSACK_HPP

#include <algorithm>

#include "../Problem/Problem.hpp"

using namespace std;

class BranchBoundKnapsack {
   private:
    int weight;                                 // Backpack current weight
    int value;                                  // Backpack monetary value
    int bestValue;                              // Best solution value
    vector<pair<double, int>> valueProportion;  // Proportion
    vector<int> bestAssignment;  // Binary array representing the best assignment of each item. 1  means it is part of
                                 // the solution. -1 means undefined and 0 not in solution
    vector<int> items;  // Binary array representing each item. 1  means it is part of the solution. -1 means undefined
                        // and 0 not in solution The position means the item index.

   public:
    BranchBoundKnapsack(int nitems, int weight);
    ~BranchBoundKnapsack();

    /**
     * For a given instance, solve the Knapsack problem iteratively using a solution table.
     * @param instance is the instance data.
     */
    void solve(const Problem* instance);

    /**
     * For a given instance, create an initial solution.
     * @param instance is the instance data.
     */
    void initialSolution(const Problem* instance);

    /**
     * Check if the current solution is complete.
     * @return true if it is complete.
     */
    bool isComplete(vector<int> items);

    /**
     * Check if the current solution breaks any constraint.
     * @return true if it is complete.
     */
    bool isConsistent(const Problem* instance, vector<int> items);

    /**
     * Check if the solution is promissing by predicting it.
     * @return true if it is complete.
     */
    bool isPromissing(const Problem* instance, vector<int> items, int idx, int value, int weight);

    /**
     * For a given instance, display the solution for the Knapsack problem.
     * @param instance is the instance data.
     */
    void printSolution(const Problem* instance);

   private:
    void _solve(const Problem* instance, vector<int> items, int item, int value, int weight);
};

#endif