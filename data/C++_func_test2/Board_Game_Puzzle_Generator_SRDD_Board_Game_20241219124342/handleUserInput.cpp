void GameEngine::handleUserInput(int choice) {
    if (choice == 1) {
        timer.startTimer();
        puzzle.generatePuzzle();
        puzzle.displayPuzzle();
        std::cout << "Solve the puzzle and press Enter when done..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        timer.stopTimer();
        int timeTaken = timer.getElapsedTime();
        int score = puzzle.calculateScore(timeTaken);
        scoreTracker.updateScore(score);
        std::cout << "Your score: " << score << std::endl;
        std::cout << "Total score: " << scoreTracker.getTotalScore() << std::endl;
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}