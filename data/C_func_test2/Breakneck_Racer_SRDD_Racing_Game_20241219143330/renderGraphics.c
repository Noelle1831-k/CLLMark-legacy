void renderGraphics(Car *car, Track *track) {
    printf("Rendering car at position: %.2f\n", car->position);
    printf("Car speed: %.2f | Car acceleration: %.2f\n", car->speed, car->acceleration);
    printf("Track length: %d | Obstacles: %d | Turns: %d\n", track->length, track->obstacles, track->turns);
}