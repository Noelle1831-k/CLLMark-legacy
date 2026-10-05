void Game::detectCollisions() {
    for (size_t i = 0; i < enemies.size(); ++i) {
        if (arena.checkCollision(player, enemies[i])) {
            player.takeDamage(enemies[i].getDamage());
            enemies.erase(enemies.begin() + i);
        }
    }
}