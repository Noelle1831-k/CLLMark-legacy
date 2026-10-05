void initializePreferences() {
    printf("Initializing user preferences...\n");
    char *categories[] = {"Technology", "Health", "Sports"};
    printf("Loaded categories: ");
    for (int i = 0; i < 3; i++) {
        printf("%s ", categories[i]);
    }
    printf("\nUser preferences initialized.\n");
}