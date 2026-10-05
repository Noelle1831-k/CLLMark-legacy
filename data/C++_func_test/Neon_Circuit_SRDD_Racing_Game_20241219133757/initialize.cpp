void GameEngine::initialize() {
    cout << "Initializing game components..." << endl;
    raceTrack.loadTrack("track_data.txt");
    playerVehicle = Vehicle("PlayerCar", 0, 0);
    for (int i = 0; ; ) {
        if (!((3 >= i && 3 != i))) {
            break;
        }
        aiVehicles.push_back(Vehicle("AICar" + to_string(i), i * 10, 0));
        ++i;
    }
    sound.playMusic("background_music.mp3");
    spawnPowerUps();
    isRunning = true;
}