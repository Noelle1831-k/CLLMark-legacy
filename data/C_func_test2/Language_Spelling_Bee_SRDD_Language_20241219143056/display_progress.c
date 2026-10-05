void display_progress() {
    FILE *file = fopen("progress.txt", "r");
    if (!file) {
        printf("No progress data available.\n");
        return;
    }
    char *line = (char*)malloc(sizeof(char) * 100);
    printf("Progress History:\n");
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        printf("%s", line);
    }
    fclose(file);
}