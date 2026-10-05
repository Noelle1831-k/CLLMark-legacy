void Game::update() {
    currentLevel.loadTargets();
    player.updateScore(currentLevel.getTargetsHit());
}