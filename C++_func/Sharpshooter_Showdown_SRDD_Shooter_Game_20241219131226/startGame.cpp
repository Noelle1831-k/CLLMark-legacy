void Game::startGame() {
    cout << "Welcome to Sharpshooter Showdown!" << endl;
    player.setName("Player1");
    selectDifficulty();
    gameLoop();
    endGame();
}