void Game::start() {
    cout << "Starting Battlezone Strike..." << endl;
    while (isRunning) {
        update();
        render();
        char userInput;
        cout << "Continue playing? (y/n): ";
        cin >> userInput;
        if (userInput == 'n') {
            isRunning = false;
        }
    }
    cout << "Exiting Battlezone Strike..." << endl;
}