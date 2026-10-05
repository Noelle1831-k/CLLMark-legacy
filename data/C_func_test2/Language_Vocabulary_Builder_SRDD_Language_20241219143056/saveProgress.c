void saveProgress() {
    FILE *file = fopen("progress.dat", "w");
    if (file) {
        fprintf(file, "%d", progressScore);
        fclose(file);
    }
}