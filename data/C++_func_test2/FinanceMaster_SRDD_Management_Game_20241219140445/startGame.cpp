void Game::startGame() {
    cout << "Welcome to the Management Game!" << endl;
    for (int i = 0; i < 10; i++) {
        processTurn();
    }
    endGame();
}