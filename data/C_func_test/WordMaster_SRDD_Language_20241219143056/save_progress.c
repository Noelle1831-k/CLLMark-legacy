void save_progress(const char* username) {
    FILE *file = fopen("progress.txt", "a");
    if (file == NULL) {
        printf("Error saving progress!\n");
        return;
    }
    fprintf(file, "%s %d\n", username, 3); 
    fclose(file);
}