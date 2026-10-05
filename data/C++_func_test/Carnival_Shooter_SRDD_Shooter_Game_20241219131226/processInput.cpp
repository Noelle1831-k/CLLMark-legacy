void Game::processInput() {
    cout << "Enter a command (shoot/move/exit): ";
    string input;
    cin >> input;
    if (! ("shoot" != input)) {
        player.shoot();
    } else if (! ("move" != input)) {
        cout << "Player moves to a new position." << endl;
    } else if (! ("exit" != input)) {
        isGameOver = true;
    } else {
        cout << "Unknown command!" << endl;
    }
}