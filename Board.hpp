#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "Dot.hpp"
#include "Road.hpp"
#include "Player.hpp"
#include <vector>
#include <map>
#include <set>


using namespace std;

namespace ariel {

class Dot;
class Road;
class Player;

class Board {
public:
    Board(Player& p1, Player& p2, Player& p3);
    void initializeBoard();
    void assignStartingResources(Dot& dot);
    void upgradeSettlementToCity(Player& player, int settlementLocation);
    vector<Dot>& getIntersections();  // Getter for Intersections
    vector<Tile>& getTiles();         // Getter for tiles
    vector<Road>& getRoads();         // Getter for Roads
    std::map<std::string, int>& getDevelopmentCards();
    void setRobberLocation(int location);
    void assignResources(int roll);
    std::vector<Player*>& getPlayers();    // Getter for players
    void setPlayers(const std::vector<Player*>& newPlayers);  // Setter for players

private:
    vector<Tile> tiles;  // Vector to keep track of tiles in order
    vector<Dot> Intersections;  // Map to keep track of settlements and cities
    vector<Road> Roads;  // Vector to keep track of roads in order
    int robberLocation;
    std::vector<Player*> players;  // List of players

    void createTiles();
    void createIntersections();
    void createRoads();
    map<std::string, int> developmentCards = {
        {"Knight", 3},
        {"Victory Point", 4},
        {"Road Building", 2},
        {"Year of Plenty", 2},
        {"Monopoly", 2}
    };
};

} // namespace ariel

#endif // BOARD_HPP
