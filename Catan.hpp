// Catan.hpp
#ifndef CATAN_HPP
#define CATAN_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace ariel{

class Catan {
public:
    Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    Board& getBoard();
    void printWinner();
	void endTurn();
    int getCurrentPlayer();
    ~Catan();
private:
    Player& player1;
    Player& player2;
    Player& player3;
    Board board;
	int currentPlayerIndex;
};
}

#endif // CATAN_HPP