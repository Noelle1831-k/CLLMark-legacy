void updateGameState() {
        cout << "Updating game state..." << endl;
        playerTank.move();
        enemyTank.move();
        if (checkCollision(playerTank.getPosition(), enemyTank.getPosition())) {
            playerTank.takeDamage(10);
            enemyTank.takeDamage(10);
            score -= 5; 
        }
        if (checkCollision(playerTank.getPosition(), powerUp.getPosition())) {
            powerUp.applyEffect(playerTank);
            score += 10; 
            powerUpCooldown = 10; 
        }
        if (powerUpCooldown > 0) {
            powerUpCooldown--;
        } else {
            powerUp.respawn();
        }
        multiplayer.syncGameState();
    }