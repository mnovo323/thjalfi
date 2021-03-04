#include "defs.h"
#include "util.h"
#include <cassert>

//This taken from chess programming wiki,
//courtesy of Kim Walisch
const int index64[64] =
{
    0, 47,  1, 56, 48, 27,  2, 60,
   57, 49, 41, 37, 28, 16,  3, 61,
   54, 58, 35, 52, 50, 42, 21, 44,
   38, 32, 29, 23, 17, 11,  4, 62,
   46, 55, 26, 59, 40, 36, 15, 53,
   34, 51, 20, 43, 31, 22, 10, 45,
   25, 39, 14, 33, 19, 30,  9, 24,
   13, 18,  8, 12,  7,  6,  5, 63
};

bitboard flip_vertical(const bitboard& b)
{
    return
    (
        (b << 56) |
        ((b << 40) & 0x00ff000000000000) |
        ((b << 24) & 0x0000ff0000000000) |
        ((b << 8) & 0x000000ff00000000) |
        ((b >> 8) & 0x00000000ff000000) |
        ((b >> 24) & 0x0000000000ff0000) |
        ((b >> 40) & 0x000000000000ff00) |
        ((b >> 56) & 0x00000000000000ff)
    );
}

//I got this code from chessprogrammingwiki
bitboard flip_horizontal(const bitboard& b)
{
    bitboard k1 = 0x5555555555555555ULL;
    bitboard k2 = 0x3333333333333333ULL;
    bitboard k4 = 0x0f0f0f0f0f0f0f0fULL;
    bitboard x = b;
    x = ((x >> 1) & k1) +  2*(x & k1);
    x = ((x >> 2) & k2) +  4*(x & k2);
    x = ((x >> 4) & k4) + 16*(x & k4);
    return x;
}

//taken from chess programming wiki courtesy of
//Kim Walisch
//It uses a De Bruijn sequence with substring length of 6
//which you multiply with the separation bitboard of the
//least significant bit, and the most significant 6 bits
//of the product will be unique, which you can then use to
//index the index64 array. I understand perfectly well
//how this works with an isolated bit, but with the 
//separation board, this is a bit like magic to me.
int bitscan_forward(bitboard& b)
{
    const bitboard debruijn = 0x03f79d71b4cb0a89;
    assert(b != 0);
    return index64[((b ^ (b-1)) * debruijn) >> 58];
}