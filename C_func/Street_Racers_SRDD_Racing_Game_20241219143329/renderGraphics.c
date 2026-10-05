void renderGraphics(Car *playerCar, Car *aiCars, int numCars, Race *race) {
    printf("Rendering race on track: %s\n", race->trackName);
    printf("Player Car: %s, Speed: %d\n", playerCar->name, playerCar->speed);
    for (int i = 0; i < numCars; i++) {
        printf("AI Car %d: %s, Speed: %d\n", i + 1, aiCars[i].name, aiCars[i].speed);
    }
}