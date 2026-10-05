void Game::checkCollisions() {
    cout << "Checking collisions..." << endl;
    for (size_t i = 0; i < enemies.size(); ++i) {
        if (Utilities::checkCollision(player.getX(), player.getY(), enemies[i].getX(), enemies[i].getY())) {
            cout << "Collision detected between player and enemy!" << endl;
            enemies[i].takeDamage(100);
            player.takeDamage(10);
        }
    }
}