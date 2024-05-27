// Road.cpp
#include "Road.hpp"

namespace ariel {
	Road::Road(Dot* dot1, Dot* dot2, int num) : dot1(dot1), dot2(dot2), number(num){}

    void Road::BuildRoard(Player* player) {
        if (owner == nullptr) {
            owner = player;
        }
		else{
			throw std::invalid_argument("This road is already occupied by " + owner->getName());
		}
    }

    Player* Road::getOwner() const {
        return owner;
    }

	Dot* Road::getDot1() const {
    	return dot1;
	}

	Dot* Road::getDot2() const {
		return dot2;
	}
}