// Road.hpp
#ifndef ROAD_HPP
#define ROAD_HPP

#include "Player.hpp"
#include "Dot.hpp"

namespace ariel {
    class Road {
    public:
		Road(Dot* dot1, Dot* dot2);

		void BuildRoard(Player* player);
        Player* getOwner() const;
    private:
        Player* owner = nullptr;
		Dot* dot1;
		Dot* dot2;
    };
}

#endif
