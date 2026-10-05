int checkHit() {
    int playerShot = generateRandom(0, 100);
    printf("Player shot at position: %d\n", playerShot);
    return abs(playerShot - targetPosition) < 10;
}