int main() {
    GraphicsEngine graphics;
    graphics.initialize();
    Track track("Mount Fuji Circuit");
    Car playerCar("Ferrari", 100, 0.0f);
    AI aiOpponent("Lamborghini", 95, 0.0f);
    while (!track.isRaceFinished(playerCar) && !track.isRaceFinished(aiOpponent)) {
        playerCar.handleInput();
        PhysicsEngine::applyPhysics(playerCar);
        aiOpponent.updateAI(track);
        PhysicsEngine::applyPhysics(aiOpponent);
        graphics.render(playerCar, aiOpponent, track);
        graphics.waitForNextFrame();
    }
    graphics.cleanup();
    return 0;
}