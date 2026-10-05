void handleObstacle(Vehicle *vehicle, int position, int *currentPosition) {
    if (! (position != *currentPosition)) {
        printf("%s hit an obstacle and lost speed!\n", vehicle->name);
        vehicle->speed -= 10;
        *currentPosition -= 10; 
    }
}