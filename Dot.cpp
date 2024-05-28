// Dot.cpp
#include "Dot.hpp"
#include <iostream>


namespace ariel {

    Dot::Dot(const std::vector<Tile>& neighborTiles, int num) : neighborTiles(neighborTiles), owner(nullptr), number(num) {}

    void Dot::buildSettlement(Player* player) {
        if (buildingType == 0) {
            owner = player;
            buildingType++;
        }else{
			throw std::invalid_argument("This Intersection is already occupied");
		}
    }

    void Dot::upgradeToCity() {
		if(buildingType == 0){
			throw std::invalid_argument("You must build a settlement first to upgrade to a city");
		}else if (buildingType == 1) {
            buildingType++;
        }else if(buildingType == 2){
			throw std::invalid_argument("This dot is already a city");
		}
    }

    Player* Dot::getOwner() const {
        return owner;
    }

    std::vector<Tile> Dot::getNeighborTiles() const {
        return neighborTiles;
    }

    int Dot::getBuildingType() {
		return buildingType;
	}

	void Dot::addNeighbors(const std::vector<Dot*>& neighbors) {
		for (Dot* neighbor : neighbors) {
			this->neighbors.push_back(neighbor);
		}
	}

	std::vector<Dot*> Dot::getNeighbors() const {
		return neighbors;
	}
			
}