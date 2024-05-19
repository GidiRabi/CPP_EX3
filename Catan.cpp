// Catan.cpp
#include "Catan.hpp"

using namespace std;
using namespace ariel;

Catan::Catan(Player& p1, Player& p2, Player& p3) : player1(p1), player2(p2), player3(p3) {

    // Players receive starting resources based on the locations of their settlements
    // Assuming that the Board class has a method to assign starting resources
    board.assignStartingResources(player1);
    board.assignStartingResources(player2);
    board.assignStartingResources(player3);

    // The order of play is determined arbitrarily
    // Let's make player1 the starting player
    player1.isTurn = true;
    player2.isTurn = false;
    player3.isTurn = false;
}


void Catan::ChooseStartingPlayer() {
    // Implement this method
}

Board Catan::getBoard() {
    // Implement this method
    return board;
}

void Catan::printWinner() {
    // Implement this method
}