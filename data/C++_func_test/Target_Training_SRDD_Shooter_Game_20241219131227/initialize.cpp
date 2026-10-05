void Game::initialize() {
    printf("Initializing game resources...\n");
    scoreManager->resetScore();
    target->spawnTarget();
}