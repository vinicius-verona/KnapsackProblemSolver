#include "./Problem.hpp"

Item::Item(int id, int weight, int value) : id(id), weight(weight), value(value) {}
Item::~Item() {}

Problem::Problem(int capacity, vector<Item *> *items = NULL) : capacity(capacity), items(items) {}
Problem::~Problem() {
    for (auto i : this->items) {
        delete i;
    }

    delete items;
}

void Problem::insert(Item *item) { this->items->push_back(item); }

Item *Problem::getItem(int idx) const { return this->items[idx]; }

int Problem::getCapacity() const { return this->capacity; }

int Problem::getSize() const { return this->nItems; }