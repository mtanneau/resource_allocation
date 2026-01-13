# resource_allocation

A C++ project for parsing integer data from text files.

## Project Structure

```
.
├── include/          # Header files
│   └── file_parser.h
├── src/              # Source files
│   ├── file_parser.cpp
│   └── main.cpp
├── tests/            # Unit tests
│   └── test_file_parser.cpp
└── CMakeLists.txt    # Build configuration
```

## Building

### Prerequisites
- CMake 3.10 or higher
- C++ compiler with C++11 support
- Internet connection (for downloading Google Test framework)

### Build Instructions

```bash
# Create a build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
make
```

This will create:
- `resource_allocation` - The main executable
- `test_file_parser` - The test executable

## Usage

The program reads a text file containing one integer per line and parses them into an array.

```bash
./build/resource_allocation <input_file>
```

### Example

Create a test file:
```bash
echo -e "10\n20\n30\n-5\n100" > numbers.txt
```

Run the program:
```bash
./build/resource_allocation numbers.txt
```

Output:
```
Successfully parsed 5 integers:
  [0] = 10
  [1] = 20
  [2] = 30
  [3] = -5
  [4] = 100
```

## Running Tests

After building, run the tests with:

```bash
cd build
ctest --verbose
```

Or run the test executable directly:
```bash
./build/test_file_parser
```

## Features

- Parses integers from text files (one per line)
- Handles positive and negative integers
- Skips empty lines
- Provides clear error messages for invalid input
- Comprehensive unit test coverage