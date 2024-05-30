// 325483444 gidirabi111@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "Catan.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace ariel;


TEST_CASE("Player initialization") {
    Player p1("Gidi");
    CHECK(p1.getName() == "Gidi");
    CHECK(p1.getPoints() == 2); // Each player starts with 2 points (2 settlements)
}

TEST_CASE("Place settlement and road") {
    Player p1("Gidi");
    Player p2("Nael");
    Player p3("Ido");
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    p1.placeSettelemnt(5, board);
    CHECK(board.getIntersections()[5].getOwner() == &p1);

    p1.placeRoad(4, board);
    CHECK(board.getRoads()[4].getOwner() == &p1);
}

