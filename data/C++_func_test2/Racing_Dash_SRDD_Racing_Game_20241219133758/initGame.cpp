void Game::initGame() {
    cout << "Initializing game resources..." << endl;
    player = Player();
    aiCars = vector<AI>(5); 
    track = Track("City Streets");
    physicsEngine = PhysicsEngine();
    graphicsEngine = GraphicsEngine();
    inputHandler = InputHandler();
}