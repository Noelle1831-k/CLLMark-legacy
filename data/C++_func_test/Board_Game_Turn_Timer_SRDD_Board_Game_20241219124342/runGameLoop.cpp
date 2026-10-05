void runGameLoop(PlayerManager &playerManager, GameTimer &gameTimer, Display &display) {
    while (true) {
        string currentPlayer = playerManager.getCurrentPlayer();
        display.showCurrentPlayer(currentPlayer);
        gameTimer.startTimer();
        while (!gameTimer.isTimeUp()) {
            display.showTimer(gameTimer.getRemainingTime());
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Time's up for " << currentPlayer << "!" << endl;
        playerManager.nextPlayer();
    }
}