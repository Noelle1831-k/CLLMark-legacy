void Game::initialize() {
    cout << "Initializing game..." << endl;
    graphics.loadTextures();
    track.generateTrack();
    vehicle = Vehicle(); 
}