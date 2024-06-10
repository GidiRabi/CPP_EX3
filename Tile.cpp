// Tile.cpp
#include "Tile.hpp"

using namespace std;
using namespace ariel;

/**
 * Constructor for the Tile class.
 * Initializes a tile with a name, resource type, and token number.
 *
 * @param name The name of the tile.
 * @param resource The resource type of the tile.
 * @param number The token number associated with the tile.
 */
Tile::Tile(const std::string& name, Tile::Resource resource, int number)
    : name(name), resource(resource), token(number), construction(Construction::NONE), owner(nullptr) {
    // Initialize other members as needed
}

/**
 * Retrieves the resource type of the tile.
 *
 * @return The resource type of the tile.
 */
Tile::Resource Tile::getResource() const {
    return resource;
}

/**
 * Retrieves the token number of the tile.
 *
 * @return The token number of the tile.
 */
int Tile::getToken() const {
    return token;
}

/**
 * Retrieves the name of the tile.
 *
 * @return The name of the tile.
 */

const std::string& Tile::getName() const {
    return name;
}

/**
 * Retrieves the construction type on the tile.
 *
 * @return The construction type on the tile (e.g., NONE, SETTLEMENT, CITY).
 */
Tile::Construction Tile::getConstruction() const {
    return construction;
}
