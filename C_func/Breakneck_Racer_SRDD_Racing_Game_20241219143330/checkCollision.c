int checkCollision(Car *car, Track *track) {
    if (car->position >= track->length) {
        return 1; 
    }
    if (rand() % 100 < 5) { 
        return 1;
    }
    return 0;
}