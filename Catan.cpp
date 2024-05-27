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

	currentPlayerIndex = 1;
}

void Catan::endTurn(){

	//iterate to find whos turn is at the moment (searching whos true)
	if (player1.getTurn() == true) {
		player1.setTurn(false);
		player2.setTurn(true);
		currentPlayerIndex = 2;
	}
	else if (player2.getTurn() == true) {
		player2.setTurn(false);
		player3.setTurn(true);
		currentPlayerIndex = 3;
	}
	else if (player3.getTurn() == true) {
		player3.setTurn(false);
		player1.setTurn(true);
		currentPlayerIndex = 1;
	}

	std::cout << "Player " << currentPlayerIndex << " has ended his turn." << std::endl;
    std::cout << "It's player " << currentPlayerIndex << " turn now." << std::endl;
}

ariel::Board Catan::getBoard() {
    return this->board;
}

void Catan::printWinner() {
    // go over all players and print the winner (the player with the most points)
	// if there is a tie, print all the winners
	// must have over 10 points to win
	int maxPoints = 0;
	if (player1.getPoints() >= maxPoints) {
		maxPoints = player1.getPoints();
	}
	if (player2.getPoints() >= maxPoints) {
		maxPoints = player2.getPoints();
	}
	if (player3.getPoints() >= maxPoints) {
		maxPoints = player3.getPoints();
	}

	//if no one has over 10 points, print None
	if (maxPoints < 10) {
		cout << "None" << endl;
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