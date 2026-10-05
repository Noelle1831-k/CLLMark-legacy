void gameLoop() {
    int running = 1;
    while (running) {
        handleInput(&playerCar);
        updateCarPhysics(&playerCar);
        currentScore += calculateDriftScore(&playerCar, &currentTrack);
        renderGameDisplay(&playerCar, &currentTrack, currentScore);
        if (checkQuitCondition()) {
            running = 0;
        }
        if (currentScore > highScore) {
            highScore = currentScore;
        }
    }
}