void accelerate() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].currentSpeed += cars[i].acceleration;
    }
}