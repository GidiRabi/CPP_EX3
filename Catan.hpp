// Catan.hpp
#include "Player.hpp"
#include "Board.hpp"

namespace ariel{

class Catan {
public:
    Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
private:
    Player& player1;
    Player& player2;
    Player& player3;
    Board board;
    // other private members as needed
};
}