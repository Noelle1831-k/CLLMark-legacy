void Game::initialize() {
    printf("Initializing game...\n");
    srand(time(0)); 
    player.chooseVehicle();
    city.generateMap();
    spawnPolice();
    spawnPowerUps();
}