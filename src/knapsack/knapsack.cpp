#include <iostream>
#include <algorithm>
#include <vector>

#include "knapsack/knapsack.hpp"

void knapsackInstance::print_stats() {
    std::cout << "Knapsack problem with " << num_items << " items" << std::endl;
    std::cout << "Total capacity: " << capacity << std::endl;
    if (num_items > 0) {
        std::cout << "Item stats:" << std::endl;
        auto pw = std::minmax_element(weights.begin(), weights.end());
        std::cout << "Weights: [" << *pw.first << ", " << *pw.second << "]" << std::endl;
        auto pv = std::minmax_element(values.begin(), values.end());
        std::cout << "Values : [" << *pv.first << ", " << *pv.second << "]" << std::endl;
    } else {
        std::cout << "(empty knapsack)" << std::endl;
    }
};

void knapsackInstance::solve() {
    std::cout << "Solving knapsack instance" << std::endl;
    print_stats();
};
