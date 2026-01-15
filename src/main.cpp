#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "problem_data.hpp"

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

    return 0;
}