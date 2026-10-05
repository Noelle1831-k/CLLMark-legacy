void GameEngine::updateGameState() {
    playerCar.accelerate();
    playerCar.applyBoost();
    if (playerCar.getSpeed() > 200) {
        isGameRunning = false;
    }
}