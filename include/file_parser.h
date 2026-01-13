#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

/**
 * @brief Parse a text file containing integers (one per line) into a vector
 * 
 * @param filepath Path to the input file
 * @param numbers Output vector to store parsed integers
 * @return true if parsing was successful, false otherwise
 */
bool parseIntegerFile(const std::string& filepath, std::vector<int>& numbers);

#endif // FILE_PARSER_H
