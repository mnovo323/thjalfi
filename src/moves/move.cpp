#include "move.h"
#include "../defs.h"

Move::Move(unsigned int& from, unsigned int& to, unsigned int& flags, unsigned short int& piece, unsigned short int& color)
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