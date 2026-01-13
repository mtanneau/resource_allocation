#include "file_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool parseIntegerFile(const std::string& filepath, std::vector<int>& numbers) {
    std::ifstream file(filepath);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filepath << std::endl;
        return false;
    }
    
    numbers.clear();
    std::string line;
    int lineNumber = 0;
    
    while (std::getline(file, line)) {
        lineNumber++;
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Try to parse the integer
        std::istringstream iss(line);
        int value;
        
        if (!(iss >> value)) {
            std::cerr << "Error: Invalid integer on line " << lineNumber 
                      << ": " << line << std::endl;
            file.close();
            return false;
        }
        
        // Check if there's extra content after the integer
        std::string extra;
        if (iss >> extra) {
            std::cerr << "Warning: Extra content after integer on line " 
                      << lineNumber << ": " << extra << std::endl;
        }
        
        numbers.push_back(value);
    }
    
    file.close();
    return true;
}
