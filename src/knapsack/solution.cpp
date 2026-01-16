#include <iostream>
#include <vector>

#include "knapsack/solution.hpp"

void knapsackSolution::print_solution() {
    std::cout << "Knapsack solution with value " << value << " and weight " << weight << std::endl;
    for (size_t i=0; i<x.size(); i++) {
        if (x[i] > 0) {
            std::cout << "Item #" << i << ": " << x[i] << std::endl;
        };
    };
};