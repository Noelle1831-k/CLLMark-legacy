void rotate(PuzzlePiece *piece) {
    piece->rotation = (piece->rotation + 90) % 360;
}