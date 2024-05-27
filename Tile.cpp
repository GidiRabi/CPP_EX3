// Tile.cpp
#include "Tile.hpp"

using namespace std;
using namespace ariel;

Tile::Tile(const std::string& name, Tile::Resource resource, int number)
    : name(name), resource(resource), token(number), construction(Construction::NONE), owner(nullptr) {
    // Initialize other members as needed
}

Tile::Resource Tile::getResource() const {
    return resource;
}

int Tile::getToken() const {
    return token;
}

const std::string& Tile::getName() const {
    return name;
}

Tile::Construction Tile::getConstruction() const {
    return construction;
}
