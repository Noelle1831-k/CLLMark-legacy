void Game::update() {
    player.move();
    for (size_t i = 0; i < monsters.size(); i++) {
        if (!monsters[i].isDefeated()) {
            monsters[i].attack();
        }
    }
    world.explore();
}