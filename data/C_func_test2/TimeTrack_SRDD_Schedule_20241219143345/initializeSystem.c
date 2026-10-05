void initializeSystem() {
    printf("Initializing TimeTrack System...\n");
    if (!loadActivitiesFromFile()) {
        handleErrors("Failed to load activities from file.");
    }
    if (!loadCategoriesFromFile()) {
        handleErrors("Failed to load categories from file.");
    }
    printf("System Initialized Successfully!\n\n");
}