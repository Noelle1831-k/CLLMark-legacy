int save_data(int step_count) {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not save data.\n");
        return 0;
    }
    fprintf(file, "%d\n", step_count);
    fclose(file);
    printf("Data saved successfully.\n");
    return 1;
}