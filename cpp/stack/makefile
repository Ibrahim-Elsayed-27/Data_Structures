# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Targets
MAIN = StackMain
TEST = StackTest

# Source files
MAIN_SRC = main.cpp Stack.cpp
TEST_SRC = StackTest.cpp Stack.cpp
HEADERS = Stack.hpp

# Default target
all: $(MAIN)

# Compile the main program
$(MAIN): $(MAIN_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(MAIN_SRC)

# Compile the test suite
test: $(TEST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST_SRC)

# Clean build artifacts
clean:
	rm -f $(MAIN) $(TEST)

# Phony targets
.PHONY: all test clean
