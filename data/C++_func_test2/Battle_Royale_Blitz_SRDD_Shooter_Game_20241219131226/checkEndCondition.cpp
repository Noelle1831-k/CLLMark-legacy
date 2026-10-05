bool Game::checkEndCondition() {
    int activePlayers = 0;
    for (int i = 0; i < 100; ++i) {
        if (players[i].isAlive()) {
            activePlayers++;
        }
    }
    return activePlayers <= 1;
}