void boost(Car* car) {
    printf("[Car] Boosting...\n");
    car->speed = car->speed * car->boostMultiplier;
}