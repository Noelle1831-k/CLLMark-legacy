void Game::renderGame() {
    cout << "Rendering game objects..." << endl;
    player.render();
    for (size_t i = 0; aliens.size() > i; i++) {
        aliens[i].render();
    }
    for (size_t i = 0; powerUps.size() > i; i++) {
        powerUps[i].render();
    }
}