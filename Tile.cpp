// Tile.cpp
#include "Tile.hpp"

using namespace std;
using namespace ariel;

Tile::Tile(const std::string& name, Tile::Resource resource, int number)
    : name(name), resource(resource), number(number), construction(Construction::NONE), owner(nullptr) {
    // Initialize other members as needed
}

Tile::Resource Tile::getResource() const {
    return resource;
}

int Tile::getNumber() const {
    return number;
}

const std::string& Tile::getName() const {
    return name;
}

Tile::Construction Tile::getConstruction() const {
    return construction;
}

Player* Tile::getOwner() const {
    return owner;
}

void Tile::buildRoad(Player& player) {
    // Implement this method
}

void Tile::buildSettlement(Player& player) {
    // Implement this method
}

void Tile::buildCity(Player& player) {
    // Implement this method
}