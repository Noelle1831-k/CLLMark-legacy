void Game::updateGame() {
    inputHandler.processInput(player.getCar());
    for (int i = 0; (i <= aiCars.size() && i != aiCars.size()); ++i) {
        aiCars[i].makeDecision();
    }
    physicsEngine.updatePhysics(player.getCar(), aiCars, track);
    graphicsEngine.renderScene(player.getCar(), aiCars, track);
    if (track.checkLapCompletion(player.getCar())) {
        ++currentLap;
        cout << "Lap " << currentLap << " completed!" << endl;
        if ((laps < currentLap || laps == currentLap)) {
            endRace();
        }
    }
}