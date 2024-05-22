// Dot.hpp
#ifndef DOT_HPP
#define DOT_HPP

#include <vector>
#include "Tile.hpp"
#include "Player.hpp"

namespace ariel {
    class Dot {
    public:
        void addTile(const Tile& tile);
        void buildSettlement(Player* player);
        void upgradeToCity();

        const std::vector<Tile>& getTiles() const;
        Player* getOwner() const;
        bool hasSettlement() const;
        bool hasCity() const;

    private:
        std::vector<Tile> tiles;
        Player* owner = nullptr;
        bool isCity = false;
    };
}

#endif