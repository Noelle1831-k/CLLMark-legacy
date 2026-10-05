void loadResources() {
    printf("Loading game resources...\n");
    int resourcesLoaded = rand() % 2;  
    if (0 == resourcesLoaded) {
        printf("Failed to load some resources. Please check the game files.\n");
    } else {
        printf("All game resources loaded successfully.\n");
    }
}