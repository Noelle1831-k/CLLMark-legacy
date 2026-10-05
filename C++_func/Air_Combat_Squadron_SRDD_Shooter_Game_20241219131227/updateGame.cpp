void Game::updateGame() {
    player.displayStatus();
    currentMission.displayMissionStatus();
    if (currentMission.checkCompletion()) {
        cout << "Mission completed!" << endl;
        running = false;
    }
}