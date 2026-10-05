void Game::run() {
    cout << "Running game..." << endl;
    bool isRunning = true;
    while (isRunning) {
        inputHandler.processInput();
        player.updateStatus();
        city.updateTraffic();
        for (size_t i = 0; i < policeUnits.size(); i++) {
            policeUnits[i].chasePlayer(player);
        }
        for (size_t i = 0; i < powerUps.size(); i++) {
            powerUps[i].activate(player);
        }
        checkCollisions();
        graphics.renderScene();
        if (checkWinCondition()) {
            cout << "You won the race!" << endl;
            isRunning = false;
        }
        if (checkLoseCondition()) {
            cout << "You were caught by the police!" << endl;
            isRunning = false;
        }
    }
}