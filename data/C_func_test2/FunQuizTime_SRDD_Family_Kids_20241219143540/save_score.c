void save_score(int score, int total) {
    FILE *file = fopen("scores.txt", "a");
    if (!file) {
        printf("Error opening scores file for saving.\n");
        return;
    }
    fprintf(file, "Score: %d/%d\n", score, total);
    fclose(file);
}