void startGame() {
    Car car;
    Track track;
    initializeCar(&car, 0.0f, 0.5f, 1.0f);
    generateTrack(&track);
    SDL_Window *window = SDL_CreateWindow(
        "Breakneck Racer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    int gameRunning = 1;
    while (gameRunning) {
        gameRunning = processInput(&car);
        applyPhysics(&car, 0.016f); 
        updateCarPosition(&car, 0.016f);
        if (checkCollision(&car, &track)) {
            printf("Collision detected! Game over.\n");
            break;
        }
        renderGraphics(&car, &track);
        updateDisplay();
        SDL_Delay(16); 
    }
    SDL_DestroyWindow(window);
    endGame();
}