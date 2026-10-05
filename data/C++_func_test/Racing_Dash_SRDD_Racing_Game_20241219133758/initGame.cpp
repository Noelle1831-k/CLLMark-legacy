void Game::initGame() {
    printf("Initializing game resources...\n");
    player = Player();
    aiCars = vector<AI>(5); 
    track = Track("City Streets");
    physicsEngine = PhysicsEngine();
    graphicsEngine = GraphicsEngine();
    inputHandler = InputHandler();
}