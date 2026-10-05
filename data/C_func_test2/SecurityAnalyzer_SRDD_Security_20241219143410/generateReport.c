void generateReport() {
    printf("Generating security report...\n");
    if (!compileReport()) {
        printf("Error: Failed to compile the report. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    if (!provideRecommendations()) {
        printf("Error: Failed to generate recommendations. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}