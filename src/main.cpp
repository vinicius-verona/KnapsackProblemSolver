#include <iostream>

// #include "B&B/BranchBoundKnapsack.hpp"
// #include "DPI/IterativeKnapsack.hpp"
#include "DPR/RecursiveKnapsack.hpp"

using namespace std;

int main(int argc, char** argv) {
    int nItems = 0, capacity = 0;

    cin >> nItems >> capacity;

    Problem* instance = new Problem(capacity, nItems);

    for (int i = 0; i < nItems; i++) {
        int item = 0, weight = 0, price = 0;
        cin >> item >> weight >> price;
        instance->insert(new Item(item, weight, price));
    }

    RecursiveKnapsack* dpr = new RecursiveKnapsack(nItems, capacity);
    dpr->solve(instance);
    dpr->printSolution(instance);

    delete instance;

    return 0;
}