void Game::displayBoard() {
    std::cout << "Moves Left: " << movesLeft << " | Score: " << score << " | Target: " << targetScore << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}