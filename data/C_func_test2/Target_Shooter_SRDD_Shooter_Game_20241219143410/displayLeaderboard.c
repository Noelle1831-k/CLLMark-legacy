void displayLeaderboard() {
    printf("\nLeaderboard:\n");
    for (int i = 0; i < MAX_SCORES; i++) {
        if (highScores[i] > 0) {
            printf("%d: %d\n", i + 1, highScores[i]);
        }
    }
    printf("\n");
}