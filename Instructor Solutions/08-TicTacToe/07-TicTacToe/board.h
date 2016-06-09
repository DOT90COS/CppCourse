#pragma once

#include "iBoard.h"
#include <fstream>
#include <vector>
#include <memory>
#include <array>
#include <iostream>

class Board : public iBoard
{ 
    enum class Player { E, X, O };
    static const Board::Player E;
    std::array<Board::Player, 9> board_ = { E, E, E, E, E, E, E, E, E };
    std::array<std::array<int, 3>, 8> winningIndexes_;

    Board::Player spot(int r, int c) const;
    static int index(int r, int c);
    Board::Player checkWinner() const;
    static Board::Player toBoardPlayer(iBoard::Player player);
    static iBoard::Player toiBoardPlayer(Board::Player player);
    friend std::ostream& operator<<(std::ostream& os, Board::Player player);

public:
    Board();
    void printBoard() override;
    bool move(iBoard::Player, int row, int col) override;
    bool hasWinner() const override;
    iBoard::Player winner() const override;
    bool draw() const override;
};

std::ostream& operator<<(std::ostream& os, iBoard::Player player);