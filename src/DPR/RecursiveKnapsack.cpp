#include "RecursiveKnapsack.hpp"

RecursiveKnapsack::RecursiveKnapsack(int nitems, int weight) {
    this->weight = weight;

    vector<int> items(nitems, 0);
    this->items = items;
    this->value = 0;
    this->itemsInSolution = 0;

    int** memo = new int*[nitems + 1];
    for (int i = 0; i <= nitems; i++) {
        memo[i] = new int[weight + 1];
        memo[i][0] = 0;
    }

    for (int i = 0; i <= nitems; i++) {
        for (int j = 0; j <= weight; j++) {
            if (i == 0) {
                memo[i][j] = 0;
            } else {
                memo[i][j] = -1;
            }
        }

        memo[i][0] = 0;
    }

    this->memo = memo;
}
RecursiveKnapsack::~RecursiveKnapsack() {
    for (int i = 0; i <= (int)this->items.size(); i++) {
        delete[] this->memo[i];
    }

    delete[] this->memo;
    this->items.clear();
}

void RecursiveKnapsack::solve(const Problem* instance) {
    this->value = this->_solve(instance, instance->getSize(), instance->getCapacity());
}

int RecursiveKnapsack::_solve(const Problem* instance, int nItems, int capacity) {
    if (capacity == 0 || nItems == 0) return 0;

    if (this->memo[nItems][capacity] == -1) {
        Item* item = instance->getItem(nItems - 1);

        if (item->weight > capacity) {
            this->memo[nItems][capacity] = this->_solve(instance, nItems - 1, capacity);
        } else {
            int notInSolution = this->_solve(instance, nItems - 1, capacity);
            int inSolution = this->_solve(instance, nItems - 1, capacity - item->weight) + item->value;

            if (notInSolution > inSolution) {
                this->memo[nItems][capacity] = notInSolution;
            } else {
                this->memo[nItems][capacity] = inSolution;
            }
        }
    }

    return this->memo[nItems][capacity];
}

void RecursiveKnapsack::printSolution(const Problem* instance) {
    cout << "The total value for the given instance is: " << this->value << endl;
    cout << "The items in the backpack are: [ ";

    int weight = instance->getCapacity();

    for (int i = instance->getSize(); i > 0; i--) {
        if (this->memo[i][weight] != this->memo[i - 1][weight]) {
            cout << i << " ";
            this->items[i - 1] = 1;

            Item* item = instance->getItem(i - 1);
            weight -= item->weight;
        }
    }
    cout << "]" << endl;
}