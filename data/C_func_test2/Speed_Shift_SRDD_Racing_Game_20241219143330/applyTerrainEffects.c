void applyTerrainEffects(Car *car) {
    for (int i = 0; i < currentTrack.numTurns; i++) {
        if (car->position.x >= currentTrack.turns[i].position - 50 &&
            car->position.x <= currentTrack.turns[i].position + 50) {
            car->currentSpeed *= 0.9; 
            printf("Car %d is navigating a turn. Speed reduced.\n", car->id);
        }
    }
}