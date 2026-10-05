void Game::updateGame() {
    player.displayStatus();
    currentMission.displayMissionStatus();
    if (currentMission.checkCompletion()) {
        printf("Mission completed!\n");
        running = false;
    }
}