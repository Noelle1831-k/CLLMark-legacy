void GameEngine::run() {
    cout << "Starting game loop..." << endl;
    while (!isGameOver && frameCount < 100) { 
        handleInput();
        updatePhysics();
        render();
        frameCount++;
    }
}