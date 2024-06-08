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

    // P1's turn - Checking resources allocation and valid settlement placement
    p1.setTurn(true);
    p1.placeSettelemnt(5, board);
    CHECK(board.getIntersections()[5].getOwner() == &p1);

    p1.placeRoad(4, board);
    CHECK(board.getRoads()[4].getOwner() == &p1);

    // p1 tries to build a settlement at 10 but he can't since they're neighbors
    // Check that the function printed "Cannot place settlement here. Neighboring settlement already owned by Shlomi"
    ostringstream ossSettlement;
    streambuf* oldCerrSettlement = cerr.rdbuf(ossSettlement.rdbuf());
    p1.placeSettelemnt(10, board);
    cerr.rdbuf(oldCerrSettlement); // Restore original cerr buffer

    CHECK(ossSettlement.str().find("Cannot place settlement here. Neighboring settlement already owned by Shlomi") != string::npos);

    p1.placeSettelemnt(12, board);
    CHECK(board.getIntersections()[12].getOwner() == &p1);

    p1.printResources();
    // Check that he got what he should have gotten
    // which is 1 wool
    CHECK(p1.getResources()[Tile::Resource::WOOL] == 1);
    // Check that all the others are 0
    CHECK(p1.getResources()[Tile::Resource::BRICK] == 0);
    CHECK(p1.getResources()[Tile::Resource::ORE] == 0);
    CHECK(p1.getResources()[Tile::Resource::LUMBER] == 0);
    CHECK(p1.getResources()[Tile::Resource::GRAIN] == 0);

    p1.placeRoad(20, board);
    CHECK(board.getRoads()[20].getOwner() == &p1);

    // P2's turn - Checking resources allocation and trading
    catan.endTurn(); 
    p2.setTurn(true);
    cout << catan.getCurrentPlayer() << endl;
    p2.placeSettelemnt(20, board);
    CHECK(board.getIntersections()[20].getOwner() == &p2);

    p2.placeRoad(27, board);
    CHECK(board.getRoads()[27].getOwner() == &p2);

    // Check that if a player tries to build not on his turn, it won't assign anything to him
    ostringstream ossNotTurn;
    streambuf* oldCerrNotTurn = cerr.rdbuf(ossNotTurn.rdbuf());
    p3.placeSettelemnt(50, board);
    cerr.rdbuf(oldCerrNotTurn); // Restore original cerr buffer
    CHECK(board.getIntersections()[50].getOwner() == nullptr);
    CHECK(ossNotTurn.str().find("It is not your turn.") != string::npos);

    int placesNum = 39;
    p2.placeSettelemnt(placesNum, board);
    CHECK(board.getIntersections()[39].getOwner() == &p2);

    // Check that he got what he should have gotten
    // Which is 2 grain, 1 wood
    CHECK(p2.getResources()[Tile::Resource::GRAIN] == 2);
    CHECK(p2.getResources()[Tile::Resource::LUMBER] == 1);
    // Check that all the others are 0
    CHECK(p2.getResources()[Tile::Resource::BRICK] == 0);
    CHECK(p2.getResources()[Tile::Resource::ORE] == 0);
    CHECK(p2.getResources()[Tile::Resource::WOOL] == 0);

    p2.placeRoad(49, board);
    CHECK(board.getRoads()[49].getOwner() == &p2);

    // Check that he can't buy a development card yet (a cerr is being printed)
    int initialDevCards = p2.getDevCardsBought();
    ostringstream ossDev;
    streambuf* oldCerrDev = cerr.rdbuf(ossDev.rdbuf());
    p2.buyDevelopmentCard(board);
    cerr.rdbuf(oldCerrDev); // Restore original cerr buffer

    CHECK(ossDev.str().find("Not enough resources to buy a development card.") != string::npos);
    CHECK(p2.getDevCardsBought() == initialDevCards);

    // Check that he can't trade with himself and expect this line
    // Check that the function printed "Cannot trade with yourself."
    ostringstream ossTrade;
    streambuf* oldCerrTrade = cerr.rdbuf(ossTrade.rdbuf());
    p2.trade(p2, "wood", "brick", 1, 1);
    cerr.rdbuf(oldCerrTrade); // Restore original cerr buffer

    CHECK(ossTrade.str().find("Cannot trade with yourself.") != string::npos);

    // P3's turn - Checking invalid locations and occupied locations
    catan.endTurn(); 
    p3.setTurn(true);

    placesNum = 37;
    p3.placeSettelemnt(placesNum, board);
    CHECK(board.getIntersections()[37].getOwner() == &p3);

    p3.placeRoad(52, board);
    CHECK(board.getRoads()[52].getOwner() == &p3);

    // Player tries to build a settlement in an invalid place
    // Check that the function printed "Invalid settlement location."
    ostringstream ossInvalidSettlement;
    streambuf* oldCerrInvalidSettlement = cerr.rdbuf(ossInvalidSettlement.rdbuf());
    p3.placeSettelemnt(100, board);
    cerr.rdbuf(oldCerrInvalidSettlement); // Restore original cerr buffer

    CHECK(ossInvalidSettlement.str().find("Invalid settlement location.") != string::npos);

    placesNum = 13;
    p3.placeSettelemnt(placesNum, board);
    CHECK(board.getIntersections()[13].getOwner() == &p3);

    // Player tries to build road where he can't, check that nothing changed there
    p3.placeRoad(71, board);
    CHECK(board.getRoads()[71].getOwner() == nullptr);

    // Player tries to build a road in an invalid place
    // Check that the function printed "Invalid road location."
    ostringstream ossRoad;
    streambuf* oldCerrRoad = cerr.rdbuf(ossRoad.rdbuf());
    p3.placeRoad(200, board);
    cerr.rdbuf(oldCerrRoad); // Restore original cerr buffer

    CHECK(ossRoad.str().find("Invalid road location.") != string::npos);

    p3.placeRoad(21, board);
    CHECK(board.getRoads()[21].getOwner() == &p3);

    catan.endTurn(); // p3 ends his turn.

    SUBCASE("End game checks after first turn for each") {
        p1.printPoints(); // p1 has 2 points because it has two settlements.
        p2.printPoints(); // p2 has 3 points because it has two settlements and a bonus points card.
        p3.printPoints(); // p3 has 2 points because it has two settlements.

        //check that it printed "None"
        ostringstream ossNone;
        streambuf* oldCoutNone = cout.rdbuf(ossNone.rdbuf());
        catan.printWinner();
        cout.rdbuf(oldCoutNone); // Restore original cout buffer

        CHECK(ossNone.str().find("None") != string::npos);
    }

    // Check its not failing and the program does it well
    p1.trade(p2, "wood", "brick", 1, 1);

    // With cheats we can check the buy development card function and points 
    // allocating and buying from empty deck
    p1.cheatResources();

    // Buying all the cards in the deck
    for (int i = 0; i < 13; ++i) {
        p1.buyDevelopmentCard(board);
        // Add checks for development card allocation here.
    }

    catan.endTurn(); // p1 ends his turn.

    // Check that a player can't buy a development card if the deck is empty
    // Check that the function printed "No development cards left to draw."
    ostringstream ossEmptyDeck;
    streambuf* oldCerrEmptyDeck = cerr.rdbuf(ossEmptyDeck.rdbuf());
    p2.buyDevelopmentCard(board);
    cerr.rdbuf(oldCerrEmptyDeck); // Restore original cerr buffer

    CHECK(ossEmptyDeck.str().find("No development cards left to draw.") != string::npos);


    catan.endTurn(); // p2 ends his turn.

    

    SUBCASE("End game checks after cheating") {
        p1.printPoints(); // p1 has 14 points because it has two settlements and 10 development cards
        // and 3 knights that gives him the largest army bonus.
        p2.printPoints(); // p2 has 3 points because it has two settlements and a bonus points card.
        p3.printPoints(); // p3 has 2 points because it has two settlements.

        //check that it printed "Shlomi is the winner!"
        ostringstream ossShlomi;
        streambuf* oldCoutNone = cout.rdbuf(ossShlomi.rdbuf());
        catan.printWinner();
        cout.rdbuf(oldCoutNone); // Restore original cout buffer

        CHECK(ossShlomi.str().find("Shlomi is the winner!") != string::npos);
    }

}

