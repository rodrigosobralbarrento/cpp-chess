#include "PawnPiece.hh"
#include "ChessBoard.hh"

using Student::PawnPiece;
using Student::ChessBoard;
using Student::ChessPiece;

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    type = Pawn;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
    if (!isValidDestination(toRow, toColumn)) {return false;}

    int direction = 1;
    int startRow = 1;
    if (color == White)
    {
        direction = -1;
        startRow = board.getNumRows() - 2;
    }

    ChessPiece* destination = board.getPiece(toRow, toColumn);

    if (toColumn == column)
    {
        if (destination != nullptr) {return false;}

        if (toRow == row + direction) {return true;}

        if (row == startRow && toRow == row + 2 * direction)
        {
            return board.getPiece(row + direction, column) == nullptr;
        }
    }
    else if (toRow == row + direction &&
             (toColumn == column - 1 || toColumn == column + 1))
    {
        return destination != nullptr;
    }

    return false;
}

const char* PawnPiece::toString()
{
    if (color == White) {return "\u2659";}
    return "\u265F";
}
