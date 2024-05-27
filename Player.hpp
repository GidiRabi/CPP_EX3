// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "Board.hpp"
#include "Tile.hpp"

namespace ariel{

struct TradeItem {
    std::string type; // "resource"
    std::string name; // Name of the resource
    int amount;       // Amount of the resource
};

class Player {
public:
    Player(const std::string& name);
    void placeSettelemnt(const std::vector<int>& placesNum, Board& board);
    void placeRoad(const std::vector<int>& placesNum, Board& board);
    void rollDice();
    void endTurn();
    void trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount);
    void buyDevelopmentCard();
    int getPoints();
	void printPoints();
	void printResources();
	string getName();
    void setTurn(bool turn) {
        isTurn = turn;
    }
    std::map<Tile::Resource, int> getResources() {
        return resources;
    }

private:
    std::string name;
    std::map<Tile::Resource, int> resources;  // Map to keep track of resources
    int points;
    bool isTurn;
    int startingSettlements;
    std::vector<std::string> developmentCards;
    std::vector<Road*> roads;  // Vector to keep track of roads the player has built
    Tile::Resource stringToResource(const std::string& resource);
};

}


#endif // PLAYER_HPP