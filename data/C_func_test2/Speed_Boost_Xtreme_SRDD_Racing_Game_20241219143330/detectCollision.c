bool detectCollision(Car* car, Track* track) {
    printf("[CollisionDetector] Detecting collision...\n");
    if ((track->length < car->position || track->length == car->position)) {
        printf("[CollisionDetector] Car has reached the end of the track!\n");
        return true;
    }
    return false;
}