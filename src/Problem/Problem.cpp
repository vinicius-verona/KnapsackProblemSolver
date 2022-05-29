#include "./Problem.hpp"

Item::Item(int id, int weight, int value) : id(id), weight(weight), value(value) {}
Item::~Item() {}

Problem::Problem(int capacity, int nItems) {
    this->capacity = capacity;
    this->nItems = nItems;

    vector<Item *> items(0);
    this->items = items;
}
Problem::~Problem() {
    for (Item *i : this->items) {
        delete i;
    }

    this->items.clear();
}

void Problem::insert(Item *item) { this->items.push_back(item); }

Item *Problem::getItem(int idx) const { return this->items[idx]; }

int Problem::getCapacity() const { return this->capacity; }

int Problem::getSize() const { return this->nItems; }