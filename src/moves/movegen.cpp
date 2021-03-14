#include "movegen.h"
#include "../position.h"
#include "../defs.h"
#include "move.h"
#include "../util.h"
#include <vector>
#include <iostream>
#include <cassert>

void Movegen::pawn_push(Position* position)
{
    if (position->white_to_move)
    {
        bitboard pawns = position->pieces[Pawn] & position->pieces[White];
        bitboard valid_one_pushes = (pawns << 8) & ~position->occupied;
        bitboard valid_two_pushes = ((pawns & 0x000000000000ff00ULL) << 16) & ~position->occupied & ~(position->occupied << 8);
        //bitscan through move boards and generate moves and push moves into position->move_list
        while (valid_one_pushes)
        {
            int to = bitscan_forward(valid_one_pushes);
            valid_one_pushes &= valid_one_pushes - 1;
            int from = to >> 8;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }
        while (valid_two_pushes)
        {
            int to = bitscan_forward(valid_two_pushes);
            valid_two_pushes &= valid_two_pushes - 1;
            int from = to >> 16;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }
    }
    else
    {
        bitboard pawns = position->pieces[Pawn] & position->pieces[Black];
        bitboard valid_one_pushes = (pawns >> 8) & ~position->occupied;
        bitboard valid_two_pushes = ((pawns & 0x00FF000000000000ULL) >> 16) & ~position->occupied & ~(position->occupied >> 8);

        while (valid_one_pushes)
        {
            int to = bitscan_forward(valid_one_pushes);
            valid_one_pushes &= valid_one_pushes - 1;
            int from = to << 8;
            Move move_to_add(from, to, 0, Pawn, Black);
            position->move_list.push_back(move_to_add);
        }
        while (valid_two_pushes)
        {
            int to = bitscan_forward(valid_two_pushes);
            valid_two_pushes &= valid_two_pushes - 1;
            int from = to << 16;
            Move move_to_add(from, to, 0, Pawn, Black);
            position->move_list.push_back(move_to_add);
        }
    }
};

void Movegen::pawn_attack(Position* position)
{
    if (position->white_to_move)
    {
        //NE & NW attacks
        bitboard pawns = position->pieces[Pawn] & position->pieces[White];
        bitboard valid_NE = (pawns << 9) & ~0x0101010101010101 & position->occupied & position->pieces[Black];
        bitboard valid_NW = (pawns << 7) & ~0x8080808080808080 & position->occupied & position->pieces[Black];

        while (valid_NE)
        {
            int to = bitscan_forward(valid_NE);
            valid_NE &= valid_NE - 1;
            int from = to >> 9;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }
        while (valid_NW)
        {
            int to = bitscan_forward(valid_NW);
            valid_NW &= valid_NW - 1;
            int from = to >> 7;
            Move move_to_add(from, to, 0, Pawn, White);
            position->move_list.push_back(move_to_add);
        }


    }
    else
    {
        //SE & SW attacks
        bitboard pawns = position->pieces[Pawn] & position->pieces[Black];
        bitboard valid_SW = (pawns >> 9) & ~0x8080808080808080 & position->occupied & position->pieces[White];
        bitboard valid_SE = (pawns >> 7) & ~0x0101010101010101 & position->occupied & position->pieces[White];

        while (valid_SE)
        {
            int to = bitscan_forward(valid_SE);
            valid_SE &= valid_SE - 1;
            int from = to << 7;
            Move move_to_add(from, to, 0, Pawn, Black);
            position->move_list.push_back(move_to_add);
        }
        while (valid_SW)
        {
            int to = bitscan_forward(valid_SW);
            valid_SW &= valid_SW - 1;
            int from = to << 9;
            Move move_to_add(from, to, 0, Pawn, Black);
            position->move_list.push_back(move_to_add);
        }
    }
    
};

void Movegen::knight_move(Position* position)
{
    if (position->white_to_move)
    {
        bitboard knights = position->pieces[Knight] & position->pieces[White];
        while (knights)
        {
            int from = bitscan_forward(knights);
            knights &= knights - 1;
            bitboard possible_moves = knight_table[from] & ~position->pieces[White];
            bitboard attack_moves = possible_moves & position->pieces[Black];
            bitboard quiet_moves = possible_moves ^ attack_moves;
            while (attack_moves)
            {
                int to = bitscan_forward(attack_moves);
                attack_moves &= attack_moves - 1;
                Move move_to_add(from, to, 0, Knight, White);
                position->move_list.push_back(move_to_add);
            }
            while ( quiet_moves)
            {
                int to = bitscan_forward(quiet_moves);
                quiet_moves &= quiet_moves - 1;
                Move move_to_add(from, to, 0, Knight, White);
                position->move_list.push_back(move_to_add);
            }
        }
    }
    else
    {
        bitboard knights = position->pieces[Knight] & position->pieces[Black];
        while (knights)
        {
            int from = bitscan_forward(knights);
            knights &= knights - 1;
            bitboard possible_moves = knight_table[from] & ~position->pieces[Black];
            bitboard attack_moves = possible_moves & position->pieces[White];
            bitboard quiet_moves = possible_moves ^ attack_moves;
            while (attack_moves)
            {
                int to = bitscan_forward(attack_moves);
                attack_moves &= attack_moves - 1;
                Move move_to_add(from, to, 0, Knight, Black);
                position->move_list.push_back(move_to_add);
            }
            while ( quiet_moves)
            {
                int to = bitscan_forward(quiet_moves);
                quiet_moves &= quiet_moves - 1;
                Move move_to_add(from, to, 0, Knight, Black);
                position->move_list.push_back(move_to_add);
            }
        }
    }

};

void Movegen::generate_moves(Position* position)
{
    assert(position != nullptr);
    pawn_push(position);
    pawn_attack(position);
    knight_move(position);
};

/*void Movegen::pawn_attack(Position* position)
{

};*/