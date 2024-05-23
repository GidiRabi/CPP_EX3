// Dot.cpp
#include "Dot.hpp"

namespace ariel {
    Dot::Dot(const std::vector<Tile>& neighborTiles) : neighborTiles(neighborTiles) {}

    void Dot::buildSettlement(Player* player) {
        if (buildingType == 0) {
            owner = player;
            buildingType++;
        }else{
			throw std::invalid_argument("This Intersection is already occupied");
		}
    }

    void Dot::upgradeToCity() {
        if (buildingType == 1) {
            buildingType++;
        }else if(buildingType == 2){
			throw std::invalid_argument("This dot is already a city");
		}else{
			throw std::invalid_argument("You must build a settlement first to upgrade to a city");
		}
		
    }

    Player* Dot::getOwner() const {
        return owner;
    }

    std::vector<Tile> Dot::getNeighborTiles() const {
        return neighborTiles;
    }

    int Dot::getBuildingType() const {
        return buildingType;
    }
}