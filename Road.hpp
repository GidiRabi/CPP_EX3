// Road.hpp
#ifndef ROAD_HPP
#define ROAD_HPP

#include "Dot.hpp"
#include "Player.hpp"
#include <iostream>

namespace ariel {

    class Dot; // Forward declaration

    class Road {
    public:
		Road(Dot* dot1, Dot* dot2, int num);

		void buildRoad(Player* player);
        Player* getOwner() const;
		Dot* getDot1() const;
		Dot* getDot2() const;
		int getNumber() const { return number; }
    private:
        Player* owner = nullptr;
		Dot* dot1;
		Dot* dot2;
		int number;
    };
}

#endif
