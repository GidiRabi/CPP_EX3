CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Catan.cpp Main.cpp
TEST_SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Catan.cpp Test.cpp

OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

EXEC = catan
TEST_EXEC = test

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

.PHONY: all clean
