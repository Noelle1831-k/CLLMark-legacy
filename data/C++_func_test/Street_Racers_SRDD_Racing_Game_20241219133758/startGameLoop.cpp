void GameEngine::startGameLoop() {
    cout << "Starting game loop..." << endl;
    while (isRunning) {
        handleInput();
        update();
        render();
        checkGameOver();
        this_thread::sleep_for(chrono::milliseconds(16)); 
    }
}