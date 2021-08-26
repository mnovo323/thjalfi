#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstdint>

typedef uint64_t bitboard;

const int PIECES_ARRAY_LENGTH = 8;

// Could I just gen these at run time with bitshifting?
// I mean yeah, probably but I'm in too deep now
enum bb_squares
{
    bb_a1 = 0x0000000000000001ULL,
    bb_a2 = 0x0000000000000002ULL,
    bb_a3 = 0x0000000000000004ULL,
    bb_a4 = 0x0000000000000008ULL,
    bb_a5 = 0x0000000000000010ULL,
    bb_a6 = 0x0000000000000020ULL,
    bb_a7 = 0x0000000000000040ULL,
    bb_a8 = 0x0000000000000080ULL,
    bb_b1 = 0x0000000000000100ULL,
    bb_b2 = 0x0000000000000200ULL,
    bb_b3 = 0x0000000000000400ULL,
    bb_b4 = 0x0000000000000800ULL,
    bb_b5 = 0x0000000000001000ULL,
    bb_b6 = 0x0000000000002000ULL,
    bb_b7 = 0x0000000000004000ULL,
    bb_b8 = 0x0000000000008000ULL,
    bb_c1 = 0x0000000000010000ULL,
    bb_c2 = 0x0000000000020000ULL,
    bb_c3 = 0x0000000000040000ULL,
    bb_c4 = 0x0000000000080000ULL,
    bb_c5 = 0x0000000000100000ULL,
    bb_c6 = 0x0000000000200000ULL,
    bb_c7 = 0x0000000000400000ULL,
    bb_c8 = 0x0000000000800000ULL,
    bb_d1 = 0x0000000001000000ULL,
    bb_d2 = 0x0000000002000000ULL,
    bb_d3 = 0x0000000004000000ULL,
    bb_d4 = 0x0000000008000000ULL,
    bb_d5 = 0x0000000010000000ULL,
    bb_d6 = 0x0000000020000000ULL,
    bb_d7 = 0x0000000040000000ULL,
    bb_d8 = 0x0000000080000000ULL,
    bb_e1 = 0x0000000100000000ULL,
    bb_e2 = 0x0000000200000000ULL,
    bb_e3 = 0x0000000400000000ULL,
    bb_e4 = 0x0000000800000000ULL,
    bb_e5 = 0x0000001000000000ULL,
    bb_e6 = 0x0000002000000000ULL,
    bb_e7 = 0x0000004000000000ULL,
    bb_e8 = 0x0000008000000000ULL,
    bb_f1 = 0x0000010000000000ULL,
    bb_f2 = 0x0000020000000000ULL,
    bb_f3 = 0x0000040000000000ULL,
    bb_f4 = 0x0000080000000000ULL,
    bb_f5 = 0x0000100000000000ULL,
    bb_f6 = 0x0000200000000000ULL,
    bb_f7 = 0x0000400000000000ULL,
    bb_f8 = 0x0000800000000000ULL,
    bb_g1 = 0x0001000000000000ULL,
    bb_g2 = 0x0002000000000000ULL,
    bb_g3 = 0x0004000000000000ULL,
    bb_g4 = 0x0008000000000000ULL,
    bb_g5 = 0x0010000000000000ULL,
    bb_g6 = 0x0020000000000000ULL,
    bb_g7 = 0x0040000000000000ULL,
    bb_g8 = 0x0080000000000000ULL,
    bb_h1 = 0x0100000000000000ULL,
    bb_h2 = 0x0200000000000000ULL,
    bb_h3 = 0x0400000000000000ULL,
    bb_h4 = 0x0800000000000000ULL,
    bb_h5 = 0x1000000000000000ULL,
    bb_h6 = 0x2000000000000000ULL,
    bb_h7 = 0x4000000000000000ULL,
    bb_h8 = 0x8000000000000000ULL
};

enum files
{
    FILE_1 = 0x0101010101010101ULL,
    FILE_2 = 0x0202020202020202ULL,
    FILE_3 = 0x0404040404040404ULL,
    FILE_4 = 0x0808080808080808ULL,
    FILE_5 = 0x1010101010101010ULL,
    FILE_6 = 0x2020202020202020ULL,
    FILE_7 = 0x4040404040404040ULL,
    FILE_8 = 0x8080808080808080ULL
};

enum ranks
{
    RANK_A = 0x00000000000000FFULL,
    RANK_B = 0x000000000000FF00ULL,
    RANK_C = 0x0000000000FF0000ULL,
    RANK_D = 0x00000000FF000000ULL,
    RANK_E = 0x000000FF00000000ULL,
    RANK_F = 0x0000FF0000000000ULL,
    RANK_G = 0x00FF000000000000ULL,
    RANK_H = 0xFF00000000000000ULL
};

enum square_index
{
    a1 = 0,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    b1,
    b2,
    b3,
    b4,
    b5,
    b6,
    b7,
    b8,
    c1,
    c2,
    c3,
    c4,
    c5,
    c6,
    c7,
    c8,
    d1,
    d2,
    d3,
    d4,
    d5,
    d6,
    d7,
    d8,
    e1,
    e2,
    e3,
    e4,
    e5,
    e6,
    e7,
    e8,
    f1,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7,
    f8,
    g1,
    g2,
    g3,
    g4,
    g5,
    g6,
    g7,
    g8,
    h1,
    h2,
    h3,
    h4,
    h5,
    h6,
    h7,
    h8
};

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

extern bitboard knight_table[];

void init_arrays(bitboard array[]);

#endif