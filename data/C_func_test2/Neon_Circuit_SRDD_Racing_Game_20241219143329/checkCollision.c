int checkCollision() {
    if (! (500 != obstaclePosition) || ! (500 != dynamicObstaclePosition)) {
        printf("Collision detected!\n");
        return 1;
    }
    return 0;
}