// Catan.hpp
#ifndef CATAN_HPP
#define CATAN_HPP

#include <memory>  // for std::shared_ptr
#include "Player.hpp"
#include "Board.hpp"

namespace ariel{

class Catan {
public:
    Catan(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, std::shared_ptr<Player> p3);
    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
private:
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Player> player3;
    Board board;
    // other private members as needed
};
}

#endif // CATAN_HPP