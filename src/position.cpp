#include "defs.h"
#include "position.h"

Position::Position()
{
    pieces[PIECES_ARRAY_LENGTH] = {0};

    occupied = 0ULL;
    empty = 0xffffffffffffffffULL;
    en_passant = 0ULL;
    castle_rights = 1 + 2 + 4 + 8;
    white_to_move = true;
}