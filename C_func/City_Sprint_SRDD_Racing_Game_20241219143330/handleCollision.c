void handleCollision(Car* car) {
    car->speed *= 0.5;
    printf("Collision detected. Car speed reduced to %.2f.\n", car->speed);
}