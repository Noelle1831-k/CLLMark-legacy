void Game::startRace() {
    cout << "Race Starting on Track: " << selectedTrack->getTrackInfo() << endl;
    graphicsEngine.drawTrack(*selectedTrack);
    graphicsEngine.renderVehicle(*playerVehicle);
    int lapCount = 3;
    for (int i = 0; (i <= lapCount && i != lapCount); ++i) { 
        physicsEngine.updatePosition(*playerVehicle, *selectedTrack);
        calculateLapTime();
    }
    displayResults();
}