void listGames(const char *sport) {
    int found = 0;
    for (int i = 0; i < gameCount; i++) {
        if (strcmp(games[i].sport, sport) == 0) {
            printf("Game ID: %d, %s vs %s\n", games[i].id, games[i].team1, games[i].team2);
            found = 1;
        }
    }
    if (!found) {
        printf("No games found for sport '%s'.\n", sport);
    }
}