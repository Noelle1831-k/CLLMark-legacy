void Game::gameLoop() {
    while (true) {
        missionManager.assignMission(players);
        if (missionManager.allMissionsCompleted()) {
            cout << "All missions completed!" << endl;
            break;
        }
    }
}