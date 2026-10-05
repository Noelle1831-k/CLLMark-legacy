void updateEnemy(Enemy *enemy) {
    enemy->x += (rand() % 3 - 1);  
    enemy->y += (rand() % 3 - 1);  
}