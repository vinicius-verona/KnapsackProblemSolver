#include <iostream>
#include <chrono>
#include <string.h>

#include "B&B/BranchBoundKnapsack.hpp"
#include "DPI/IterativeKnapsack.hpp"
#include "DPR/RecursiveKnapsack.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {

    bool recursive, iterative, bb;

    if (argc != 4){
        recursive = true;
        iterative = true;
        bb = true;
    }
    else{
        if (strcmp(argv[1], "R") == 0){
            recursive = true;
            iterative = false;
            bb = false;
        }
        else if(strcmp(argv[1], "I") == 0){
            recursive = false;
            iterative = true;
            bb = false;
        }
        else if(strcmp(argv[1], "B") == 0){
            recursive = false;
            iterative = false;
            bb = true;
        }
        else{
            recursive = false;
            iterative = false;
            bb = false;
        }
    }
    
    int nItems = 0, capacity = 0;

    cin >> nItems >> capacity;

    Problem* instance = new Problem(capacity, nItems);

    for (int i = 0; i < nItems; i++) {
        int item = 0, weight = 0, price = 0;
        cin >> item >> weight >> price;
        instance->insert(new Item(item, weight, price));
    }

    /*
    ██████╗ ███████╗ ██████╗██╗   ██╗██████╗ ███████╗██╗██╗   ██╗███████╗
    ██╔══██╗██╔════╝██╔════╝██║   ██║██╔══██╗██╔════╝██║██║   ██║██╔════╝
    ██████╔╝█████╗  ██║     ██║   ██║██████╔╝███████╗██║██║   ██║█████╗  
    ██╔══██╗██╔══╝  ██║     ██║   ██║██╔══██╗╚════██║██║╚██╗ ██╔╝██╔══╝  
    ██║  ██║███████╗╚██████╗╚██████╔╝██║  ██║███████║██║ ╚████╔╝ ███████╗
    ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝  ╚══════╝
    */
    if (recursive){

        cout << "\nRecursive DP Knapsack" << endl;
        RecursiveKnapsack* dpr = new RecursiveKnapsack(nItems, capacity);

        auto recursive_start = high_resolution_clock::now();
        dpr->solve(instance);
        auto recursive_end = high_resolution_clock::now();

        dpr->printSolution(instance);

        auto recursive_duration = duration_cast<microseconds>(recursive_end - recursive_start);
        cout << "Time taken by function: " << recursive_duration.count() << " microseconds" << endl;

    }

    /*
    ██╗████████╗███████╗██████╗  █████╗ ████████╗██╗██╗   ██╗███████╗
    ██║╚══██╔══╝██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██║██║   ██║██╔════╝
    ██║   ██║   █████╗  ██████╔╝███████║   ██║   ██║██║   ██║█████╗  
    ██║   ██║   ██╔══╝  ██╔══██╗██╔══██║   ██║   ██║╚██╗ ██╔╝██╔══╝  
    ██║   ██║   ███████╗██║  ██║██║  ██║   ██║   ██║ ╚████╔╝ ███████╗
    ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═══╝  ╚══════╝
    */
    if (iterative){

        cout << "\nIterative DP Knapsack" << endl;
        IterativeKnapsack* dpi = new IterativeKnapsack(nItems, capacity);

        auto iterative_start = high_resolution_clock::now();
        dpi->solve(instance);
        auto iterative_end = high_resolution_clock::now(); 

        dpi->printSolution(instance);

        auto iterative_duration = duration_cast<microseconds>(iterative_end - iterative_start);
        cout << "Time taken by function: " << iterative_duration.count() << " microseconds" << endl;

    }

    /*
    ██████╗ ██████╗  █████╗ ███╗   ██╗ ██████╗██╗  ██╗      ██████╗  ██████╗ ██╗   ██╗███╗   ██╗██████╗ 
    ██╔══██╗██╔══██╗██╔══██╗████╗  ██║██╔════╝██║  ██║      ██╔══██╗██╔═══██╗██║   ██║████╗  ██║██╔══██╗
    ██████╔╝██████╔╝███████║██╔██╗ ██║██║     ███████║█████╗██████╔╝██║   ██║██║   ██║██╔██╗ ██║██║  ██║
    ██╔══██╗██╔══██╗██╔══██║██║╚██╗██║██║     ██╔══██║╚════╝██╔══██╗██║   ██║██║   ██║██║╚██╗██║██║  ██║
    ██████╔╝██║  ██║██║  ██║██║ ╚████║╚██████╗██║  ██║      ██████╔╝╚██████╔╝╚██████╔╝██║ ╚████║██████╔╝
    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝      ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚═════╝ 
    */
    if (bb){

        cout << "\nBranch and Bound DP Knapsack" << endl;
        BranchBoundKnapsack* branchBound = new BranchBoundKnapsack(nItems, capacity);

        auto bb_start = high_resolution_clock::now();
        branchBound->solve(instance);
        auto bb_end = high_resolution_clock::now(); 

        branchBound->printSolution(instance);

        auto bb_duration = duration_cast<microseconds>(bb_end - bb_start);
        cout << "Time taken by function: " << bb_duration.count() << " microseconds" << endl;

    }

    delete instance;

    return 0;
}