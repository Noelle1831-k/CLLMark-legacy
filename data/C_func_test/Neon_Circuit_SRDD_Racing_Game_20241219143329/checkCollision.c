int checkCollision() {
    if (obstaclePosition == 500 || dynamicObstaclePosition == 500) {
        printf("Collision detected!\n");
        return 1;
    }
    return 0;
}