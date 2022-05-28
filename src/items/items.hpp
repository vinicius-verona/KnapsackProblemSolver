#ifndef ITEMS_HPP
#define ITEMS_HPP

using namespace std;

class Item {
   public:
    const int id;      // Item's identifier
    const int weight;  // Item's weight
    const int value;   // Item's monetary value
    Item(int id, int weight, int value);
    ~Item();
};

#endif