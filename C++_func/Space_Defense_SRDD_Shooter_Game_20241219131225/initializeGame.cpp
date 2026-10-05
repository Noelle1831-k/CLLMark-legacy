void Game::initializeGame() {
    srand(time(0));
    player = Spaceship();
    aliens.clear();
    powerUps.clear();
    cout << "Game initialized successfully!" << endl;
}