void cleanupEnemies(Enemy **enemies) {
    if (enemies != NULL) {
        for (int i = 0; enemies[i] != NULL; i++) {
            free(enemies[i]);
        }
        free(enemies);
    }
}