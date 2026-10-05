int load_data(int *step_count) {
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not load data.\n");
        return 0;
    }
    fscanf(file, "%d", step_count);
    fclose(file);
    printf("Data loaded: %d steps.\n", *step_count);
    return 1;
}