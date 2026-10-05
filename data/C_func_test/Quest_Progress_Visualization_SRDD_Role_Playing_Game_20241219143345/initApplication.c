void initApplication() {
    printf("Initializing Quest Progress Visualization...\n");
    if (!loadQuestsFromFile()) {
        printf("No saved quests found. Starting fresh.\n");
    }
}