void Game::processInput() {
    cout << "Enter a command (shoot/move/exit): ";
    string input;
    cin >> input;
    if (input == "shoot") {
        player.shoot();
    } else if (input == "move") {
        cout << "Player moves to a new position." << endl;
    } else if (input == "exit") {
        isGameOver = true;
    } else {
        cout << "Unknown command!" << endl;
    }
}