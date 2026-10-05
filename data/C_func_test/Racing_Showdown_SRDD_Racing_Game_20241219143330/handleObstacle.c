void handleObstacle(Vehicle *vehicle, int position, int *currentPosition) {
    if (*currentPosition == position) {
        printf("%s hit an obstacle and lost speed!\n", vehicle->name);
        vehicle->speed = vehicle->speed - 10;
        *currentPosition = *currentPosition - 10; 
    }
}