#include "BranchBoundKnapsack.hpp"

BranchBoundKnapsack::BranchBoundKnapsack(int nitems, int weight) {
    this->weight = weight;

    vector<int> items(nitems, -1);
    this->items = items;
    this->bestAssignment = items;
    this->value = 0;
    this->bestValue = 0;

}
BranchBoundKnapsack::~BranchBoundKnapsack() {
    this->items.clear();
    this->bestAssignment.clear();
    this->valueProportion.clear();
}

void BranchBoundKnapsack::initialSolution(const Problem* instance) {

    vector<pair<double, int>> proportion;
    for (int i = 1; i <= instance->getSize(); i++){
        Item* item = instance->getItem(i - 1);
        pair<double, int> x;
        x.first = (double)item->value / (double)item->weight;
        x.second = i - 1;

        proportion.push_back(x);
    }

    this->valueProportion = proportion;
    sort(proportion.begin(), proportion.end(), greater<pair<double, int>>());
    
    int capacity = instance->getCapacity();

    for (int i = 1; i <= (int) proportion.size(); i++){
        int position = proportion[i - 1].second;
        Item* item = instance->getItem(position);
        
        if (capacity - item->weight >= 0){
            this->bestAssignment[position] = 1;
            this->weight += item->weight;
            this->bestValue += item->value;
            capacity -= item->weight;

        } else{
            this->bestAssignment[position] = 0;
        }
    }

}

bool BranchBoundKnapsack::isComplete(vector<int> items) {
    
    for (int i : items) {
        if (i == -1) return false;
    }

    return true;

}

bool BranchBoundKnapsack::isConsistent(const Problem* instance, vector<int> items) {
    
    int totalWeight = 0;
    int counter = 0;
    
    for (int i : items) {
        if (i == 1) {
            totalWeight += instance->getItem(counter)->weight;

            if (totalWeight > instance->getCapacity()) {
                return false;
            }
        }

        counter++;
    }

    return true;

}

bool BranchBoundKnapsack::isPromissing(const Problem* instance, vector<int> items, int idx, int value, int weight) {

    double nValue = value;
    
    if (items[idx]) {
        Item* item = instance->getItem(idx);
        weight += item->weight;
        nValue += item->value;
    }

    vector<pair<double, int>> proportion = this->valueProportion;
    sort(proportion.begin() + idx + 1, proportion.end(), greater<pair<double, int>>());

    vector<int> nitems = items;

    for (auto it = proportion.begin() + idx + 1; it != proportion.end(); ++it){
        Item* item = instance->getItem(it->second);
        if (weight + item->weight <= instance->getCapacity()){
            weight += item->weight;
            nValue += item->value;
            nitems[it->second] = 1;
        
        } else{
            int remainder = instance->getCapacity() - weight;
            weight += remainder;
            nValue += (remainder * it->first); 
            break;
        }
    }

    if (this->bestValue < nValue) return true;
    else return false;

}

void BranchBoundKnapsack::solve(const Problem* instance) {

    this->initialSolution(instance);

    if (!(this->isComplete(this->bestAssignment) && this->isConsistent(instance, this->bestAssignment))){
        cout << "Solução errada, revise o codigo!!!" << endl;
    }

    this->weight = 0;
    this->_solve(instance, this->items, 0, this->value, this->weight);

}

void BranchBoundKnapsack::_solve(const Problem* instance, vector<int> items, int item, int value, int weight) {

    if (this->isComplete(items)){

        this->bestAssignment = items;
        this->bestValue = value;

    } else{
        items[item] = 0;
        if (this->isConsistent(instance, items) && this->isPromissing(instance, items, item, value, weight)){
            this->_solve(instance, items, item + 1, value, weight);
        }

        items[item] = 1;
        if (this->isConsistent(instance, items) && this->isPromissing(instance, items, item, value, weight)){
            this->_solve(instance, items, item + 1, value + instance->getItem(item)->value, weight + instance->getItem(item)->weight);
        }

        items[item] = -1;
    }

}


void BranchBoundKnapsack::printSolution(const Problem* instance) {
    cout << "The total value for the given instance is: " << this->bestValue << endl;
    cout << "The items in the backpack are: [ ";

    for (int i = this->bestAssignment.size(); i > 0; i--){
        if (this->bestAssignment[i - 1] == 1) {
            cout << i << " ";
        }
    }
    cout << "]" << endl;

}