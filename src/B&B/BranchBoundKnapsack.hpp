#ifndef BRANCH_BOUND_KNAPSACK_HPP
#define BRANCH_BOUND_KNAPSACK_HPP

#include <vector>

#include "../items/items.hpp"

using namespace std;

class BranchBoundKnapsack {
   private:
    int capacity;       // Backpack total capacity
    int weight;         // Backpack current weight
    int value;          // Backpack monetary value
    vector<int> items;  // Items in backpack

   public:
    BranchBoundKnapsack();
    ~BranchBoundKnapsack();
};

#endif