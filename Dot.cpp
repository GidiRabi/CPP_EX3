// Dot.cpp
#include "Dot.hpp"

using namespace ariel;

void Dot::addTile(const Tile& tile) {
    tiles.push_back(tile);
}

void Dot::buildSettlement(Player* player) {
    owner = player;
}

void Dot::upgradeToCity() {
    if (owner != nullptr) {
        isCity = true;
    }
}

const std::vector<Tile>& Dot::getTiles() const {
    return tiles;
}

Player* Dot::getOwner() const {
    return owner;
}

bool Dot::hasSettlement() const {
    return owner != nullptr && !isCity;
}

bool Dot::hasCity() const {
    return owner != nullptr && isCity;
}