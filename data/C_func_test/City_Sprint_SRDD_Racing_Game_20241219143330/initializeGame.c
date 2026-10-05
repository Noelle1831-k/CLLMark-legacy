void initializeGame() {
    if (!initializeGraphics()) {
        printf("Error initializing graphics.\n");
        exit(1);
    }
    loadAssets();
    initializePlayerCar();
    initializeAI();
    printf("Game initialized successfully.\n");
}