// Player.cpp
#include "Player.hpp"

using namespace std;
using namespace ariel;

ariel::Player::Player(const std::string& name) 
    : name(name), isTurn(false), points(2) , settlements(2), roads(2) {
    // Each player starts with 2 settlements and 2 road segments, giving them 2 victory points

    // Initialize the resources map with 0 for each resource type
    resources[Tile::Resource::BRICK] = 0;
    resources[Tile::Resource::LUMBER] = 0;
    resources[Tile::Resource::WOOL] = 0;
    resources[Tile::Resource::GRAIN] = 0;
    resources[Tile::Resource::ORE] = 0;
    resources[Tile::Resource::DESERT] = 0;
}

void Player::placeSettelemnt(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    // Implement this method
}

void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    // Implement this method
}

void Player::rollDice() {
    // Implement this method
}

void Player::endTurn() {
    // Implement this method
}

void Player::trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount) {
    // Implement this method
}

void Player::buyDevelopmentCard() {
    // Implement this method
}

void Player::printPoints() {
    // Implement this method
}