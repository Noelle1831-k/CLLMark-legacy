void Game::handleInput() {
    char input;
    std::cin >> input;
    switch (input) {
        case 'a':
            blaster.moveLeft();
            break;
        case 'd':
            blaster.moveRight();
            break;
        case ' ':
            blaster.shoot();
            break;
        case 'q':
            isRunning = false;
            break;
    }
}