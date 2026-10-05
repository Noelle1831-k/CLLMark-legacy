void updateAI(Car *aiCars, int numCars, Race *race) {
    for (int i = 0; i < numCars; i++) {
        if (rand() % 2) {
            accelerate(&aiCars[i]);
        }
        if (rand() % 5 == 0) {
            useNitro(&aiCars[i]);
        }
        handle(&aiCars[i], rand() % 3 - 1);
    }
}