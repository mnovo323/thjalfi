#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <vector>
#include "../position.h"
#include "../defs.h"

namespace Movegen
{
    void generate_moves(Position *position);

    void pawn_push(Position *position);
    void pawn_attack(Position *position);

    void knight_move(Position* position);

    // sliding pieces... Just need to find a bitboard transformatino algorithm...
    // queen == rook + bishop
    // FUCK
    // Need attack bitboards soon for checks.

    void bishop_move(Position* position);

}; // namespace Movegen

#endif