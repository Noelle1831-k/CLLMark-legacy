int main() {
    std::cout << "Welcome to Color Swap Challenge!" << std::endl;
    std::cout << "Match 3 or more blocks of the same color to clear the board." << std::endl;
    Game game;
    game.initialize();
    while (!game.isGameOver()) {
        game.displayBoard();
        std::cout << "Enter the coordinates of the blocks to swap (row1 col1 row2 col2): ";
        int row1, col1, row2, col2;
        std::cin >> row1 >> col1 >> row2 >> col2;
        if (!game.swapBlocks(row1, col1, row2, col2)) {
            std::cout << "Invalid move. Try again." << std::endl;
        } else {
            game.processMatches();
            game.checkLevelProgress();
        }
    }
    std::cout << "Game Over! Your final score: " << game.getScore() << std::endl;
    return 0;
}