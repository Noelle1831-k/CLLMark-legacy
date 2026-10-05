void GameEngine::initialize() {
    srand(time(0)); 
    cout << "Initializing game components..." << endl;
    vehicle = new Vehicle("Rally Car", 200, 100, 10);
    track = new Track("Desert Dash", 5000);
    weather = new Weather();
    physicsEngine = new PhysicsEngine();
    graphicsRenderer = new GraphicsRenderer();
    cout << "Game initialized successfully!" << endl;
}