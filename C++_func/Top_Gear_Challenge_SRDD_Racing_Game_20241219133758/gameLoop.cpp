void Game::gameLoop() {
    while (isRunning) {
        auto startTime = chrono::high_resolution_clock::now();
        physics.updatePhysics(playerCar, track);
        isRunning = timer.checkTime();
        graphics.renderGraphics(playerCar, track, timer);
        this_thread::sleep_for(chrono::milliseconds(16)); 
        auto endTime = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = endTime - startTime;
        cout << "Frame time: " << elapsed.count() << " seconds\n";
    }
}