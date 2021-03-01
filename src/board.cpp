#include "board.h"
#include <string>
#include "util.h"
#include "defs.h"
#include <iostream>

Board::Board(std::string fen)
{
    position = Position();

    short unsigned int fen_index(0);
    short unsigned int loop_index(0);
    bool past_enpassant(false);

    for (char c : fen)
    {
        switch (c)
        {
            case 'p':
                position.pieces[Pawn] = position.pieces[Pawn] | (1ULL << fen_index);
                position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'n':
                position.pieces[Knight] = position.pieces[Knight] | (1ULL << fen_index);
                position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'b':
                if (fen_index < 64)
                {
                    position.pieces[Bishop] = position.pieces[Bishop] | (1ULL << fen_index);
                    position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
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
                    position.en_passant = (1ULL << 1);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
                    
                }
                
            case 'r':
                position.pieces[Rook] = position.pieces[Rook] | (1ULL << fen_index);
                position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'q':
                if (fen_index < 64)
                {
                    position.pieces[Queen] = position.pieces[Queen] | (1ULL << fen_index);
                    position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    position.castle_rights += BlackQueenCastle;
                    fen_index++;
                    continue;
                }
                
            case 'k':
                if (fen_index < 64)
                {
                    position.pieces[King] = position.pieces[King] | (1ULL << fen_index);
                    position.pieces[Black] = position.pieces[Black] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    position.castle_rights += BlackKingCastle;
                    fen_index++;
                    continue;
                }
                
            case 'P':
                position.pieces[Pawn] = position.pieces[Pawn] | (1ULL << fen_index);
                position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'N':
                
                position.pieces[Knight] = position.pieces[Knight] | (1ULL << fen_index);
                position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'B':
                position.pieces[Bishop] = position.pieces[Bishop] | (1ULL << fen_index);
                position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'R':
                
                position.pieces[Rook] = position.pieces[Rook] | (1ULL << fen_index);
                position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                fen_index++;
                continue;
            case 'Q':
                if (fen_index < 64)
                {
                    position.pieces[Queen] = position.pieces[Queen] | (1ULL << fen_index);
                    position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    position.castle_rights += WhiteQueenCastle;
                    fen_index++;
                    continue;
                }
            case 'K':
                if (fen_index < 64)
                {
                    position.pieces[King] = position.pieces[King] | (1ULL << fen_index);
                    position.pieces[White] = position.pieces[White] | (1ULL << fen_index);
                    fen_index++;
                    continue;
                }
                else
                {
                    position.castle_rights += WhiteKingCastle;
                    fen_index++;
                    continue;
                }
            case 'w':
                position.white_to_move = true;
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
                position.en_passant = (1);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'c':
                position.en_passant = (1ULL << 2);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'd':
                position.en_passant = (1ULL << 3);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'e':
                position.en_passant = (1ULL << 4);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'f':
                position.en_passant = (1ULL << 5);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'g':
                position.en_passant = (1ULL << 6);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }
            case 'h':
                position.en_passant = (1ULL << 7);
                    if (fen[loop_index + 1] == '3')
                    {
                        position.en_passant = position.en_passant << 40;
                    }
                    else
                    {
                        position.en_passant = position.en_passant << 16;
                    }

        }
        loop_index++;
    }
    for (int i = 0; i < PIECES_ARRAY_LENGTH; i++)
    {
        position.pieces[i] = flip_vertical(position.pieces[i]);
        position.pieces[i] = flip_horizontal(position.pieces[i]);
    }
    //might be faster to do a 180 rotation...
    position.en_passant = flip_vertical(position.en_passant);
    position.en_passant = flip_vertical(position.en_passant);
    position.occupied = position.pieces[White] | position.pieces[Black];
    position.empty = ~position.occupied;

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
    if (board.position.white_to_move)
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
    return position.pieces[White] & position.pieces[Pawn];
}

bitboard Board::get_black_pawns(const Board& board)
{
    return position.pieces[Black] & position.pieces[Pawn];
}
bitboard Board::get_white_knights(const Board& board)
{
    return position.pieces[White] & position.pieces[Knight];
}

bitboard Board::get_black_knights(const Board& board)
{
    return position.pieces[Black] & position.pieces[Knight];
}

bitboard Board::get_white_bishops(const Board& board)
{
    return position.pieces[White] & position.pieces[Bishop];
}

bitboard Board::get_black_bishops(const Board& board)
{
    return position.pieces[Black] & position.pieces[Bishop];
}

bitboard Board::get_white_rooks(const Board& board)
{
    return position.pieces[White] & position.pieces[Rook];
}

bitboard Board::get_black_rooks(const Board& board)
{
    return position.pieces[Black] & position.pieces[Rook];
}

bitboard Board::get_white_queens(const Board& board)
{
    return position.pieces[White] & position.pieces[Queen];
}

bitboard Board::get_black_queens(const Board& board)
{
    return position.pieces[Black] & position.pieces[Queen];
}

bitboard Board::get_white_king(const Board& board)
{
    return position.pieces[White] & position.pieces[King];
}

bitboard Board::get_black_king(const Board& board)
{
    return position.pieces[Black] & position.pieces[King];
}
