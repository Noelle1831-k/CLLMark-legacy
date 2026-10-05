void read_config() {
    log_message("Reading configuration...");
    FILE *config_file = fopen("config.txt", "r");
    if (config_file == NULL) {
        log_message("Error: Configuration file not found. Using defaults.");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), config_file)) {
        printf("Config: %s", line);
    }
    fclose(config_file);
    log_message("Configuration reading completed.");
}