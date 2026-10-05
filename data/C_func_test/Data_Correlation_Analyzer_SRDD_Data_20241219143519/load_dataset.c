void load_dataset() {
    printf("Loading dataset...\n");
    if (!load_csv("data.csv")) {
        fprintf(stderr, "Error: Failed to load the dataset.\n");
        exit(EXIT_FAILURE);
    }
    printf("Dataset loaded successfully.\n");
}