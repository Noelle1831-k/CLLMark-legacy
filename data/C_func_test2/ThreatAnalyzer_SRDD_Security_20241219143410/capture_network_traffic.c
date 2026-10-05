char *capture_network_traffic() {
    char *data = (char *)malloc(256);
    if (!data) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(data, "Simulated network packet data...");
    return data;
}