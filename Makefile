CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Main.cpp
OBJ = $(SRC:.cpp=.o)

all: catan

catan: $(OBJ)
	$(CXX) $(CXXFLAGS) -o catan $(OBJ)

Board.o: Board.cpp Board.hpp Tile.hpp Dot.hpp Road.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Tile.o: Tile.cpp Tile.hpp
	$(CXX) $(CXXFLAGS) -c Tile.cpp

Dot.o: Dot.cpp Dot.hpp Player.hpp Tile.hpp Road.hpp
	$(CXX) $(CXXFLAGS) -c Dot.cpp

Road.o: Road.cpp Road.hpp Dot.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Road.cpp

Player.o: Player.cpp Player.hpp Board.hpp Tile.hpp Dot.hpp Road.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Main.o: Main.cpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

clean:
	rm -f *.o catan
