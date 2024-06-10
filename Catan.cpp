// Catan.cpp
#include "Catan.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;
namespace ariel{

/**
 * Constructor for the Catan class.
 * Initializes the game with three players and a game board.
 *
 * @param p1 Reference to the first player.
 * @param p2 Reference to the second player.
 * @param p3 Reference to the third player.
 */
Catan::Catan(Player& p1, Player& p2, Player& p3) 
	: player1(p1), player2(p2), player3(p3), board(Board(p1,p2,p3)){

	ChooseStartingPlayer();

}

/*
 * Chooses the starting player for the game. Player 1 is set to start the game.
 */
void Catan::ChooseStartingPlayer() {
	cout << "Player 1 starts the game! Good Luck GG HF" << endl;
    // Player1 will be the starting player
    player1.setTurn(true);

	currentPlayerIndex = 1;
}

/*
 * Ends the current player's turn and passes the turn to the next player.
 * Updates the currentPlayerIndex to reflect the player whose turn is next.
 */
void Catan::endTurn(){

	std::cout << "Player " << currentPlayerIndex << " has ended his turn." << std::endl;

	//iterate to find whos turn is at the moment (searching whos true)
	if (player1.getTurn()) {
		player1.setTurn(false);
		player2.setTurn(true);
		currentPlayerIndex = 2;
	}
	else if (player2.getTurn()) {
		player2.setTurn(false);
		player3.setTurn(true);
		currentPlayerIndex = 3;
	}
	else if (player3.getTurn()) {
		player1.setTurn(true);
		player3.setTurn(false);
		currentPlayerIndex = 1;
	}

    std::cout << "It's player " << currentPlayerIndex << " turn now." << std::endl;
}

/**
 * Retrieves the game board.
 *
 * @return Reference to the game board.
 */
ariel::Board& Catan::getBoard() {
    return board;
}

/*
 * Prints the winner(s) of the game.
 * The player(s) with the most points (over 10 points) are declared winners.
 * If there is a tie, all players with the most points are declared winners.
 * If no player has over 10 points, "None" is printed.
 */
void Catan::printWinner() {

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
	if (maxPoints >= 10) {
		if (player1.getPoints() == maxPoints) {
			cout << player1.getName() << " is the winner!" << endl;
		}
		if (player2.getPoints() == maxPoints) {
			cout << player2.getName() << " is the winner!" << endl;
		}
		if (player3.getPoints() == maxPoints) {
			cout << player3.getName() << " is the winner!" << endl;
		}
	}else{
		cout << "None" << endl;
	}
}

/**
 * Retrieves the index of the current player.
 *
 * @return Integer representing the current player's index.
 */
int Catan::getCurrentPlayer() {
	return currentPlayerIndex;
}

/*
 * Destructor for the Catan class.
 * Performs any necessary cleanup when a Catan object is destroyed.
 */
Catan::~Catan() {
	
}

}
