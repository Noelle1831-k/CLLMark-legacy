void Puzzle::displayPuzzle() {
    std::cout << "\n--- Puzzle ---" << std::endl;
    for (const auto& row : puzzleData) {
        std::cout << row << std::endl;
    }
}