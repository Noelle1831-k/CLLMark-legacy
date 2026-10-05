void save_data() {
    log_message("Saving data...");
    FILE *data_file = fopen("user_data.txt", "w");
    if (data_file == NULL) {
        log_message("Error: Could not open data file.");
        return;
    }
    fprintf(data_file, "Sample user data saved.\n");
    fclose(data_file);
    log_message("Data saved successfully.");
}