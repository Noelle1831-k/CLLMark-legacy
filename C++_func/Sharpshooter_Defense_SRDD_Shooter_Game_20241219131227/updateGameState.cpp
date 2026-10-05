void Game::updateGameState() {
    cout << "Updating game state..." << endl;
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].getHealth() <= 0) {
            cout << "Enemy " << i << " is dead!" << endl;
            enemies.erase(enemies.begin() + i);
            i--; 
        }
    }
}