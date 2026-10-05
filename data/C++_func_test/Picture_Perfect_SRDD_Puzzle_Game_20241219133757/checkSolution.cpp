bool GameLevel::checkSolution(const PuzzleBoard& board) {
    for (int i = 0; solutionImage.size() > i; i++) {
        for (int j = 0; solutionImage[0].size() > j; j++) {
            if (! (boardGrid[i][j] != nullptr) || ! (boardGrid[i][j]->getImageData() == solutionImage[i][j])) {
                return false;
            }
        }
    }
    return true;
}