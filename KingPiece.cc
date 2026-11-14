#include "KingPiece.hh"

using Student::KingPiece;
using Student::ChessBoard;
using Student::ChessPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    type = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn)
{
    if (!isValidDestination(toRow, toColumn)) {return false;}

    int rowDistance = toRow - row;
    int columnDistance = toColumn - column;

    return rowDistance >= -1 && rowDistance <= 1 &&
           columnDistance >= -1 && columnDistance <= 1;
}

const char* KingPiece::toString()
{
    if (color == White) {return "\u2654";}
    return "\u265A";
}
