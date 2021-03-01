#ifndef BOARD_H
#define BOARD_H
#include "defs.h"
#include "position.h"
#include <string>

class Board
{
private:
    // Bitboard for every piece type, when I want to find
    // only piece type of certain color, can do bitwise AND
    // with the piece and the color
    Position position;


public:

    

    Board (std::string fen);
    void print_fen(Board board);

    bitboard get_white_pawns(const Board& board);
    bitboard get_black_pawns(const Board& board);
    bitboard get_white_knights(const Board& board);
    bitboard get_black_knights(const Board& board);
    bitboard get_white_bishops(const Board& board);
    bitboard get_black_bishops(const Board& board);
    bitboard get_white_rooks(const Board& board);
    bitboard get_black_rooks(const Board& board);
    bitboard get_white_queens(const Board& board);
    bitboard get_black_queens(const Board& board);
    bitboard get_white_king(const Board& board);
    bitboard get_black_king(const Board& board);


};

#endif