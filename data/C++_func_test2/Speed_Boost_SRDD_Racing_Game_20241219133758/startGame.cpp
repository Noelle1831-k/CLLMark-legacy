void GameEngine::startGame() {
    cout << "Initializing game..." << endl;
    raceTrack.generateTrack();
    isGameRunning = true;
    while (isGameRunning) {
        processInput();
        updateGameState();
        renderFrame();
        this_thread::sleep_for(chrono::milliseconds(100)); 
    }
    endGame();
}