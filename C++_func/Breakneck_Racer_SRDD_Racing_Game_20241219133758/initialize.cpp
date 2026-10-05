void GameEngine::initialize() {
    cout << "Initializing game engine..." << endl;
    graphicsEngine.loadTextures();
    cars.push_back(Car("Speedster", 3.5, 2.0));
    cars.push_back(Car("Thunderbolt", 4.0, 1.8));
    cars.push_back(Car("Roadster", 3.0, 2.5));
    player.selectCar(cars[0]);
    track.generateObstacles();
}