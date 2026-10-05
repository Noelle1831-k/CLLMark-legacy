void Game::spawnPolice() {
    cout << "Spawning police units..." << endl;
    for (int i = 0; i < 3; i++) {
        Police police;
        policeUnits.push_back(police);
    }
}