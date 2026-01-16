#pragma once

#include <vector>

// namespace knapsack {

class knapsackInstance {
  public:
    knapsackInstance() = default;
    void print_stats();
    void solve();

    // Getters
    const int get_num_items() {return num_items;}

    const double get_capacity() {return capacity;}

    const double get_item_weight(int i) {return weights[i];}
    const double get_item_value(int i) {return values[i];}

    // setters
    inline void set_capacity(double w) {capacity = w;}

    void add_item(double weight, double value) {
      num_items += 1;
      values.push_back(value);
      weights.push_back(weight);
    }

  private:
    /*
    * @brief Number of items
    */
    int num_items;
    /*
    * @brief Capacity of the knapsack
    */
    double capacity;
    /*
    * @brief Value of each item
    */
    std::vector<double> values;
    /*
    * @brief Weight of each item
    */
    std::vector<double> weights;
};

// }