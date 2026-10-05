void log_data_to_file(int step_count) {
    FILE *file = fopen("step_log.txt", "a");
    if (!file) {
        fprintf(stderr, "Error: Could not log data.\n");
        return;
    }
    fprintf(file, "Steps: %d\n", step_count);
    fclose(file);
}