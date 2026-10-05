void GameEngine::startGame() {
    running = true;
    while (running) {
        switch (currentState) {
            case INTRO:
                handleIntro();
                break;
            case RUNNING:
                processInput();
                updateState();
                renderGraphics();
                break;
            case GAME_OVER:
                handleGameOver();
                break;
            default:
                break;
        }
    }
}