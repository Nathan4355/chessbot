#include <iostream>
#include <vector>
#include <string>
#include "pieces.h"
using namespace std;

/// KING STUFF
King::King()
{
    this->pieceType = 'K';
    this->pieceValue = 1000;
    this->hasMoved = false;
}

bool King ::checkMoved()
{
    return this->hasMoved;
}
