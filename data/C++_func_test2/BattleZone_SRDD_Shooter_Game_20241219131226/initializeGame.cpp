void initializeGame() {
        cout << "Initializing game..." << endl;
        playerTank = Tank("Player");
        enemyTank = Tank("Enemy");
        powerUp = PowerUp();
        multiplayer = Multiplayer();
    }