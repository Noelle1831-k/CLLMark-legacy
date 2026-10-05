void GameEngine::run() {
    bool isRunning = true;
    while (isRunning) {
        weather->updateWeather();
        track->updateTrack();
        physicsEngine->updateVehiclePhysics(vehicle, track, weather);
        vehicle->updatePosition();
        graphicsRenderer->render(track, vehicle, weather);
        if (track->hasReachedFinishLine(vehicle)) {
            cout << "Congratulations! You've finished the race!" << endl;
            isRunning = false;
        }
    }
}