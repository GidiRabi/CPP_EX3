CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Catan.cpp Main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = catan

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
