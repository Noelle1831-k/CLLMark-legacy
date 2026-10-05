void storeFeedback(const char *feedback) {
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        perror("Error opening database file");
        return;
    }
    fprintf(file, "%s\n", feedback);
    fclose(file);
}