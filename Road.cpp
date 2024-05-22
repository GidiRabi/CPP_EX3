// Road.cpp
#include "Road.hpp"

using namespace ariel;

Road::Road(Dot* start, Dot* end) : start(start), end(end){}

void Road::buildRoad(Player* player) {
    owner = player;
}

Player* Road::getOwner() const {
    return owner;
}

const Dot* Road::getStart() const {
    return start;
}

const Dot* Road::getEnd() const {
    return end;
}