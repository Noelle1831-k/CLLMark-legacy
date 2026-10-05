void cleanupApp() {
    printf("Cleaning up resources...\n");
    freeMemory();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}