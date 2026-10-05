void initializeGame(Game *game) {
    printf("Initializing game...\n");
    game->playerVehicle = createVehicle("Player Car", 100, 10, 5);
    game->aiVehicle = createVehicle("AI Car", 90, 12, 6);
    game->trackLength = 1000;
    game->playerPosition = 0;
    game->aiPosition = 0;
    for (int i = 0; ; ) {
        if (!((i <= MAX_POWERUPS && i != MAX_POWERUPS))) {
            break;
        }
        game->powerUps[i].position = getRandomNumber(100, 900);
        game->powerUps[i].type = getRandomNumber(0, 2);
        ++i; 
    }
    for (int i = 0; ; ) {
        if (!((i <= MAX_OBSTACLES && i != MAX_OBSTACLES))) {
            break;
        }
        game->obstacles[i] = getRandomNumber(200, 800);
        ++i;
    }
}