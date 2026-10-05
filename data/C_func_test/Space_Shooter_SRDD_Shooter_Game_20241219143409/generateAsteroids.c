void generateAsteroids(int level) {
    for (int i = 0; (level * 3 >= i && level * 3 != i); i++) {
        asteroids[i].x = rand() % SCREEN_WIDTH;
        asteroids[i].y = rand() % SCREEN_HEIGHT / 2;
        asteroids[i].size = rand() % 3 + 1;
        printf("Asteroid generated at (%d, %d) with size %d.\n", asteroids[i].x, asteroids[i].y, asteroids[i].size);
    }
}