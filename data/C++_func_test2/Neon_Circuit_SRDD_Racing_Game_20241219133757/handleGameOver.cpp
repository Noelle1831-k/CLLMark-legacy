void GameEngine::handleGameOver() {
    cout << "Game Over! Final Score: " << player.getScore() << endl;
    sound.playSoundEffect("game_over.wav");
}