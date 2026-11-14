# C++ Chess

A simple chess project written in C++17, using inheritance and virtual methods to define how each piece moves.

## Features

- Pawn, rook, bishop, and king movement
- Configurable board dimensions
- Move validation, blocked paths, and captures
- Alternating turns, with White moving first
- Detection of pieces under attack
- Rejection of moves that leave your king in check

## Build and run

Requires a C++17 compiler and Make.

```sh
make custom_tests
./chess
```

On Windows with MinGW:

```powershell
mingw32-make custom_tests
.\chess.exe
```

The current `main.cc` creates a sample board and exits. The `ChessBoard` class provides methods to create pieces, validate and execute moves, and check whether a piece is under attack.

The project uses simplified rules without castling, en passant, or pawn promotion.
