#include "ChessPiece.hh"
#include "ChessBoard.hh"

using Student::ChessPiece;
using Student::ChessBoard;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
    : board(board), color(color), type(Pawn), row(row), column(column)
{
}

Color ChessPiece::getColor()
{
    return color;
}

Type ChessPiece::getType()
{
    return type;
}

int ChessPiece::getRow()
{
    return row;
}

int ChessPiece::getColumn()
{
    return column;
}

void ChessPiece::setPosition(int row, int column)
{
    this->row = row;
    this->column = column;
}

bool ChessPiece::isValidDestination(int toRow, int toColumn)
{
    if (toRow < 0 || toRow >= board.getNumRows() ||
        toColumn < 0 || toColumn >= board.getNumCols())
    {
        return false;
    }

    if (toRow == row && toColumn == column) {return false;}

    ChessPiece* destination = board.getPiece(toRow, toColumn);
    if (destination != nullptr && destination->getColor() == color) {return false;}

    return true;
}
