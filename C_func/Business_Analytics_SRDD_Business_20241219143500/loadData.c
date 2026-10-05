void loadData() {
    printf("Loading data...\n");
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter the data file name: ");
    scanf("%s", fileName);
    if (readFile(fileName)) {
        printf("Data loaded successfully!\n");
    } else {
        printf("Failed to load data. Please check the file and try again.\n");
        exit(EXIT_FAILURE);
    }
}