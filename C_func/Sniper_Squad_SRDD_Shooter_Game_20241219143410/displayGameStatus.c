void displayGameStatus(Game *game) {
    printf("Game Status:\n");
    for (int i = 0; i < game->playerCount; i++) {
        printf("Player: %s, Skill Level: %d\n", game->players[i].name, game->players[i].skillLevel);
    }
    for (int i = 0; i < game->missionCount; i++) {
        printf("Mission: %s, Objective: %s, Completed: %d\n", game->missions[i].location, game->missions[i].objective, game->missions[i].completed);
    }
}