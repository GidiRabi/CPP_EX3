// Road.hpp
#ifndef ROAD_HPP
#define ROAD_HPP

#include "Player.hpp"
#include "Dot.hpp"

namespace ariel {
    class Road {
    public:
        Road(Dot* start, Dot* end);

        void buildRoad(Player* player);

        Player* getOwner() const;
        const Dot* getStart() const;
        const Dot* getEnd() const;

    private:
        Dot* start;
        Dot* end;
        Player* owner = nullptr;
    };
}

#endif