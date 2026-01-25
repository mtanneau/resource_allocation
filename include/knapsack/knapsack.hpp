#pragma once

#include <vector>

// namespace knapsack {

struct dantzigSolution{
  size_t critical_item = 0;
  double weight = 0.0;
  double value = 0.0;
  double dw_bound = 0.0;
};

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
      is_sorted = false;
    }

    /**
     * @brief sort items by decreasing weight/value ratio.
     */
    void sort_items();

    dantzigSolution solve_dantzig();

  private:
    /*
    * @brief Number of items
    */
    int num_items = 0;
    /*
    * @brief Capacity of the knapsack
    */
    double capacity = 0.0;
    /*
    * @brief Value of each item
    */
    std::vector<double> values = {};
    /*
    * @brief Weight of each item
    */
    std::vector<double> weights = {};
    /*
    */
    bool is_sorted = false;
    /**
     * @brief Permutation vector 
     * 
     * `sort_perm[i]` is the index of the item with i-th largest `value/weight` ratio.
     * This should be set just before the instance is solved.
     */
    std::vector<size_t> sort_perm = {};
};

// }