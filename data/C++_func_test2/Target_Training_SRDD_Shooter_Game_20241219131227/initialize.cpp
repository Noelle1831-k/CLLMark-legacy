void Game::initialize() {
    cout << "Initializing game resources..." << endl;
    scoreManager->resetScore();
    target->spawnTarget();
}