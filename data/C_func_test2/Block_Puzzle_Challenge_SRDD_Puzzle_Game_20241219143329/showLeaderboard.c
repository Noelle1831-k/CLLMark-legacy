void showLeaderboard() {
    FILE *file = fopen("leaderboard.txt", "r");
    if (!file) {
        printf("No leaderboard data available.\n");
        return;
    }
    printf("\n========== Leaderboard ==========\n");
    char *line = (char*)malloc(sizeof(char) * 100);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("=================================\n");
}