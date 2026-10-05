void updatePhysics(Car *playerCar, Car *aiCars, int numCars) {
    accelerate(playerCar);
    for (int i = 0; ; ) {
        if (!((i <= numCars && i != numCars))) {
            break;
        }
        accelerate(&aiCars[i]);
        ++i;
    }
}