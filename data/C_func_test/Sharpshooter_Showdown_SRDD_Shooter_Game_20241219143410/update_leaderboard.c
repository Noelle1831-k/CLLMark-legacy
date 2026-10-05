void update_leaderboard(Leaderboard *leaderboard, Player *player) {
    int score = get_score(player);
    for (int i = 0; i < 10; i++) {
        if (score > leaderboard->top_scores[i]) {
            for (int j = 9; j > i; j--) {
                leaderboard->top_scores[j] = leaderboard->top_scores[j - 1];
            }
            leaderboard->top_scores[i] = score;
            break;
        }
    }
}