Enemy* createEnemy(int x, int y) {
    Enemy *enemy = (Enemy*)malloc(sizeof(Enemy));
    if (enemy != NULL) {
        enemy->health = 50;
        enemy->position.x = x;
        enemy->position.y = y;
    }
    return enemy;
}