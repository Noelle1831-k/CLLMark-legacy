void spawnAliens(int level) {
    for (int i = 0; i < level * 5; i++) {
        aliens[i].x = rand() % SCREEN_WIDTH;
        aliens[i].y = rand() % SCREEN_HEIGHT / 2;
        aliens[i].health = level * 10;
        printf("Alien spawned at (%d, %d) with health %d.\n", aliens[i].x, aliens[i].y, aliens[i].health);
    }
}