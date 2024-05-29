// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "Tile.hpp"
#include "Board.hpp"

namespace ariel{

class Board; // Forward declaration
class Road;  // Forward declaration

struct TradeItem {
    std::string type; // "resource"
    std::string name; // Name of the resource
    int amount;       // Amount of the resource
};

class Player {
public:
    Player(const std::string& name);
    void placeSettelemnt(int placesNum, Board& board);
	void upgradeToCity(int placesNum, Board& board);
    void placeRoad(int placesNum, Board& board);
    void rollDice(Board& board);
    void trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount);
    void buyDevelopmentCard(Board& board);
    int getPoints();
	void printPoints();
	void printResources();
	std::string getName();
	bool getTurn() const;
    void setTurn(bool turn);
    std::map<Tile::Resource, int> getResources() {
        return resources;
    }
	void cheatResources();

private:
    std::string name;
    std::map<Tile::Resource, int> resources;  // Map to keep track of resources
    int points;
    bool isTurn;
    int startingSettlements;
	int startingRoads;
    std::map<std::string, int> developmentCards = {
        {"Knight", 0},
        {"Victory Point", 0},
        {"Road Building", 0},
        {"Year of Plenty", 0},
        {"Monopoly", 0}
    };
	std::vector<Road*> roads;  // Vector to keep track of roads the player has built
    Tile::Resource stringToResource(const std::string& resource);
};

}


#endif // PLAYER_HPP