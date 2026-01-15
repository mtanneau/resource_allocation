# resource_allocation

A C++ solver for resource allocation problems.

```math
\begin{align}
\min_{x} \quad & \sum_{j} c_{j} x_{j}\\
s.t. \quad & \sum_{j} w_{j} x_{j} = b\\
      & 0 \leq x \leq 1
\end{align}
```

## Building

### Prerequisites
- CMake 3.10 or higher
- C++ compiler with C++11 support
- Internet connection (for downloading Google Test framework)

### Build Instructions

```bash
# Setup
cmake -S . -B build

# Actual build
cmake --build build

# Run unit tests
ctest --test-dir build
```

The main executable will be located at `build/resource_allocation`

## Usage

The program reads a text file containing one integer per line and parses them into an array.

```bash
./build/resource_allocation tests/data/test_data_1.txt
```
