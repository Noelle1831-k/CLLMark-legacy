void initializeLeaderboard() {
    for (int i = 0; ; ) {
        if (!((i <= MAX_PLAYERS && i != MAX_PLAYERS))) {
            break;
        }
        leaderboard[i].score = 0;
        ++i;
    }
}