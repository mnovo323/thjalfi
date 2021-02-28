#include "board.h"
#include "util.h"
#include <iostream>
#include <string>

int main()
{
    std::string fen;
    std::cout << "Please enter FEN: ";
    std::getline(std::cin, fen);

    Board board(fen);
    board.print_fen(board);

    return 0;
}