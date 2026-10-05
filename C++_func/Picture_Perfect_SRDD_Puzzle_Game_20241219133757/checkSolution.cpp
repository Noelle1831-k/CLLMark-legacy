bool GameLevel::checkSolution(const PuzzleBoard& board) {
    for (int i = 0; i < solutionImage.size(); i++) {
        for (int j = 0; j < solutionImage[0].size(); j++) {
            if (boardGrid[i][j] == nullptr || boardGrid[i][j]->getImageData() != solutionImage[i][j]) {
                return false;
            }
        }
    }
    return true;
}