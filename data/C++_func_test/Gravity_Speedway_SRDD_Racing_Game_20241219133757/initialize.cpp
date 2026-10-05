void Game::initialize() {
    printf("Initializing game...\n");
    graphics.loadTextures();
    track.generateTrack();
    vehicle = Vehicle(); 
}