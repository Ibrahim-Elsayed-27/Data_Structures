# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Targets
MAIN = SinglyMain
TEST = SinglyTest

# Source files
MAIN_SRC = main.cpp SinglyLinked.cpp
TEST_SRC = SinglyTest.cpp SinglyLinked.cpp
HEADERS = SinglyLinked.hpp

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
