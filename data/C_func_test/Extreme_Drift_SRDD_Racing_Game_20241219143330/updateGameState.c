void updateGameState() {
    if (isOffTrack(&playerCar, &currentTrack)) {
        driftScore -= 50;  
        if (driftScore < 0) {
            driftScore = 0;  
        }
    }
    updatePhysics(&playerCar, &currentTrack);
    updateCarPosition(&playerCar);
    updateDriftScore(&driftScore, &playerCar);
}