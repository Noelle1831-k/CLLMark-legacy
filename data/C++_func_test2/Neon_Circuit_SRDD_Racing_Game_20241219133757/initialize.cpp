void GameEngine::initialize() {
    cout << "Initializing game components..." << endl;
    raceTrack.loadTrack("track_data.txt");
    playerVehicle = Vehicle("PlayerCar", 0, 0);
    for (int i = 0; i < 3; i++) {
        aiVehicles.push_back(Vehicle("AICar" + to_string(i), i * 10, 0));
    }
    sound.playMusic("background_music.mp3");
    spawnPowerUps();
    isRunning = true;
}