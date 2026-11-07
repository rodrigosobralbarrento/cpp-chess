#include "BishopPiece.hh"
#include "ChessBoard.hh"

using Student::BishopPiece;
using Student::ChessBoard;
using Student::ChessPiece;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    type = Bishop;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    if (!isValidDestination(toRow, toColumn)) {return false;}

    int rowDistance = toRow - row;
    int columnDistance = toColumn - column;
    if (rowDistance < 0) {rowDistance = -rowDistance;}
    if (columnDistance < 0) {columnDistance = -columnDistance;}

    if (rowDistance != columnDistance) {return false;}

    int rowStep = 1;
    int columnStep = 1;
    if (toRow < row) {rowStep = -1;}
    if (toColumn < column) {columnStep = -1;}

    int currRow = row + rowStep;
    int currColumn = column + columnStep;

    while (currRow != toRow)
    {
        if (board.getPiece(currRow, currColumn) != nullptr) {return false;}
        currRow += rowStep;
        currColumn += columnStep;
    }

    return true;
}

const char* BishopPiece::toString()
{
    if (color == White) {return "\u2657";}
    return "\u265D";
}
