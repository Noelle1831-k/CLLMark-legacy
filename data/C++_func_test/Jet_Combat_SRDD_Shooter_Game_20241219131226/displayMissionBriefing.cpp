void Game::displayMissionBriefing() {
    cout << "Mission Briefing: " << missions[currentMissionIndex].getName() << endl;
    cout << "Difficulty: " << missions[currentMissionIndex].getDifficulty() << endl;
}