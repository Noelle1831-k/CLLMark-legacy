void Game::processInput() {
    if (_kbhit()) {
        char input = _getch();
        switch (input) {
            case 'w': player.move(0, -1); break;
            case 's': player.move(0, 1); break;
            case 'a': player.move(-1, 0); break;
            case 'd': player.move(1, 0); break;
            case ' ': player.shoot(); break;
        }
    }
}