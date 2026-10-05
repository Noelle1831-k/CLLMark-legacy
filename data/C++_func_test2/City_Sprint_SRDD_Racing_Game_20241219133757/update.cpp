void Game::update() {
    input.processInput(playerCar);
    ai.updateAI(aiCars, raceTrack);
    physics.updatePhysics(playerCar, aiCars, raceTrack);
}