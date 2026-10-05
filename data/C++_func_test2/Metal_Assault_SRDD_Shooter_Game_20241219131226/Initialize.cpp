void Game::Initialize() {
    cout << "Initializing game..." << endl;
    graphics.LoadTextures();
    currentLevel.Load();
    SpawnEnemies(5);
    isRunning = true;
}