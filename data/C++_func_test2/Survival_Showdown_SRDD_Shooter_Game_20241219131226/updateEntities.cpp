void Game::updateEntities() {
    for (size_t i = 0; i < enemies.size(); ++i) {
        enemies[i].move();
    }
    arena.shrink();
    score.update();
}