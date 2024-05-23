// Catan.cpp
#include "Catan.hpp"
#include "Player.hpp"

using namespace std;
using namespace ariel;

Catan::Catan(Player p1, Player p2, Player p3) : player1(p1), player2(p2), player3(p3) {

    // Players place their initial settlements on the board
    board.placeInitialSettlements(player1);
    board.placeInitialSettlements(player2);
    board.placeInitialSettlements(player3);

    // Players receive starting resources based on the locations of their settlements
    board.assignStartingResources(player1);
    board.assignStartingResources(player2);
    board.assignStartingResources(player3);

    // The order of play is determined arbitrarily
    // Let's make player1 the starting player
    player1.setTurn(true);
    player2.setTurn(false);
    player3.setTurn(false);
}


void Catan::ChooseStartingPlayer() {
    // Implement this method
}

ariel::Board Catan::getBoard() {
    // Implement this method
    return this->board;
}

void Catan::printWinner() {
    // Implement this method
}