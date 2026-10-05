void GameEngine::run() {
    cout << "Starting game loop..." << endl;
    while (isRunning) {
        player.update();
        environment.update();
        mission.update();
        if (mission.isCompleted() || player.isDead()) {
            isRunning = false;
        }
    }
}