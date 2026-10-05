void Game::updateGameState() {
    physicsEngine.simulatePhysics(playerVehicle, track);
    weather.updateWeather();
}