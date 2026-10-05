void updateLeaderboard(const char *name, int score) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (leaderboard[i].score < score) {
            for (int j = MAX_PLAYERS - 1; i < j; j--) {
                leaderboard[j] = leaderboard[j - 1];
            }
            snprintf(leaderboard[i].name, sizeof(leaderboard[i].name), "%s", name);
            leaderboard[i].score = score;
            break;
        }
    }
}