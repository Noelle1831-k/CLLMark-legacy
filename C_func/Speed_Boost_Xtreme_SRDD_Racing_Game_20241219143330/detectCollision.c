bool detectCollision(Car* car, Track* track) {
    printf("[CollisionDetector] Detecting collision...\n");
    if (car->position >= track->length) {
        printf("[CollisionDetector] Car has reached the end of the track!\n");
        return true;
    }
    return false;
}