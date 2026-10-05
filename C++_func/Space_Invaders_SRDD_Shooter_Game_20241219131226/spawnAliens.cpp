void GameEngine::spawnAliens() {
    for (int i = 0; i < level * 5; ++i) {
        aliens.push_back(Alien());
    }
}