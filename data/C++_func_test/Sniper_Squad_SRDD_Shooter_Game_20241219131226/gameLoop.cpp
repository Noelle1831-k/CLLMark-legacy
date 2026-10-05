void Game::gameLoop() {
    while (true) {
        missionManager.assignMission(players);
        if (missionManager.allMissionsCompleted()) {
            printf("All missions completed!\n");
            break;
        }
    }
}