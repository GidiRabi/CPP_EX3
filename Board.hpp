// Board.hpp
#include "Tile.hpp"
#include "Player.hpp"
#include <vector>
#include <map>

namespace ariel{
class Board {
public:
    Board(const std::vector<Tile>& tiles);
    void assignStartingResources(Player& player);
    // other public methods as needed
private:
    std::vector<Tile> tiles;
    std::map<Player, std::vector<std::pair<int, int>>> settlements;  // Map to keep track of settlements
    std::map<Player, std::vector<std::pair<int, int>>> roads;  // Map to keep track of roads
    // private members as needed
};
}