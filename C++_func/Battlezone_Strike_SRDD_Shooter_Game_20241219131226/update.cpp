void Game::update() {
    if (mission.isCompleted()) {
        cout << "Mission completed!" << endl;
        isRunning = false;
    }
}