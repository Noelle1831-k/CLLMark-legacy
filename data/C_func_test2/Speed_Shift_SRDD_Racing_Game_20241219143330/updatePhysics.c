void updatePhysics() {
    for (int i = 0; i < NUM_CARS; i++) {
        Car *car = getCar(i);
        calculateSpeed(car);
        checkCollisions(car);
        applyFriction(car);
        applyTerrainEffects(car);
    }
}