Game::Game() {
    playerVehicle = new Vehicle();
    currentTrack = new RaceTrack();
    player = new Player();
    graphics = new Graphics();
    inputHandler = new InputHandler();
    soundManager = new SoundManager();
    isRunning = false;
}