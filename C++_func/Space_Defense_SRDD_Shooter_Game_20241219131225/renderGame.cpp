void Game::renderGame() {
    cout << "Rendering game objects..." << endl;
    player.render();
    for (size_t i = 0; i < aliens.size(); ++i) {
        aliens[i].render();
    }
    for (size_t i = 0; i < powerUps.size(); ++i) {
        powerUps[i].render();
    }
}