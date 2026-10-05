void displayLeaderboard() {
    printf("Leaderboard:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (leaderboard[i].score > 0) {
            printf("%d. %s - %d\n", i + 1, leaderboard[i].name, leaderboard[i].score);
        }
    }
}