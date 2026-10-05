void loadProgress() {
    FILE *file = fopen("progress.dat", "r");
    if (file) {
        fscanf(file, "%d", &progressScore);
        fclose(file);
    }
}