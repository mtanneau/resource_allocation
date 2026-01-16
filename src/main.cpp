#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "problem_data.hpp"
#include "knapsack/knapsack.hpp"
#include "knapsack/solution.hpp"
#include "knapsack/greedy.hpp"
#include "knapsack/generator.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        std::cerr << "  input_file: Path to a text file containing one integer per line" << std::endl;
        return 1;
    }
    
    std::string filepath = argv[1];

    std::cout << "Parsing data from file " << filepath << std::endl;
    auto pbdata = problem_data();
    pbdata.parse_data(filepath);
    pbdata.print_instance();

    // Create a knapsack instance and add a few items
    auto kpg = uniform_generator(20, 20, 1, 100, 1, 100, 0.5);
    auto kp = kpg.generate(42);
    
    // Solve using gredy algorithm
    auto sol = greedy(kp);
    sol.print_solution();

    return 0;
}