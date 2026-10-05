void Game::handleInput() {
    char input;
    cout << "Press q to quit, c to customize, x to explore, or any other key to continue: ";
    cin >> input;
    switch (input) {
        case 'q':
            gameRunning = false;
            break;
        case 'c':
            player.customize();
            break;
        case 'x':
            world.unlockArea();
            break;
        default:
            cout << "Continuing the game..." << endl;
            break;
    }
}