void Mission::spawnEnemies(int count) {
    for (int i = 0; i < count; i++) {
        enemies.push_back(Enemy());
    }
}