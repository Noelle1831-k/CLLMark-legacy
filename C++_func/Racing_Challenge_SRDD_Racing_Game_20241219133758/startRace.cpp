void Game::startRace() {
    cout << "Starting the race on " << currentTrack->getName() << "!" << endl;
    currentTrack->generateObstacles();
    for (size_t i = 0; i < players.size(); ++i) {
        players[i]->chooseVehicle();
    }
    cout << "Race has begun!" << endl;
}