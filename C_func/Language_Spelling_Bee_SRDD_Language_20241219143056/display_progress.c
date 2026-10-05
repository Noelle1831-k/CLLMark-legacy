void display_progress() {
    FILE *file = fopen("progress.txt", "r");
    if (!file) {
        printf("No progress data available.\n");
        return;
    }
    char line[100];
    printf("Progress History:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}