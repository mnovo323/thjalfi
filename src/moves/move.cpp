#include "move.h"
#include "../defs.h"

Move::Move(int from, int to, int flags, EnumPieces piece, EnumPieces color)
{
    move = 0;
    //6 bits, 6 bits, and 4 bits on the masks
    move = (to & 0x3f) | ((from & 0x3f) << 6) | ((flags & 0xf)<< 12);
    piece_type = piece;
    color_type = color;
}

unsigned short int Move::get_to()
{
    return (move & 0x3f);
}

unsigned short int Move::get_from()
{
    return ((move >> 6) & 0x3f);
}

unsigned short int Move::get_flags()
{
    return ((move >> 12) & 0xf);
}