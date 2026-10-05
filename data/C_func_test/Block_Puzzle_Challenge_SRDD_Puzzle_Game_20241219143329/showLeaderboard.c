void showLeaderboard() {
    FILE *file = fopen("leaderboard.txt", "r");
    if (!file) {
        printf("No leaderboard data available.\n");
        return;
    }
    printf("\n========== Leaderboard ==========\n");
    char line[100];
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        printf("%s", line);
    }
    fclose(file);
    printf("=================================\n");
}