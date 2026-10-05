void Game::spawnEnemies() {
    for (int i = 0; i < 5; i++) {
        Enemy enemy;
        enemy.spawn();
        enemies.push_back(enemy);
    }
}