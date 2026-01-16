#include <random>

#include "knapsack/generator.hpp"

knapsackInstance uniform_generator::generate(std::mt19937_64 rng) {
    auto kp = knapsackInstance();

    // Sample number of items
    std::uniform_int_distribution<int> dint(min_num_items, max_num_items);
    auto n = dint(rng);

    double W = 0.0;  // total weight of items
    std::uniform_int_distribution<int> dvalue(min_value, max_value);
    std::uniform_int_distribution<int> dweight(min_weight, max_weight);
    for (int i=0; i < n; i++) {
        // Sample weight and value of item
        double v = dvalue(rng);
        double w = dvalue(rng);
        kp.add_item(w, v);
        W += w;
    }

    W *= capacity_ratio;

    kp.set_capacity(W);

    return kp;
};

knapsackInstance uniform_generator::generate(int seed) {
    std::mt19937_64 rng(seed);
    return generate(rng);
}