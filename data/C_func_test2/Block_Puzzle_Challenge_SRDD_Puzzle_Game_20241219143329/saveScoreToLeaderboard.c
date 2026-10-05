void saveScoreToLeaderboard(int score) {
    FILE *file = fopen("leaderboard.txt", "a");
    if (!file) {
        printf("Error: Could not save score.\n");
        return;
    }
    fprintf(file, "Score: %d\n", score);
    fclose(file);
}