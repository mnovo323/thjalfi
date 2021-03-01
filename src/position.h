#ifndef POSITION_H
#define POSITION_H
#include "defs.h"

struct Position
{
    bitboard pieces[PIECES_ARRAY_LENGTH] = {0};

    bitboard occupied;
    bitboard empty;
    bitboard en_passant;
    short int castle_rights;
    bool white_to_move;
    Position();
};

#endif