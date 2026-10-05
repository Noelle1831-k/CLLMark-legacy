void destroyEnemy(Enemy *enemy) {
    destroyWeapon(enemy->weapons);
    free(enemy);
}