void updateScore(int teamId, int score) {
    if (!gameActive) {
        printf("Game not active. Initialize the game first.\n");
        return;
    }
    if (teamId < 0 || teamId > 1) {
        printf("Invalid Team ID.\n");
        return;
    }
    scores[teamId] += score;
    printf("Score updated for %s: %d\n", getTeamName(teamId), scores[teamId]);
}