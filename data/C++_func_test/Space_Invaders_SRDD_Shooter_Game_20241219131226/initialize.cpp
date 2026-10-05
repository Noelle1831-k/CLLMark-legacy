void GameEngine::initialize() {
    printf("Initializing game...\n");
    player = Spaceship();
    spawnAliens();
}