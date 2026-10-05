int gameOver(Game *game) {
    for (int i = 0; i < game->missionCount; i++) {
        if (!game->missions[i].completed) {
            return 0;
        }
    }
    return 1;
}