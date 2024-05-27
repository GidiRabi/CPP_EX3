// Catan.cpp
#include "Catan.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Catan::Catan(Player p1, Player p2, Player p3) : player1(p1), player2(p2), player3(p3) {

	//initialize the board
	board = Board();
	
}


void Catan::ChooseStartingPlayer() {
    // Player1 will be the starting player
    player1.setTurn(true);
    player2.setTurn(false);
    player3.setTurn(false);

}

ariel::Board Catan::getBoard() {
    return this->board;
}

void Catan::printWinner() {
    // go over all players and print the winner (the player with the most points)
	// if there is a tie, print all the winners
	// must have over 10 points to win
	int maxPoints = 10;
	if (player1.getPoints() > maxPoints) {
		maxPoints = player1.getPoints();
	}
	if (player2.getPoints() > maxPoints) {
		maxPoints = player2.getPoints();
	}
	if (player3.getPoints() > maxPoints) {
		maxPoints = player3.getPoints();
	}
	if (player1.getPoints() == maxPoints) {
		cout << player1.getName() << " is the winner!" << endl;
	}
	if (player2.getPoints() == maxPoints) {
		cout << player2.getName() << " is the winner!" << endl;
	}
	if (player3.getPoints() == maxPoints) {
		cout << player3.getName() << " is the winner!" << endl;
	}
}