void GameEngine::initialize() {
    cout << "Initializing game..." << endl;
    player = Spaceship();
    spawnAliens();
}