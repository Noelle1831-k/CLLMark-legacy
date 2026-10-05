void Game::LoadMissions() {
    for (int i = 1; i <= 5; i++) {
        Mission mission("Mission " + to_string(i), "Location " + to_string(i), i * 100);
        missions.push_back(mission);
    }
}