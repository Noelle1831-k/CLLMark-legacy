void runApp() {
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = 0;
            } else {
                handleInput(event);
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderMapVisual(renderer);
        updateUI(renderer);
        SDL_RenderPresent(renderer);
    }
}