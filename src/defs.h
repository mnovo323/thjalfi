#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstdint>

typedef uint64_t bitboard;

const int PIECES_ARRAY_LENGTH = 8;

/* const enum bb_squares
{
    a1 = 0x0000000000000001ULL,
    a2 = 0x0000000000000002ULL,
    a3 = 0x0000000000000004ULL,
    a4 = 
    a5 = 
    a6 = 
    a7 = 
    a8 = 


}; */

enum EnumPieces
{
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,
    White,
    Black
};
enum EnumCastle
{
    WhiteKingCastle = 1,
    WhiteQueenCastle = 2,
    BlackKingCastle = 4,
    BlackQueenCastle = 8
};

#endif