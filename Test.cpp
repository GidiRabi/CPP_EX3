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

TEST_CASE("Full game implementation") {
    Player p1("Shlomi");
    Player p2("Yossi");
    Player p3("Israel");
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    SUBCASE("Player 1 initial placements") {
        p1.placeSettelemnt(5, board);
        CHECK(board.getIntersections()[5].getOwner() == &p1);

        p1.placeRoad(4, board);
        CHECK(board.getRoads()[4].getOwner() == &p1);
    }

    SUBCASE("Player 1 places settlements and roads") {
        p1.placeSettelemnt(5, board);
        CHECK(board.getIntersections()[5].getOwner() == &p1);

        p1.placeRoad(4, board);
        CHECK(board.getRoads()[4].getOwner() == &p1);

        int placesNum = 8;
        p1.placeSettelemnt(placesNum, board);
        CHECK(board.getIntersections()[8].getOwner() == &p1);

        p1.placeRoad(10, board);
        CHECK(board.getRoads()[10].getOwner() == &p1);

    }


    SUBCASE("Player 2 places settlements and roads") {

        catan.endTurn(); 
        cout << catan.getCurrentPlayer() << endl;
        p2.placeSettelemnt(20, board);
        CHECK(board.getIntersections()[20].getOwner() == &p2);

        p2.placeRoad(27, board);
        CHECK(board.getRoads()[27].getOwner() == &p2);

        //not his turn
        (p3.placeSettelemnt(50, board));
        CHECK(board.getIntersections()[50].getOwner() == nullptr);


        int placesNum = 39;
        p2.placeSettelemnt(placesNum, board);
        CHECK(board.getIntersections()[39].getOwner() == &p2);

        p2.placeRoad(49, board);
        CHECK(board.getRoads()[49].getOwner() == &p2);

    }

    SUBCASE("Player 3 places settlements and roads") {
        catan.endTurn(); 
        catan.endTurn(); 

        int placesNum = 37;
        p3.placeSettelemnt(placesNum, board);
        CHECK(board.getIntersections()[37].getOwner() == &p3);

        p3.placeRoad(52, board);
        CHECK(board.getRoads()[52].getOwner() == &p3);

        placesNum = 13;
        p3.placeSettelemnt(placesNum, board);
        CHECK(board.getIntersections()[13].getOwner() == &p3);

        p3.placeRoad(21, board);
        CHECK(board.getRoads()[21].getOwner() == &p3);

        catan.endTurn(); // p3 ends his turn.
    }

    SUBCASE("Dice rolling and resource allocation") {
        p1.rollDice(board); // Assume it prints 4.
        // Add checks for resource allocation here.

        p1.placeRoad(7, board); // Assume p1 can build the road.

        catan.endTurn(); // p1 ends his turn.

        p2.rollDice(board); 

        catan.endTurn(); // p2 ends his turn.

        p3.rollDice(board); // Assume it prints 3.
        // Add checks for resource allocation here.

        catan.endTurn(); // p3 ends his turn.
    }

    SUBCASE("Trade and development cards") {
        p1.trade(p2, "wood", "brick", 1, 1);
        // Add checks for resource exchange here.

        p1.cheatResources();
        for (int i = 0; i < 8; ++i) {
            p1.buyDevelopmentCard(board);
            // Add checks for development card allocation here.
        }

        catan.endTurn(); // p1 ends his turn.

        p2.buyDevelopmentCard(board); // Assume it is a bonus points card.
        // Add checks for development card allocation here.

        catan.endTurn(); // p2 ends his turn.

    }

    SUBCASE("End game checks") {
        p1.printPoints(); // p1 has 2 points because it has two settlements.
        p2.printPoints(); // p2 has 3 points because it has two settlements and a bonus points card.
        p3.printPoints(); // p3 has 2 points because it has two settlements.

        catan.printWinner();
    }

}

