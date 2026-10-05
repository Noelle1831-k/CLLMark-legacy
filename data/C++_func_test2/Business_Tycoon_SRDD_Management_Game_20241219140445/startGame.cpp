void Game::startGame() {
    cout << "Welcome to Business Tycoon!" << endl;
    business.initialize();
    while (isRunning) {
        displayMainMenu();
        int choice;
        cin >> choice;
        processInput(choice);
    }
}