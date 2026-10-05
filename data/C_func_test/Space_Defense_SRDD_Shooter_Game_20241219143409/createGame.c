Game* createGame() {
    Game* game = (Game*)malloc(sizeof(Game));
    if (!game) return NULL;
    game->spaceship = createSpaceship();
    game->aliens = createAliens();
    game->bullets = createBullets();
    game->powerUps = createPowerUps();
    game->collisionManager = createCollisionManager();
    game->renderer = createRenderer();
    game->inputHandler = createInputHandler();
    game->upgradeSystem = createUpgradeSystem();
    game->isGameOver = false;
    return game;
}