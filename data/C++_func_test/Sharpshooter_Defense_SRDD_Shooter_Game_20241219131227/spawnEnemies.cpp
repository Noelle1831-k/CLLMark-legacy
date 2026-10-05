void Game::spawnEnemies() {
    cout << "Spawning enemies..." << endl;
    int enemyCount = Utilities::getRandomNumber(1, 5);
    for (int i = 0; i < enemyCount; ++i) {
        Enemy newEnemy;
        enemies.push_back(newEnemy);
    }
}