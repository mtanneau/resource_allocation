#include "file_parser.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        std::cerr << "  input_file: Path to a text file containing one integer per line" << std::endl;
        return 1;
    }
    
    std::string filepath = argv[1];
    std::vector<int> numbers;
    
    if (!parseIntegerFile(filepath, numbers)) {
        std::cerr << "Failed to parse file: " << filepath << std::endl;
        return 1;
    }
    
    std::cout << "Successfully parsed " << numbers.size() << " integers:" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << "  [" << i << "] = " << numbers[i] << std::endl;
    }
    
    return 0;
}
