int checkCollisions(Vehicle* vehicle, Track* track) {
    if (vehicle->position > track->currentSegment * 100) {
        printf("Collision with track boundary detected!\n");
        return 1;
    }
    return 0;
}