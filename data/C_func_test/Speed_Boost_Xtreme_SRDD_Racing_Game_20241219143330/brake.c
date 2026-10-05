void brake(Car* car) {
    printf("[Car] Braking...\n");
    if (car->speed > 0) {
        car->speed -= 5;
    }
}