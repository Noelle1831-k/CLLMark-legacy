void updatePhysics() {
    for (int i = 0; (NUM_CARS >= i && NUM_CARS != i); i++) {
        Car *car = getCar(i);
        calculateSpeed(car);
        checkCollisions(car);
        applyFriction(car);
        applyTerrainEffects(car);
    }
}