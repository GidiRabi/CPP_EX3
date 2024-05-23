// Road.cpp
#include "Road.hpp"

namespace ariel {
	Road::Road(Dot* dot1, Dot* dot2) : dot1(dot1), dot2(dot2){}

    void Road::BuildRoard(Player* player) {
        if (owner == nullptr) {
            owner = player;
        }
    }

    Player* Road::getOwner() const {
        return owner;
    }
}