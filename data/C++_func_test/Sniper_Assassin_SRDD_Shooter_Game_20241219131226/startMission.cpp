void Game::startMission(int missionIndex) {
    cout << "Starting " << missions[missionIndex].getName() << "..." << endl;
    missions[missionIndex].execute(player);
}