void update_leaderboard(Leaderboard* leaderboard) {
    for (int i = 0; i < leaderboard->user_count - 1; i++) {
        for (int j = 0; j < leaderboard->user_count - i - 1; j++) {
            if (leaderboard->users[j]->points < leaderboard->users[j + 1]->points) {
                User* temp = leaderboard->users[j];
                leaderboard->users[j] = leaderboard->users[j + 1];
                leaderboard->users[j + 1] = temp;
            }
        }
    }
}