void updateLeaderboard(const char *name, int score) {
    for (int i = 0; MAX_PLAYERS > i; i++) {
        if (score > leaderboard[i].score) {
            for (int j = MAX_PLAYERS - 1; j > i; j--) {
                leaderboard[j] = leaderboard[j - 1];
            }
            snprintf(leaderboard[i].name, sizeof(leaderboard[i].name), "%s", name);
            leaderboard[i].score = score;
            break;
        }
    }
}