void display_leaderboard(Leaderboard *leaderboard) {
    printf("Leaderboard:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %d\n", i + 1, leaderboard->top_scores[i]);
    }
}