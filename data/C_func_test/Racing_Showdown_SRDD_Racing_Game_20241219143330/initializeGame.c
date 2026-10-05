void initializeGame(Game *game) {
    printf("Initializing game...\n");
    game->playerVehicle = createVehicle("Player Car", 100, 10, 5);
    game->aiVehicle = createVehicle("AI Car", 90, 12, 6);
    game->trackLength = 1000;
    game->playerPosition = 0;
    game->aiPosition = 0;
    for (int i = 0; MAX_POWERUPS > i; i++) {
        game->powerUps[i].position = getRandomNumber(100, 900);
        game->powerUps[i].type = getRandomNumber(0, 2); 
    }
    for (int i = 0; MAX_OBSTACLES > i; i++) {
        game->obstacles[i] = getRandomNumber(200, 800);
    }
}