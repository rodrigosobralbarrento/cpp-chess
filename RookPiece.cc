#include "RookPiece.hh"
#include "ChessBoard.hh"

using Student::RookPiece;
using Student::ChessBoard;
using Student::ChessPiece;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    type = Rook;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    if (!isValidDestination(toRow, toColumn)) {return false;}

    if (toRow != row && toColumn != column) {return false;}

    int rowStep = 0;
    int columnStep = 0;
    if (toRow > row) {rowStep = 1;}
    else if (toRow < row) {rowStep = -1;}
    if (toColumn > column) {columnStep = 1;}
    else if (toColumn < column) {columnStep = -1;}

    int currRow = row + rowStep;
    int currColumn = column + columnStep;

    while (currRow != toRow || currColumn != toColumn)
    {
        if (board.getPiece(currRow, currColumn) != nullptr) {return false;}
        currRow += rowStep;
        currColumn += columnStep;
    }

    return true;
}

const char* RookPiece::toString()
{
    if (color == White) {return "\u2656";}
    return "\u265C";
}
