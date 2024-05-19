CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic
SRCS = Main.cpp Catan.cpp Player.cpp Board.cpp Tile.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = catan

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(EXEC)