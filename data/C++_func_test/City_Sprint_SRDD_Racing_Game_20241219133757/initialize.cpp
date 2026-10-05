void Game::initialize() {
    playerCar = Car("Player", 0, 0, 0);
    aiCars.push_back(Car("AI_1", 10, 0, 0));
    aiCars.push_back(Car("AI_2", 20, 0, 0));
    raceTrack = Track();
    raceTrack.addObstacle(15, 15); 
    raceTrack.addObstacle(30, 30);
    physics = PhysicsEngine();
    graphics = GraphicsEngine();
    input = InputHandler();
    ai = AIController();
    isRunning = true;
}