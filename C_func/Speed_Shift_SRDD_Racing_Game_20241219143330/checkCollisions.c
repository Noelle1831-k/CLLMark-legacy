void checkCollisions(Car *car) {
    if (car->position.x < 0 || car->position.x > TRACK_WIDTH ||
        car->position.y < 0 || car->position.y > TRACK_HEIGHT) {
        car->currentSpeed = 0; 
        printf("Collision detected for car %d!\n", car->id);
    }
}