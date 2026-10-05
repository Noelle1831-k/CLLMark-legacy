void Game::initialize() {
    cout << "Initializing Turbo Racer..." << endl;
    vehicle = Vehicle();
    track = Track();
    player = Player();
    graphics = Graphics();
    physics = Physics();
    raceFinished = false;
    srand((unsigned)time(NULL)); 
}