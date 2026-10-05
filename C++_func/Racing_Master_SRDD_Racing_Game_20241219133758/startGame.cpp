void startGame() {
        cout << "Starting the game..." << endl;
        for (int i = 0; i < races.size(); i++) {
            cout << "Race " << i + 1 << " begins!" << endl;
            races[i].simulateRace(teams);
        }
        endGame();
    }