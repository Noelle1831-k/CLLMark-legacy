void GameEngine::handleGameOver() {
    cout << "Game Over! Your final score: " << scoreManager.getFinalScore() << endl;
    cout << "Press 'q' to quit." << endl;
    if (_kbhit() && _getch() == 'q') {
        running = false;
    }
}