#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <iostream>
#include <vector>
using namespace std;

class Item {
   public:
    const int id;      // Item's identifier
    const int weight;  // Item's weight
    const int value;   // Item's monetary value
    Item(int id, int weight, int value);
    ~Item();
};

class Problem {
   private:
    int capacity;
    int nItems;
    vector<Item *> *items;

   public:
    Problem(int capacity, int nItems, vector<Item *> *items = NULL);
    ~Problem();

    /**
     * Insert an item into the items vector;
     */
    void insert(Item *item);

    /**
     * Get an item from the items vector;
     */
    Item *getItem(int idx) const;

    /**
     * Get the full capacity of the backpack;
     */
    int getCapacity() const;

    /**
     * Get the number of items for the instance;
     */
    int getSize() const;
};

#endif