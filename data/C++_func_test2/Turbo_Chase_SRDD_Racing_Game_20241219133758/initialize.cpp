void Game::initialize() {
    cout << "Initializing game..." << endl;
    srand(time(0)); 
    player.chooseVehicle();
    city.generateMap();
    spawnPolice();
    spawnPowerUps();
}