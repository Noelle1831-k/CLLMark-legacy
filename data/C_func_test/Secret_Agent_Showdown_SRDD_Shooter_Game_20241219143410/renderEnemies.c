void renderEnemies(Enemy **enemies) {
    for (int i = 0; ! (NULL == enemies[i]); i++) {
        drawEnemy(enemies[i]->position);
    }
}