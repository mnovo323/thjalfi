#include "defs.h"

void init_arrays(bitboard array[])
{
    for (int i = 0; i < 64; i++)
    {
        bitboard solution = 0;
        //UUR mask out first two ranks and the A-file, all these use bitmasks like that
        //not worried about efficiency because this only runs once, only worried about readability.
        solution = solution | (((1ULL << i) << 17) & ~0x00000000000000ff & ~0x000000000000ff00 & ~0x0101010101010101);
        //URR
        solution = solution | (((1ULL << i) << 10) & ~0x00000000000000ff & ~0x0101010101010101 & ~0x0202020202020202);
        //DRR
        solution = solution | (((1ULL << i) >> 6) & ~0xff00000000000000 & ~0x0101010101010101 & ~0x0202020202020202);
        //DDR
        solution = solution | (((1ULL << i) >> 15) & ~0xff00000000000000 & ~0x00ff000000000000 & ~0x0101010101010101);
        //DDL
        solution = solution | (((1ULL << i) >> 17) & ~0xff00000000000000 & ~0x00ff000000000000 & ~0x8080808080808080);
        //DLL
        solution = solution | (((1ULL << i) >> 10) & ~0xff00000000000000 & ~0x8080808080808080 & ~0x4040404040404040);
        //ULL
        solution = solution | (((1ULL << i) << 6) & ~0x00000000000000ff & ~0x8080808080808080 & ~0x4040404040404040);
        //UUL
        solution = solution | (((1ULL << i) << 15) & ~0x00000000000000ff & ~0x000000000000ff00 & ~0x8080808080808080);
        array[i] = solution;
    }
};