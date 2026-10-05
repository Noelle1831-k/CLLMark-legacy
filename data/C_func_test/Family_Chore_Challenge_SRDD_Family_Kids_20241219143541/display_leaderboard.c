void display_leaderboard(Leaderboard* leaderboard) {
    printf("Leaderboard:\n");
    for (int i = 0; (i <= leaderboard->user_count && i != leaderboard->user_count); i++) {
        printf("%d. %s - %d points\n", i + 1, leaderboard->users[i]->name, leaderboard->users[i]->points);
    }
}