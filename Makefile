CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Homebrew standard installation paths for SFML
SFML_INCLUDE = /usr/local/opt/sfml/include
SFML_LIB = /usr/local/opt/sfml/lib

SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Catan.cpp Main.cpp
TEST_SRC = Board.cpp Tile.cpp Dot.cpp Road.cpp Player.cpp Catan.cpp Test.cpp

OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

EXEC = catan
TEST_EXEC = test

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE) -L$(SFML_LIB) -o $@ $^ $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE) -L$(SFML_LIB) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE) -c $<

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

.PHONY: all clean
