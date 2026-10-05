void save_progress() {
    FILE *file = fopen("progress.dat", "w");
    if (file == NULL) {
        perror("Failed to save progress.");
        return;
    }
    fwrite(user_progress, sizeof(int), 10, file);
    fclose(file);
    printf("Progress saved successfully.\n");
}