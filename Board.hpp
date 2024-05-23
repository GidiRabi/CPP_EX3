// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "Dot.hpp"
#include "Road.hpp"
#include <vector>
#include <map>
#include <set>

using namespace std;

namespace ariel {
class Board {
public:
    Board();
    void initializeBoard();
    void assignStartingResources(Player player);
    void placeInitialSettlements(Player player); 
    void upgradeSettlementToCity(Player player, int settlementLocation);
private:
    vector<Tile> tiles;  // Vector to keep track of tiles in order
    vector<Dot> Intersections;  // Map to keep track of settlements and cities
    vector<Road> playerRoads;  // Vector to keep track of roads in order
    void createTiles();
    void assignNumberTokens();
};
}

#endif