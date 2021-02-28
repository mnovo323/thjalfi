#include "defs.h"
#include "util.h"

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