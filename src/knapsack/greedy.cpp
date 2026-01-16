#include <iostream>
#include <vector>
#include <numeric>   // for std::iota
#include <algorithm> // for std::sort

#include "knapsack/knapsack.hpp"
#include "knapsack/solution.hpp"
#include "knapsack/greedy.hpp"

knapsackSolution greedy(knapsackInstance kp) {
    std::cout << "Solving knapsack using greedy algorithm" << std::endl;

    int n = kp.get_num_items();

    // Sort items by increasing v/w ratio
    std::vector<size_t> item_positions(n, 0);
    std::iota(item_positions.begin(), item_positions.end(), 0);
    std::sort(item_positions.begin(), item_positions.end(),
        [&kp] (size_t i, size_t j) {
            return kp.get_item_value(i) * kp.get_item_weight(j) > kp.get_item_value(j) * kp.get_item_weight(i);
        }
    );
    
    // Show sorted items
    std::cout << "Showing sorted items" << std::endl;
    for (size_t i = 0; i < item_positions.size(); i++) {
        auto j = item_positions[i];
        std::cout << i << " --> " << j << " --> " << (kp.get_item_value(j) / kp.get_item_weight(j)) << std::endl;
    }

    // Fill knapsack greedily
    double W = kp.get_capacity();
    double w = 0.0;  // current weight of solution
    double v = 0.0;  // current value of solution
    std::vector<double> x(n, 0.0);  // solution vector

    // Extract data from KP instance, and compute items' ratio
    size_t critical_item = -1;
    double dw_bound = 0.0;
    for (size_t i=0; i < n; i++) {
        auto j = item_positions[i];
        auto vj = kp.get_item_value(j);
        auto wj = kp.get_item_weight(j);

        // do we still have enough capacity?
        if (w + wj <= W) {
            // Add item to solution
            x[j] = 1.0;
            // Update solution value and weight
            v += vj;
            w += wj;
        } else if (w < W && critical_item == -1) {
            // critical item --> get DW bound
            double _xj = (W - w) / wj;
            dw_bound = v + vj * _xj;
            critical_item = i;
            std::cout << "DW bound: " << dw_bound << std::endl;
        }
    }

    auto sol = knapsackSolution(kp, w, v, x);

    return sol;
};