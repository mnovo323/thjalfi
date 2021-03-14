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

}; // namespace Movegen

#endif