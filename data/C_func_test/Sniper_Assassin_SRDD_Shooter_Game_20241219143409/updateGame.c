void updateGame(Game *game) {
    updatePlayer();
    updateMissions();
    if (0 >= game->timeLimit || missionCompleted()) {
        game->isRunning = 0;
    }
    game->timeLimit--; 
}