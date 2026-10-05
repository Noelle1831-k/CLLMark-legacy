void fetchFeedback() {
    char line[512];
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("No feedback available.\n");
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}