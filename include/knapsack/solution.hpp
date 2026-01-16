#pragma once

#include <vector>
#include <iostream>

#include "knapsack.hpp"

class knapsackSolution {
  public:
    knapsackSolution(knapsackInstance kp) : kp(kp), weight(0.0), value(0.0), x(kp.get_num_items(), 0.0) { }
    void print_solution();
    void set_item_value(int i, double v) {
        if (0 <= i < x.size()) {
            std::cout << "Setting item " << i << " to value " << v << std::endl;
            auto xi = x[i];
            // TODO: adjust total value and weight

            // adjust 
            x[i] = v;
        };
    }

  private:
    /*
    * @brief The knapsack instance corresponding to this solution.
    */
    knapsackInstance& kp;
    /*
    * @brief Total weight of this solution
    */
    double weight;
    /*
    * @brief Total value of items in this solution
    */
    double value;
    /*
    * @brief Solution vector
    */
    std::vector<double> x;
};
