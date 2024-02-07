#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef PIECES_H
#define PIECES_H

class Pieces
{
public:
    virtual int move();
    virtual char getType();
    vector<int> getLegalMoves();

protected:
    char pieceType;
    int pieceValue;
};

class Pawn : Pieces
{
public:
    Pawn();
    int move();
    int captureL();
    int captureR();
    int enPassant();
    vector<int> getLegalMoves();
};
class Bishop : Pieces
{
public:
    Bishop();
    bool white();
    int move();
    vector<int> getLegalMoves();
};
class Knight : Pieces
{
public:
    Knight();
    int move();
    vector<int> getLegalMoves();
};
class Rook : Pieces
{
public:
    Rook();
    int move();
    vector<int> getLegalMoves();
    bool kingsRook();
    bool checkMoved();

private:
    bool hasMoved;
};
class Queen : Pieces
{
public:
    Queen();
    int move();
    vector<int> getLegalMoves();
};
class King : Pieces
{
public:
    King();
    int move();
    vector<int> getLegalMoves();
    bool inCheck();
    bool checkMoved();
    int kCastle();
    int qCastle();

private:
    bool hasMoved;
};

#endif