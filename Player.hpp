// Player.hpp
#include <string>
#include <vector>
#include <map>
#include "Board.hpp"
#include "Tile.hpp"  // Include this to access the Resource enum

namespace ariel{

class Player {
public:
    Player(const std::string& name);
    void placeSettelemnt(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void rollDice();
    void endTurn();
    void trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount);
    void buyDevelopmentCard();
    void printPoints();
private:
    std::string name;
    std::map<Tile::Resource, int> resources;  // Map to keep track of resources
    int points;
    bool isTurn;
    std::vector<std::string> developmentCards;
    int settlements;  // Number of settlements the player has
    int roads;  // Number of road segments the player has
};
}