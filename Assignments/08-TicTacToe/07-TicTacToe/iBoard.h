#pragma once
#include <memory>

class iBoard
{
public:
    enum class Player { X, O };
    virtual void printBoard() = 0;
    virtual bool move(Player, int row, int col) = 0;
    virtual bool hasWinner() const = 0;
    virtual Player winner() const = 0;
    virtual bool draw() const = 0; 
};