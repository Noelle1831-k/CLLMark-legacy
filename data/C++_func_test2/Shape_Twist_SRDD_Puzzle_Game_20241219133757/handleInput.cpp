void Game::handleInput() {
    char userChoice;
    cout << "Do you want to continue playing? (y/n): ";
    cin >> userChoice;
    if (userChoice == 'n' || userChoice == 'N') {
        isRunning = false;
    }
}