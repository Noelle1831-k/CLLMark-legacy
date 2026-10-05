Game::~Game() {
    delete playerVehicle;
    delete currentTrack;
    delete player;
    delete graphics;
    delete inputHandler;
    delete soundManager;
}