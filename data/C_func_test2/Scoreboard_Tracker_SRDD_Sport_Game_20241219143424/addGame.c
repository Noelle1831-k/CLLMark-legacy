void addGame(const char *sport, const char *team1, const char *team2) {
    if (gameCount >= MAX_GAMES) {
        printf("Error: Maximum number of games reached.\n");
        return;
    }
    if (strlen(team1) == 0 || strlen(team2) == 0) {
        printf("Error: Team names cannot be empty.\n");
        return;
    }
    games[gameCount].id = gameCount + 1;
    strcpy(games[gameCount].sport, sport);
    strcpy(games[gameCount].team1, team1);
    strcpy(games[gameCount].team2, team2);
    updateScore(games[gameCount].id, 0, 0);
    gameCount++;
    printf("Game added successfully with ID %d.\n", games[gameCount - 1].id);
}