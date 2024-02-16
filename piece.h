#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef PIECE_H
#define PIECE_H

const int WHITE = 0;
const int BLACK = 1;

class Piece
{
public:
    Piece(int team, char type, char square[2])
    {
        this->pieceType = type;
        this->team = team;
        this->square[0] = square[0];
        this->square[1] = square[1];
    }
    virtual ~Piece() { delete square; }
    virtual char getType();
    vector<int> getLegalMoves();

protected:
    int team;
    char pieceType;
    int pieceValue;
    char square[2];
};

class Pawn : Piece
{
public:
    Pawn(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->pieceType = 'P';
        this->pieceValue = 3;
    }
    ~Pawn() {}
};
class Bishop : Piece
{
public:
    Bishop(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->pieceType = 'B';
        this->pieceValue = 3;
    }
    ~Bishop();
};
class Knight : Piece
{
public:
    Knight(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->pieceType = 'N';
        this->pieceValue = 3;
    }
    ~Knight();
};
class Rook : Piece
{
public:
    Rook(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->pieceType = 'R';
        this->pieceValue = 5;
    }
    ~Rook(){};

private:
    bool hasMoved;
};
class Queen : Piece
{
public:
    Queen(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->pieceType = 'Q';
        this->pieceValue = 9;
    }
    ~Queen() {}
};
class King : Piece
{
public:
    King(int team, char type, char square[2]) : Piece(team, type, square)
    {
        this->hasMoved = false;
        this->checked = false;
        this->pieceType = 'K';
        this->pieceValue = 1000;
    }
    ~King() {}
    bool inCheck();
    bool checkMoved();

private:
    bool hasMoved;
    bool checked;
};

#endif