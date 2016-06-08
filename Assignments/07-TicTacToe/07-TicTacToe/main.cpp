#include "iBoard.h"
#include "board.h"
#include <memory>
#include <iostream>


int main()
{
    std::unique_ptr<iBoard> board = std::make_unique<Board>();
    iBoard::Player player = iBoard::Player::X;

    while (!board->draw() && !board->hasWinner())
    {
        std::cout << "Player " << (player == iBoard::Player::X ? 'X' : 'O') << "'s turn\n";
        bool validMove = false;
        while (!validMove)
        {
            board->printBoard();
            int row{ -1 }, col{ -1 };
            std::cout << "Enter a row: ";
            std::cin >> row;
            std::cout << "Enter a col: ";
            std::cin >> col;
            validMove = board->move(player, row, col);
        }

        player = player == iBoard::Player::X ? iBoard::Player::O : iBoard::Player::X;

    }

}
