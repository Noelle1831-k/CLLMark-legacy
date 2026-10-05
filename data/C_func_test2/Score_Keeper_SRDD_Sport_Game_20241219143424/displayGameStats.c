void displayGameStats() {
    if (!gameActive) {
        printf("Game not active. Initialize the game first.\n");
        return;
    }
    printf("\n===== Game Stats =====\n");
    printf("%s: %d\n", getTeamName(0), scores[0]);
    printf("%s: %d\n", getTeamName(1), scores[1]);
    updateElapsedTime();
}