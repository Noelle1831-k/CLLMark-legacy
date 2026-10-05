void Game::loadTrack() {
    cout << "Loading track..." << endl;
    track = Track("Mountain Pass", "Rainy");
    weather = Weather("Rainy");
    playerVehicle = Vehicle("Sports Car", 200, 10, 80);
    cout << "Track loaded successfully." << endl;
}