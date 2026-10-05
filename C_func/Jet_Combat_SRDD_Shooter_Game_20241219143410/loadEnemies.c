void loadEnemies() {
    printf("Loading Enemies...\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        snprintf(enemies[i].type, sizeof(enemies[i].type), "Enemy%d", i + 1);
        enemies[i].health = 50 + (rand() % 51);
        enemies[i].damage = 10 + (rand() % 21);
        enemies[i].x = rand() % 50;
        enemies[i].y = rand() % 20;
    }
}