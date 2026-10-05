void GameEngine::update() {
    player.handleInput();
    playerVehicle.updatePosition();
    for (auto &aiVehicle : aiVehicles) {
        aiController.updateAI(aiVehicle, raceTrack);
    }
    physics.detectCollision(playerVehicle, raceTrack);
    checkPowerUpCollision();
    player.updateScore();
    if (raceTrack.checkLapCompletion(playerVehicle)) {
        currentLap++;
        if (currentLap >= totalLaps) {
            isRunning = false;
        }
    }
}