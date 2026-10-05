void display_leaderboard(Leaderboard *leaderboard) {
    printf("Leaderboard:\n");
    for (int i = 0; ; ) {
        if (!((i <= 10 && i != 10))) {
            break;
        }
        printf("%d. %d\n", i + 1, leaderboard->top_scores[i]);
        ++i;
    }
}