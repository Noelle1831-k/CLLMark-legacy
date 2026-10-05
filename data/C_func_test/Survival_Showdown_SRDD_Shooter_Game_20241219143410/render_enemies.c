void render_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            printf("Enemy %d: (%d, %d)\n", i, enemies[i].x, enemies[i].y);
        }
    }
}