void Game::handleInput() {
    char input;
    cout << "Enter command (r: rotate, m: move): ";
    cin >> input;
    if (input == 'r') {
        blocks[0].rotate();
    } else if (input == 'm') {
        blocks[0].move();
    }
}