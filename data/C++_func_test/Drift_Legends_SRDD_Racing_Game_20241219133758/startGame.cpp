void Game::startGame() {
    cout << "Starting the game..." << endl;
    cout << "Available Cars:" << endl;
    for (size_t i = 0; i < cars.size(); i++) {
        cout << i + 1 << ". ";
        cars[i].displayCarStats();
    }
    int carChoice;
    cout << "Select a car (1-" << cars.size() << "): ";
    cin >> carChoice;
    cout << "Available Tracks:" << endl;
    for (size_t i = 0; i < tracks.size(); i++) {
        cout << i + 1 << ". ";
        tracks[i].displayTrackDetails();
    }
    int trackChoice;
    cout << "Select a track (1-" << tracks.size() << "): ";
    cin >> trackChoice;
    simulateDrift(cars[carChoice - 1], tracks[trackChoice - 1]);
    displayLeaderboard();
}