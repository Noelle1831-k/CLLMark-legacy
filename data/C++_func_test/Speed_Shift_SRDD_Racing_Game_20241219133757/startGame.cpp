void GameEngine::startGame() {
    isRunning = true;
    track.loadTrack();
    graphics.initializeGraphics();
    displayGameInstructions();
    cout << "Initializing game..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Game started!" << endl;
    gameLoop();
}