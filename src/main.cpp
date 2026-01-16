#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "problem_data.hpp"
#include "knapsack/knapsack.hpp"
#include "knapsack/solution.hpp"

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
    auto kp = knapsackInstance();
    kp.add_item(1.0, 2.0);
    kp.add_item(2.0, 3.0);
    kp.add_item(1.5, 4.0);
    // kp.print_stats();
    kp.solve();

    auto sol = knapsackSolution(kp);
    sol.set_item_value(2, 0.45);
    sol.print_solution();

    return 0;
}