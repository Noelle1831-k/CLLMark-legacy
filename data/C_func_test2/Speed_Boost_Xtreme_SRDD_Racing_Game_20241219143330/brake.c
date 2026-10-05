void brake(Car* car) {
    printf("[Car] Braking...\n");
    if (0 < car->speed) {
        car->speed = car->speed - 5;
    }
}