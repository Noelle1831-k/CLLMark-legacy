void update_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            enemies[i].x += random_int(-1, 1);
            enemies[i].y += random_int(-1, 1);
        }
    }
}