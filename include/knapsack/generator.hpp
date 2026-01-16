#pragma once

#include <random>

#include "knapsack.hpp"

class uniform_generator {
  public:
    uniform_generator(int nmin, int nmax, int wmin, int wmax, int vmin, int vmax, double r) : 
        min_num_items(nmin),
        max_num_items(nmax),
        min_weight(wmin),
        max_weight(wmax),
        min_value(vmin),
        max_value(vmax),
        capacity_ratio(r) {};
    knapsackInstance generate(std::mt19937_64 rng);
    knapsackInstance generate(int seed);

  private:
    int min_num_items;
    int max_num_items;
    int min_weight;
    int max_weight;
    int min_value;
    int max_value;
    double capacity_ratio;
};
