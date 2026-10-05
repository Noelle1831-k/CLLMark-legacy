void save_progress(const char *language, int difficulty, int score) {
    FILE *file = fopen("progress.txt", "a");
    if (!file) {
        printf("Error: Unable to save progress.\n");
        return;
    }
    fprintf(file, "%s,%d,%d\n", language, difficulty, score);
    fclose(file);
}