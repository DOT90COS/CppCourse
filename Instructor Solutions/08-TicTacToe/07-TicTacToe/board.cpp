#include "board.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Board::Player player)
{
    switch (player)
    {
    case Board::Player::X:
        os << 'X';
        return os;
    case Board::Player::O:
        os << 'O';
        return os;
    default:
        os << ' ';
        return os;
    }
}

int Board::index(int r, int c)
{
    return ((r - 1) * 3 + (c - 1));
}

Board::Player Board::spot(int r, int c) const
{
    auto i = index(r, c);
        return board_[i];
}

void Board::printBoard()
{
    std::cout <<
        "     1     2     3  \n"
        "  +-----------------+ \n"
        "1 |  " << spot(1, 1) << "  |  " << spot(1, 2) << "  |  " << spot(1, 3) << "  |\n"
        "  +-----------------+\n"
        "2 |  " << spot(2, 1) << "  |  " << spot(2, 2) << "  |  " << spot(2, 3) << "  |\n"
        "  +-----------------+\n"
        "3 |  " << spot(3, 1) << "  |  " << spot(3, 2) << "  |  " << spot(3, 3) << "  |\n"
        "  +-----------------+\n";
}

bool Board::move(iBoard::Player p, int r, int c)
{
    if (spot(r,c) != E) //Something is there. 
    {
        return false;
    }
    board_[index(r, c)] = toBoardPlayer(p);
    
    return true;
}

Board::Player Board::checkWinner() const
{
    for (auto& winnCombo : winningIndexes_)
    {
        auto winner = E;
        for (auto i : winnCombo)
        {
            if (board_[i] == E)
            {
                winner = E;
                break;
            }
            else if (winner == E)
            {
                winner = board_[i];
            }
            else if (winner != board_[i]) //Different player
            {
                winner = E;
                break;
            }
        }
        if (winner != E)
            return winner;
    }
    return E;
}

bool Board::hasWinner() const
{
    auto winner = checkWinner();
    if (winner != E)
        return true;
    return false;
}

iBoard::Player Board::winner() const
{
    auto winner = checkWinner();
    return toiBoardPlayer(winner);
}

const Board::Player Board::E = Board::Player::E;

iBoard::Player Board::toiBoardPlayer(Board::Player player)
{
    if (player == E)
        return iBoard::Player::X;
    return (player == Board::Player::X ? iBoard::Player::X : iBoard::Player::O);
}

Board::Player Board::toBoardPlayer(iBoard::Player player)
{
    return (player == iBoard::Player::X ? Board::Player::X : Board::Player::O);
}

bool Board::draw() const
{
    for (auto& space : board_)
    {
        if (space == E)
            return false;
    }
    auto winner = checkWinner();
    if (winner == E)
        return true;
    return false;
}

Board::Board()
{
    /*********************************
         0 | 1 | 2
         ---------
         3 | 4 | 5
         ---------
         6 | 7 | 8
    **********************************/

    winningIndexes_[0] = { 0,1,2 };
    winningIndexes_[1] = { 3,4,5 };
    winningIndexes_[2] = { 6,7,8 };
    winningIndexes_[3] = { 0,3,6 };
    winningIndexes_[4] = { 1,4,7 };
    winningIndexes_[5] = { 2,5,8 };
    winningIndexes_[6] = { 0,4,8 };
    winningIndexes_[7] = { 6,4,2 };

}


std::ostream& operator<<(std::ostream& os, iBoard::Player player)
{
    os << (player == iBoard::Player::X ? 'X' : 'Y');
    return os;
}
