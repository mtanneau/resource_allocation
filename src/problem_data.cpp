#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "problem_data.hpp"

void problem_data::parse_data(const std::string& filepath) {
    std::ifstream file(filepath);
    
    std::string line;
    std::getline(file, line);
    num_items = std::stoi(line);

    std::getline(file, line);
    resource_capacity = std::stod(line);

    double cost;
    double weight;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> cost;
        costs.push_back(cost);
        iss >> weight;
        weights.push_back(weight);
    }

    file.close();
}

void problem_data::print_instance() {
    std::cout << "Number of items: " << num_items << std::endl;
    std::cout << "Resource capacity: " << resource_capacity << std::endl;
    std::cout << "Items (cost, weight):" << std::endl;
    for (int i = 0; i < num_items; ++i) {
        std::cout << "Item " << i + 1 << ": (" << costs[i] << ", " << weights[i] << ")" << std::endl;
    }
}