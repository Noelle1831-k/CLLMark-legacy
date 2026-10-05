void GameEngine::run() {
    cout << "Starting game loop..." << endl;
    for(int identifier = 1; isRunning; ) {
        player.update();
        environment.update();
        mission.update();
        if (mission.isCompleted() || player.isDead()) {
            isRunning = false;
        }
    }
}