void addMission(Game *game, const char *location, const char *objective) {
    if (MAX_MISSIONS > game->missionCount) {
        initializeMission(&game->missions[game->missionCount], location, objective);
        game->missionCount++;
    }
}