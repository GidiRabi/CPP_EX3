// Dot.cpp
#include "Dot.hpp"
#include <iostream>


namespace ariel {

    /**
    * Constructor for the Dot class.
    * Initializes a dot with its neighboring tiles and a unique number.
    *
    * @param neighborTiles A vector of neighboring tiles.
    * @param num An integer representing the unique number of the dot.
    */
    Dot::Dot(const std::vector<Tile>& neighborTiles, int num) : neighborTiles(neighborTiles), owner(nullptr), number(num) {}

    /**
    * Builds a settlement on the dot if it is not already occupied.
    *
    * @param player Pointer to the player who is building the settlement.
    * @throws std::invalid_argument if the intersection is already occupied.
    */
    void Dot::buildSettlement(Player* player) {
        if (buildingType == 0) {
            owner = player;
            buildingType++;
        }else{
			throw std::invalid_argument("This Intersection is already occupied");
		}
    }

    /**
    * Upgrades the building on the dot to a city if a settlement already exists.
    *
    * @throws std::invalid_argument if there is no settlement or if the dot is already a city.
    */
    void Dot::upgradeToCity() {
		if(buildingType == 0){
			throw std::invalid_argument("You must build a settlement first to upgrade to a city");
		}else if (buildingType == 1) {
            buildingType++;
        }else if(buildingType == 2){
			throw std::invalid_argument("This dot is already a city");
		}
    }

    /**
    * Retrieves the owner of the dot.
    *
    * @return Pointer to the player who owns the dot.
    */
    Player* Dot::getOwner() const {
        return owner;
    }

    /**
    * Retrieves the neighboring tiles of the dot.
    *
    * @return A vector of tiles that are neighbors to the dot.
    */
    std::vector<Tile> Dot::getNeighborTiles() const {
        return neighborTiles;
    }

    /**
    * Retrieves the type of building on the dot.
    *
    * @return An integer representing the type of building (0 for none, 1 for settlement, 2 for city).
    */
    int Dot::getBuildingType() {
		return buildingType;
	}

    /**
    * Adds neighboring dots to the dot's list of neighbors.
    *
    * @param neighbors A vector of pointers to neighboring dots.
    */
	void Dot::addNeighbors(const std::vector<Dot*>& neighbors) {
		for (Dot* neighbor : neighbors) {
			this->neighbors.push_back(neighbor);
		}
	}

    /**
    * Retrieves the neighboring dots of the dot.
    *
    * @return A vector of pointers to dots that are neighbors to this dot.
    */
	std::vector<Dot*> Dot::getNeighbors() const {
		return neighbors;
	}
			
}