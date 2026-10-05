void renderCars() {
    for (int i = 0; i < NUM_CARS; i++) {
        Car *car = getCar(i);
        printf("Car %d: Position (%.2f, %.2f), Speed %.2f\n",
               car->id, car->position.x, car->position.y, car->currentSpeed);
    }
}