void brake() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].currentSpeed -= cars[i].deceleration;
        if (cars[i].currentSpeed < 0) {
            cars[i].currentSpeed = 0;
        }
    }
}