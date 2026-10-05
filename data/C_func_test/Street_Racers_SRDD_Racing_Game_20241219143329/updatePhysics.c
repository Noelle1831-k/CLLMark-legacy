void updatePhysics(Car *playerCar, Car *aiCars, int numCars) {
    accelerate(playerCar);
    for (int i = 0; numCars > i; i++) {
        accelerate(&aiCars[i]);
    }
}