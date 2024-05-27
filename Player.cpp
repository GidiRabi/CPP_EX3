// Player.cpp
#include "Player.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

ariel::Player::Player(const std::string& name) 
    : name(name), isTurn(false), points(2) , startingSettlements(2), roads(2) {
    // Each player starts with 2 settlements and 2 road segments, giving them 2 victory points

    // Initialize the resources map with 0 for each resource type
	for (int i = static_cast<int>(Tile::Resource::BRICK); i <= static_cast<int>(Tile::Resource::DESERT); ++i) {
        resources[static_cast<Tile::Resource>(i)] = 0;
    }
}

void placeSettelemnt(const std::vector<int>& placesNum, Board& board) {
	
}

void placeRoad(const std::vector<int>& placesNum, Board& board) {
    // Implement this method
}

void Player::rollDice() {
    // Implement this method
}

void Player::endTurn() {
	this->isTurn = false;
}

void Player::trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount) {
    std::cout << this->name << " offers " << giveAmount << " " << give << " for " << takeAmount << " " << take << " from " << other.name << "." << std::endl;

    char response;
    std::cout << "Does " << other.name << " agree to this trade? (Y/n): ";
    std::cin >> response;

    if (response == 'Y' || response == 'y') {
        Tile::Resource giveResource = stringToResource(give);
        Tile::Resource takeResource = stringToResource(take);

        if (this->resources[giveResource] >= giveAmount && other.resources[takeResource] >= takeAmount) {
            this->resources[giveResource] -= giveAmount;
            this->resources[takeResource] += takeAmount;

            other.resources[takeResource] -= takeAmount;
            other.resources[giveResource] += giveAmount;

            std::cout << "Trade completed successfully." << std::endl;
        } else {
            std::cout << "Trade failed: insufficient resources." << std::endl;
        }
    } else {
        std::cout << "Trade cancelled." << std::endl;
    }
}

Tile::Resource Player::stringToResource(const std::string& resource) {
    if (resource == "brick") return Tile::Resource::BRICK;
    if (resource == "wood") return Tile::Resource::LUMBER;
    if (resource == "wool") return Tile::Resource::WOOL;
    if (resource == "grain") return Tile::Resource::GRAIN;
    if (resource == "ore") return Tile::Resource::ORE;
    throw std::invalid_argument("Unknown resource: " + resource);
}

void Player::buyDevelopmentCard() {
    // Implement this method
}

int Player::getPoints() {
    return points;
}

void Player::printPoints() {
	std::cout << name << " has " << points << " points." << std::endl;
}

string Player::getName() {
	return name;
}