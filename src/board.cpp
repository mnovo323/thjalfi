#include "board.h"
#include <string>
#include "util.h"
#include <iostream>

Board::Board(std::string fen)
{
    pieces[PIECES_ARRAY_LENGTH] = {0};
    occupied = 0;
    empty = 0xffffffffffffffff;
    en_passant = 0;

    bBKCastle = false;
    bBQCastle = false;
    bWKCastle = false;
    bWQCastle = false;
    white_to_move = false;

    short unsigned int fen_index(0);
    short unsigned int loop_index(0);
    bool past_enpassant(false);

    for (char c : fen)
    {
        switch (c)
        {
            case 'p':
                pieces[Pawn] = pieces[Pawn] | (1ULL << fen_index);
                pieces[Black] = pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'n':
                pieces[Knight] = pieces[Knight] | (1ULL << fen_index);
                pieces[Black] = pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'b':
                if (fen_index < 64)
                {
                    pieces[Bishop] = pieces[Bishop] | (1ULL << fen_index);
                    pieces[Black] = pieces[Black] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else if (fen_index == 64)
                {
                    fen_index++;
                    continue;
                }
                else
                {
                    en_passant = (1ULL << 1);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
                    
                }
                
            case 'r':
                pieces[Rook] = pieces[Rook] | (1ULL << fen_index);
                pieces[Black] = pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'q':
                if (fen_index < 64)
                {
                    pieces[Queen] = pieces[Queen] | (1ULL << fen_index);
                    pieces[Black] = pieces[Black] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    bBQCastle = true;
                    fen_index++;
                    continue;
                }
                
            case 'k':
                if (fen_index < 64)
                {
                    pieces[King] = pieces[King] | (1ULL << fen_index);
                    pieces[Black] = pieces[Black] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    bBKCastle = true;
                    fen_index++;
                    continue;
                }
                
            case 'P':
                pieces[Pawn] = pieces[Pawn] | (1ULL << fen_index);
                pieces[White] = pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'N':
                
                pieces[Knight] = pieces[Knight] | (1ULL << fen_index);
                pieces[White] = pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'B':
                pieces[Bishop] = pieces[Bishop] | (1ULL << fen_index);
                pieces[White] = pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'R':
                
                pieces[Rook] = pieces[Rook] | (1ULL << fen_index);
                pieces[White] = pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'Q':
                if (fen_index < 64)
                {
                    pieces[Queen] = pieces[Queen] | (1ULL << fen_index);
                    pieces[White] = pieces[White] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    bWQCastle = true;
                    fen_index++;
                    continue;
                }
            case 'K':
                if (fen_index < 64)
                {
                    pieces[King] = pieces[King] | (1ULL << fen_index);
                    pieces[White] = pieces[White] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    bWKCastle = true;
                    fen_index++;
                    continue;
                }
            case 'w':
                white_to_move = true;
                fen_index++;
                continue;
            case '1':
                if (fen_index < 64)
                {
                    fen_index++;
                    continue;
                }
            case '2':
                if (fen_index < 64)
                {
                    fen_index += 2;
                    continue;
                }
            case '3':
                if (fen_index < 64)
                {
                    fen_index += 3;
                    continue;
                }
            case '4':
                if (fen_index < 64)
                {
                    fen_index += 4;
                    continue;
                }
            case '5':
                if (fen_index < 64)
                {
                    fen_index += 5;
                    continue;
                }
            case '6':
                if (fen_index < 64)
                {
                    fen_index += 6;
                    continue;
                }
            case '7':
                if (fen_index < 64)
                {
                    fen_index += 7;
                    continue;
                }
            case '8':
                if (fen_index < 64)
                {
                    fen_index += 8;
                    continue;
                }
            case '-':
                past_enpassant = true;
                fen_index++;
            case 'a':
                en_passant = (1);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'c':
                en_passant = (1ULL << 2);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'd':
                en_passant = (1ULL << 3);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'e':
                en_passant = (1ULL << 4);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'f':
                en_passant = (1ULL << 5);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'g':
                en_passant = (1ULL << 6);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }
            case 'h':
                en_passant = (1ULL << 7);
                    if (fen[loop_index + 1] == '3')
                    {
                        en_passant = en_passant << 40;
                    }
                    else
                    {
                        en_passant = en_passant << 16;
                    }

        }
        loop_index++;
    }
    for (int i = 0; i < PIECES_ARRAY_LENGTH; i++)
    {
        pieces[i] = flip_vertical(pieces[i]);
        pieces[i] = flip_horizontal(pieces[i]);
    }
    //might be faster to do a 180 rotation...
    en_passant = flip_vertical(en_passant);
    en_passant = flip_vertical(en_passant);
    occupied = pieces[White] | pieces[Black];
    empty = ~occupied;

}

void Board::print_fen(Board board)
{
    char output[64] =
    {
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.',
        '.', '.', '.', '.', '.','.', '.', '.'
    };
    bitboard black_pawns = board.get_black_pawns(board);
    bitboard black_knights = board.get_black_knights(board);
    bitboard black_bishops = board.get_black_bishops(board);
    bitboard black_rooks = board.get_black_rooks(board);
    bitboard black_queens = board.get_black_queens(board);
    bitboard black_king = board.get_black_king(board);
    bitboard white_pawns = board.get_white_pawns(board);
    bitboard white_knights = board.get_white_knights(board);
    bitboard white_bishops = board.get_white_bishops(board);
    bitboard white_rooks = board.get_white_rooks(board);
    bitboard white_queens = board.get_white_queens(board);
    bitboard white_king = board.get_white_king(board);
    for (int i = 0; i < 64; i++)
    {
        if (((black_pawns >> i)) & 1 == 1)
        {
            output[i] = 'p';
            continue;
        }
        if (((black_bishops >> i) & 1) == 1)
        {
            output[i] = 'b';
            continue;
        }
        if (((black_knights >> i) & 1) == 1)
        {
            output[i] = 'n';
            continue;
        }
        if (((black_rooks >> i) & 1) == 1)
        {
            output[i] = 'r';
            continue;
        } 
        if (((black_queens >> i) & 1) == 1)
        {
            output[i] = 'q';
            continue;
        }
        if (((black_king >> i) & 1) == 1)
        {
            output[i] = 'k';
            continue;
        }
        if (((white_pawns >> i) & 1) == 1)
        {
            output[i] = 'P';
            continue;
        }
        if (((white_bishops >> i) & 1) == 1)
        {
            output[i] = 'B';
            continue;
        }
        if (((white_knights >> i) & 1) == 1)
        {
            output[i] = 'N';
            continue;
        }
        if (((white_rooks >> i) & 1) == 1)
        {
            output[i] = 'R';
            continue;
        }
        if (((white_queens >> i) & 1) == 1)
        {
            output[i] = 'Q';
            continue;
        }
        if (((white_king >> i) & 1) == 1)
        {
            output[i] = 'K';
            continue;
        }
    }
    std::cout << "\n\n";
    if (board.white_to_move)
    {
        std::cout << "White to move\n";
    }
    else
    {
        std::cout << "Black to move\n";
    }

    int index(55);
    for(int i = 8; i > 0; i--)
    {
        for (int j = 8; j > 0; j--)
        {
            std::cout << output[index + j];
        }
        index -= 8;
        std::cout << '\n';
    }
}

bitboard Board::get_white_pawns(const Board& board)
{
    return pieces[White] & pieces[Pawn];
}

bitboard Board::get_black_pawns(const Board& board)
{
    return pieces[Black] & pieces[Pawn];
}
bitboard Board::get_white_knights(const Board& board)
{
    return pieces[White] & pieces[Knight];
}

bitboard Board::get_black_knights(const Board& board)
{
    return pieces[Black] & pieces[Knight];
}

bitboard Board::get_white_bishops(const Board& board)
{
    return pieces[White] & pieces[Bishop];
}

bitboard Board::get_black_bishops(const Board& board)
{
    return pieces[Black] & pieces[Bishop];
}

bitboard Board::get_white_rooks(const Board& board)
{
    return pieces[White] & pieces[Rook];
}

bitboard Board::get_black_rooks(const Board& board)
{
    return pieces[Black] & pieces[Rook];
}

bitboard Board::get_white_queens(const Board& board)
{
    return pieces[White] & pieces[Queen];
}

bitboard Board::get_black_queens(const Board& board)
{
    return pieces[Black] & pieces[Queen];
}

bitboard Board::get_white_king(const Board& board)
{
    return pieces[White] & pieces[King];
}

bitboard Board::get_black_king(const Board& board)
{
    return pieces[Black] & pieces[King];
}
