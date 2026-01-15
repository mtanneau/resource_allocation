#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class problem_data {
  public:
    problem_data() = default;
    void parse_data(const std::string& filepath);
    void print_instance();

    // number of items
    int num_items;
    // total resource capacity
    double resource_capacity;
    // cost and weight of each item
    std::vector<double> costs;
    std::vector<double> weights;
};