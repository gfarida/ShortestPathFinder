TARGET = minPathLen
CXX = g++
CXXFLAGS = -Wall

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

SRC_FILES = $(SRC_DIR)/Graph.cpp $(SRC_DIR)/main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/Graph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	@echo "Running pytests..."
	@python3 -m pytest $(TEST_DIR)/test_minPathLen.py

clean:
	rm -f $(OBJ_FILES) $(TARGET) *.out.tmp