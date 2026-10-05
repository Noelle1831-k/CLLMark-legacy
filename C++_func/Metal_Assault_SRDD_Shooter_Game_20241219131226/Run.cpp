void Game::Run() {
    cout << "Running game loop..." << endl;
    int frameCount = 0;
    while (isRunning) {
        cout << "Frame: " << frameCount << endl;
        player.Move();
        player.Shoot();
        for (size_t i = 0; i < enemies.size(); i++) {
            enemies[i].Move();
            enemies[i].Attack();
        }
        HandleCollisions();
        currentLevel.Update();
        graphics.RenderScene();
        if (frameCount++ > 100) {
            isRunning = false; 
        }
    }
}