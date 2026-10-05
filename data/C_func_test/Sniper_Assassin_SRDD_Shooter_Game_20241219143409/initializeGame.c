void initializeGame(Game *game) {
    game->isRunning = 1;
    game->score = 0;
    game->timeLimit = 300; 
    game->currentMission = 0;
    initializePlayer();
    initializeRifles();
    initializeMissions();
}