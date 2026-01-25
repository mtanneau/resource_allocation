#include <iostream>
#include <algorithm>
#include <numeric>   // for std::iota
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

void knapsackInstance::sort_items() {
    if (is_sorted) {return;}

    sort_perm.resize(num_items);
    std::iota(sort_perm.begin(), sort_perm.end(), 0);
    std::sort(sort_perm.begin(), sort_perm.end(),
        [&] (size_t i, size_t j) {
            return values[i] * weights[j] > values[j] * weights[i];
        }
    );
    is_sorted = true;
};

dantzigSolution knapsackInstance::solve_dantzig() {
    sort_items();

    double w = 0.0;  // current weight of solution
    double v = 0.0;  // current value of solution
    size_t critical_item = -1;
    double dw_bound = 0.0;
    
    // Extract data from KP instance, and compute items' ratio
    for (size_t i=0; i < num_items; i++) {
        auto j = sort_perm[i];
        auto vj = values[j];
        auto wj = weights[j];

        // do we still have enough capacity?
        if (w + wj <= capacity) {
            // We still have enough space, add this item
            // Add this item to the solution
            v += vj;
            w += wj;
        } else if (critical_item == -1) {
            // critical item --> get DW bound and terminate
            double _xj = (capacity - w) / wj;
            dw_bound = v + vj * _xj;
            critical_item = i;
            break;
        }
    }
    dantzigSolution sol = {critical_item, w, v, dw_bound};

    return sol;
};