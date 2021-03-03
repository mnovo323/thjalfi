#ifndef POSITION_H
#define POSITION_H
#include "defs.h"
#include <vector>
#include "moves/move.h"

struct Position
{
    bitboard pieces[PIECES_ARRAY_LENGTH] = {0};

    bitboard occupied;
    bitboard empty;
    bitboard en_passant; //prolly doesn't need to be bitboard... maybe short int for the index?
    short int castle_rights;
    bool white_to_move;

    std::vector<Move> move_list;

    Position();
};

#endif