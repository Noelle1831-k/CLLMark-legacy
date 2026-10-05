Leaderboard* create_leaderboard() {
    Leaderboard *leaderboard = (Leaderboard*)malloc(sizeof(Leaderboard));
    for (int i = 0; i < 10; i++) {
        leaderboard->top_scores[i] = 0;
    }
    return leaderboard;
}