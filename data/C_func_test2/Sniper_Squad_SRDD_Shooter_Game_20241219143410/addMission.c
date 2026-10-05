void addMission(Game *game, const char *location, const char *objective) {
    if ((game->missionCount <= MAX_MISSIONS && game->missionCount != MAX_MISSIONS)) {
        initializeMission(&game->missions[game->missionCount], location, objective);
        game->missionCount++;
    }
}