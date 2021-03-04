#include "board.h"
#include "util.h"
#include <iostream>
#include <string>
#include "moves/movegen.h"
#include "ctime"

int main()
{
    std::string fen;
    std::cout << "Please enter FEN: ";
    std::getline(std::cin, fen);

    Board board(fen);
    board.print_fen(board);
    std::clock_t start = std::clock();
    Movegen::generate_moves(&(board.position));
    double duration = (std::clock() - start ) / (double) CLOCKS_PER_SEC;
    int size = board.position.move_list.size();
    std::cout << "Calculated " << size << " moves in " << duration << " seconds." << std::endl;

    return 0;
}