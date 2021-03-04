#ifndef UTILS_H
#define UTILS_H
#include "defs.h"

// Move each rank to it's appropriate place
// then use bitwise and in that particular rank
// with 0's everywhere else
// then bitwise or with all the moved ranks
bitboard flip_vertical(const bitboard& b);
bitboard flip_horizontal(const bitboard& b);
int bitscan_forward(bitboard& b);

#endif