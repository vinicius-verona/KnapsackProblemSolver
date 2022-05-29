#include "IterativeKnapsack.hpp"

IterativeKnapsack::IterativeKnapsack(int nitems, int weight) {
    this->weight = weight;

    vector<int> items(nitems, 0);
    this->items = items;
    this->value = 0;
    this->itemsInSolution = 0;

    int** solution = new int*[nitems + 1];
    for (int i = 0; i <= nitems; i++) {
        solution[i] = new int[weight + 1];
        solution[i][0] = 0;
    }

    for (int i = 0; i <= nitems; i++) {
        for (int j = 0; j <= weight; j++) {
            if (i == 0) {
                solution[i][j] = 0;
            } else {
                solution[i][j] = -1;
            }
        }

        solution[i][0] = 0;
    }

    this->solution = solution;
}
IterativeKnapsack::~IterativeKnapsack() {
    for (int i = 0; i <= (int)this->items.size(); i++) {
        delete[] this->solution[i];
    }

    delete[] this->solution;
    this->items.clear();
}

void IterativeKnapsack::solve(const Problem* instance) {
    for (int i = 1; i <= instance->getSize(); i++) {
        for (int j = 1; j <= instance->getCapacity(); j++) {
            Item* item = instance->getItem(i - 1);

            if (item->weight > j) {
                this->solution[i][j] = this->solution[i - 1][j];
            } else {
                int notInSolution = this->solution[i - 1][j];
                int inSolution = this->solution[i - 1][j - item->weight] + item->value;

                if (notInSolution > inSolution) {
                    this->solution[i][j] = notInSolution;
                } else {
                    this->solution[i][j] = inSolution;
                }
            }
        }
    }

    this->value = this->solution[instance->getSize()][instance->getCapacity()];
}

void IterativeKnapsack::printSolution(const Problem* instance) {
    cout << "The total value for the given instance is: " << this->value << endl;
    cout << "The items in the backpack are: [ ";

    int weight = instance->getCapacity();

    for (int i = instance->getSize(); i > 0; i--) {
        if (this->solution[i][weight] != this->solution[i - 1][weight]) {
            cout << i << " ";
            this->items[i - 1] = 1;

            Item* item = instance->getItem(i - 1);
            weight -= item->weight;
        }
    }
    cout << "]" << endl;
}