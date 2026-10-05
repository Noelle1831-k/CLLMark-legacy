void moveAsteroids() {
    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        asteroids[i].y += asteroids[i].size;
        if (asteroids[i].y > SCREEN_HEIGHT) asteroids[i].y = 0;
    }
}