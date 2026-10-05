void Game::runGameLoop() {
    cout << "Starting game loop..." << endl;
    while (currentMissionIndex < missions.size()) {
        displayMissionBriefing();
        missions[currentMissionIndex].startMission(playerJet);
        if (missions[currentMissionIndex].isCompleted()) {
            score += 100 * missions[currentMissionIndex].getDifficulty();
            currentMissionIndex++;
        }
    }
}