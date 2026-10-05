void GameLevel::loadLevel() {
    vector<vector<int>> pieceData = {{1, 2}, {3, 4}};
    for (int i = 0; i < 4; i++) {
        puzzlePieces.push_back(PuzzlePiece(i, pieceData));
    }
    random_shuffle(puzzlePieces.begin(), puzzlePieces.end());
    solutionImage = {{1, 2, 1, 2}, {3, 4, 3, 4}, {1, 2, 1, 2}, {3, 4, 3, 4}};
}