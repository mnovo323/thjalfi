#include "movegen.h"
#include "../position.h"
#include "../defs.h"
#include "move.h"
#include "../util.h"
#include <vector>
#include <iostream>

void Movegen::pawn_push(Position* position)
{
    if (position->white_to_move)
    {
        bitboard pawns = position->pieces[Pawn] & position->pieces[White];
        bitboard valid_one_pushes = (pawns << 8) & ~position->occupied;
        bitboard valid_two_pushes = ((pawns & 0x000000000000ff00ULL) << 16) & ~position->occupied & ~(position->occupied << 8);
        //bitscan through move boards and generate moves and push moves into position->move_list
        while(valid_one_pushes)
        {
            int to = bitscan_forward(valid_one_pushes);
            valid_one_pushes &= valid_one_pushes - 1;
            int from = to >> 8;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }
        while(valid_two_pushes)
        {
            int to = bitscan_forward(valid_two_pushes);
            valid_two_pushes &= valid_two_pushes - 1;
            int from = to >> 16;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }
    }
};

void Movegen::generate_moves(Position* position)
{
    pawn_push(position);
    //pawn_attack(position);
};



/*void Movegen::pawn_attack(Position* position)
{

};*/