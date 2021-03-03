#include "movegen.h"
#include "../position.h"
#include "../defs.h"
#include "move.h"

void Movegen::generate_moves(Position* position)
{
    pawn_push(position);
    pawn_attack(position);
};

void Movegen::pawn_push(Position* position)
{
    if (position->white_to_move)
    {
        bitboard pawns = position->pieces[Pawn] | position->pieces[White];
        bitboard valid_one_pushes = (pawns << 8) ^ position->occupied;
        bitboard valid_two_pushes = ((pawns & 0x000000000000ff00ULL) << 8) ^ position->occupied;
        //bitscan through move boards and generate moves and push into position->move_list
        //look into debruijn sequence?
        if (valid_one_pushes)
        {
            do
            {
                int index =
            } while (valid_one_pushes &= valid_one_pushes - 1);
        }
    }
    else
    {

    }
};

void Movegen::pawn_attack(Position* position)
{

};