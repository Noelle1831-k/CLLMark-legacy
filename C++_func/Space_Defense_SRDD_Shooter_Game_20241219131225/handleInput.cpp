void Game::handleInput() {
    char input;
    cout << "Enter command (w/a/s/d to move, q to quit): ";
    cin >> input;
    switch (input) {
        case 'w': player.moveUp(); break;
        case 'a': player.moveLeft(); break;
        case 's': player.moveDown(); break;
        case 'd': player.moveRight(); break;
        case 'q': isRunning = false; break;
        default: cout << "Invalid input!" << endl; break;
    }
}