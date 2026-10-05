void Game::SpawnEnemies(int count) {
    cout << "Spawning " << count << " enemies..." << endl;
    for (int i = 0; i < count; i++) {
        Enemy enemy;
        enemies.push_back(enemy);
    }
}