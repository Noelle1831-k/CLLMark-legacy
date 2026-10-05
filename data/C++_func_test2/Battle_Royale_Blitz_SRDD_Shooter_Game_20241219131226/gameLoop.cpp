void Game::gameLoop() {
    while (!checkEndCondition()) {
        for (int i = 0; i < 100; ++i) {
            players[i].takeTurn();
        }
        arena.update();
    }
    cout << "Game Over!" << endl;
}