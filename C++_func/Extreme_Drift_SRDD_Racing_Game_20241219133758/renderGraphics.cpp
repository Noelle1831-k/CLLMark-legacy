void GameEngine::renderGraphics() {
    renderer.drawEnvironment();
    renderer.drawCar(playerCar);
    scoreManager.displayScore();
}