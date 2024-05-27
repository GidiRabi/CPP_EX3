// Dot.hpp
#ifndef DOT_HPP
#define DOT_HPP

#include "Tile.hpp"
#include "Player.hpp"

namespace ariel {
    class Dot {
    public:
        Dot(const std::vector<Tile>& neighborTiles, int num);
        void buildSettlement(Player* player);
        void upgradeToCity();
        Player* getOwner() const;
		std::vector<Tile> getNeighborTiles() const;
		void getBuildingType();
		std::vector<Road*> getConnectedRoads() const; 

    private:
        std::vector<Tile> neighborTiles;
        Player* owner = nullptr;
		int number;
        int buildingType = 0;  // 0 = no building, 1 = settlement, 2 = city
		std::vector<Road*> connectedRoads;
    };
}

#endif