#ifndef MOVE_H
#define MOVE_H
#include "../defs.h"

// Based on square index 0-63
// short int break down by bits
// 
// least significant 6, TO square
// 6 behind that, FROM square
// most significant 4 bits, flags for special moves

// Mostly inspired from chessprogrammingwiki section on move encoding

struct Move {
private:
    unsigned short int move;
    unsigned short int piece_type;
    unsigned short int color_type;
public:
    Move(unsigned int& from, unsigned int& to, unsigned int& flags, unsigned short int& piece, unsigned short int& color);

    unsigned short int get_to();
    unsigned short int get_from();
    unsigned short int get_flags();
};

#endif