void updateAI(Enemy **enemies, Player *player) {
    for (int i = 0; enemies[i] != NULL; i++) {
        updateEnemy(enemies[i], player);
    }
}