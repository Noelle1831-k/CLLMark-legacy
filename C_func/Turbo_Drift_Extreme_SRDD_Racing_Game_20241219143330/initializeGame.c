void initializeGame() {
    printf("Initializing Turbo Drift Extreme...\n");
    loadCars(MAX_CARS);
    loadTracks(MAX_TRACKS);
    initGraphics();
    initInput();
    initScore();
}