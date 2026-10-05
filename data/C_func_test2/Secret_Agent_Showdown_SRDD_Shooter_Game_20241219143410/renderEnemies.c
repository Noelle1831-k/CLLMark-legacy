void renderEnemies(Enemy **enemies) {
    for (int i = 0; enemies[i] != NULL; ++i) {
        drawEnemy(enemies[i]->position);
    }
}