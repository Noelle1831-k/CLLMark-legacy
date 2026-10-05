void renderGame() {
        cout << "Rendering game..." << endl;
        playerTank.render();
        enemyTank.render();
        powerUp.render();
        cout << "Score: " << score << endl;
    }