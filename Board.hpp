// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include <vector>
#include <map>
#include <set>
#include <memory> // Include this to use std::shared_ptr

using namespace std;

namespace ariel {
class Board {
public:
    Board();
    void initializeBoard();
    void assignStartingResources(std::shared_ptr<Player> player);
    void placeInitialSettlements(std::shared_ptr<Player> player); // Add this line
    // other public methods as needed
private:
    vector<Tile> tiles;
    map<int, set<int>> graph;  // Graph to represent the possible locations for settlements and roads
    map<std::shared_ptr<Player>, set<int>> playerSettlements;  // Map to keep track of settlements
    map<int, set<Tile>> vertexTiles;  // Map to keep track of tiles adjacent to each vertex
    map<std::shared_ptr<Player>, set<pair<int, int>>> playerRoads;  // Map to keep track of roads
    void createTiles();
    void assignNumberTokens();
};
}

#endif