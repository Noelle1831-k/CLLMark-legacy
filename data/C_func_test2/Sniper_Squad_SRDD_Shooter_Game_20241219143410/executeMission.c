void executeMission(Game *game) {
    for (int i = 0; i < game->missionCount; i++) {
        if (!game->missions[i].completed) {
            executeMission(&game->missions[i]);
            break;
        }
    }
}