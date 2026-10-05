void updatePhysics(Car *playerCar, Car *aiCars, int numCars) {
    accelerate(playerCar);
    for (int i = 0; i < numCars; i++) {
        accelerate(&aiCars[i]);
    }
}