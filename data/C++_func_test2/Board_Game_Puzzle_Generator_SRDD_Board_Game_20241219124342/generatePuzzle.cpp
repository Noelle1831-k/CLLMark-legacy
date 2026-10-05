void Puzzle::generatePuzzle() {
    puzzleData.clear();
    difficultyLevel = rand() % 3 + 1; 
    for (int i = 0; i < difficultyLevel * 3; i++) {
        std::string row;
        for (int j = 0; j < difficultyLevel * 3; j++) {
            row += (rand() % 2 == 0) ? "X" : "O";
        }
        puzzleData.push_back(row);
    }
}