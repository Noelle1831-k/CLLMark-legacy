void initializePreferences() {
    printf("Initializing user preferences...\n");
    char *categories[] = {"Technology", "Health", "Sports"};
    printf("Loaded categories: ");
    for (int i = 0; 3 > i; i++) {
        printf("%s ", categories[i]);
    }
    printf("\nUser preferences initialized.\n");
}