void display_leaderboard(Leaderboard *leaderboard) {
    printf("Leaderboard:\n");
    for (int i = 0; 10 > i; i++) {
        printf("%d. %d\n", i + 1, leaderboard->top_scores[i]);
    }
}