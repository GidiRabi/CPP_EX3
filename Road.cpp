// Road.cpp
#include "Road.hpp"

namespace ariel {

	/**
	* Constructor for the Road class.
	* Initializes a road with two connecting dots and a unique number.
	*
	* @param dot1 Pointer to the first connecting dot.
	* @param dot2 Pointer to the second connecting dot.
	* @param num An integer representing the unique number of the road.
	*/
	Road::Road(Dot* dot1, Dot* dot2, int num) : dot1(dot1), dot2(dot2), number(num){}

	/**
	* Builds a road for the player if it is not already occupied.
	*
	* @param player Pointer to the player who is building the road.
	* @throws std::invalid_argument if the road is already occupied.
	*/
    void Road::buildRoad(Player* player) {
        if (owner == nullptr) {
            owner = player;
        }
		else{
			throw std::invalid_argument("This road is already occupied by " + owner->getName());
		}
    }

	/**
	* Retrieves the owner of the road.
	*
	* @return Pointer to the player who owns the road.
	*/
    Player* Road::getOwner() const {
        return owner;
    }

	/**
	* Retrieves the first connecting dot of the road.
	*
	* @return Pointer to the first connecting dot.
	*/
	Dot* Road::getDot1() const {
    	return dot1;
	}

	/**
	* Retrieves the second connecting dot of the road.
	*
	* @return Pointer to the second connecting dot.
	*/
	Dot* Road::getDot2() const {
		return dot2;
	}
}