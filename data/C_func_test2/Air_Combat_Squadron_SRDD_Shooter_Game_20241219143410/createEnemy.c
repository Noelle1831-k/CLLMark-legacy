Enemy* createEnemy() {
    Enemy *enemy = (Enemy*)malloc(sizeof(Enemy));
    if (!enemy) return NULL;
    enemy->speed = 8;
    enemy->health = 50;
    enemy->x = rand() % 100;
    enemy->y = rand() % 100;
    enemy->weapons = createWeapon();
    return enemy;
}