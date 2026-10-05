void updateGame(Game *game) {
    updatePlayer();
    updateMissions();
    if ((game->timeLimit < 0 || game->timeLimit == 0) || missionCompleted()) {
        game->isRunning = 0;
    }
    game->timeLimit--; 
}