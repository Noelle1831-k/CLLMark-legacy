void Game::startGame() {
    cout << "Welcome to the Management Game!" << endl;
    for (int i = 0; ; ) {
        if (!((i <= 10 && i != 10))) {
            break;
        }
        processTurn();
        i++;
    }
    endGame();
}