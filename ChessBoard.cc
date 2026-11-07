#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;
using Student::PawnPiece;
using Student::RookPiece;
using Student::BishopPiece;

ChessBoard::ChessBoard(int numRow, int numCol)
{
    numRows = numRow;
    numCols = numCol;
    board = std::vector<std::vector<ChessPiece*>>(numRows,
            std::vector<ChessPiece*>(numCols, nullptr));
}

ChessBoard::~ChessBoard()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            delete board.at(row).at(column);
        }
    }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    if (startRow < 0 || startRow >= numRows || startColumn < 0 || startColumn >= numCols)
    {
        return;
    }

    ChessPiece* piece = nullptr;

    switch (ty)
    {
        case Pawn:
            piece = new PawnPiece(*this, col, startRow, startColumn);
            break;
        case Rook:
            piece = new RookPiece(*this, col, startRow, startColumn);
            break;
        case Bishop:
            piece = new BishopPiece(*this, col, startRow, startColumn);
            break;
        default:
            return;
    }

    delete board.at(startRow).at(startColumn);
    board.at(startRow).at(startColumn) = piece;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
    if (fromRow < 0 || fromRow >= numRows || fromColumn < 0 || fromColumn >= numCols ||
        toRow < 0 || toRow >= numRows || toColumn < 0 || toColumn >= numCols)
    {
        return false;
    }

    ChessPiece* piece = board.at(fromRow).at(fromColumn);
    if (piece == nullptr) {return false;}

    return piece->canMoveToLocation(toRow, toColumn);
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn)
{
    if (!isValidMove(fromRow, fromColumn, toRow, toColumn)) {return false;}

    ChessPiece* piece = board.at(fromRow).at(fromColumn);
    if (piece->getColor() != turn) {return false;}

    delete board.at(toRow).at(toColumn);
    board.at(toRow).at(toColumn) = piece;
    board.at(fromRow).at(fromColumn) = nullptr;
    piece->setPosition(toRow, toColumn);

    if (turn == White) {turn = Black;}
    else {turn = White;}

    return true;
}

bool ChessBoard::isPieceUnderThreat(int row, int column)
{
    if (row < 0 || row >= numRows || column < 0 || column >= numCols) {return false;}

    ChessPiece* piece = board.at(row).at(column);
    if (piece == nullptr) {return false;}

    for (int currRow = 0; currRow < numRows; currRow++)
    {
        for (int currColumn = 0; currColumn < numCols; currColumn++)
        {
            ChessPiece* opponent = board.at(currRow).at(currColumn);
            if (opponent != nullptr && opponent->getColor() != piece->getColor() &&
                opponent->canMoveToLocation(row, column))
            {
                return true;
            }
        }
    }

    return false;
}

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++){
        outputString << i << " ";
    }
    outputString << std::endl << "  ";
    // top border
    for (int i = 0; i < numCols; i++){
        outputString << "– ";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++){
        outputString << row << "|";
        for (int column = 0; column < numCols; column++){
            ChessPiece* piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString()) << " ";
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++){
        outputString << "– ";
    }
    outputString << std::endl << std::endl;

    return outputString;
}
