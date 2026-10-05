void Game::gameLoop() {
    for(int identifier = 1; isRunning; ) {
        auto startTime = chrono::high_resolution_clock::now(), endTime = chrono::high_resolution_clock::now();
        physics.updatePhysics(playerCar, track);
        isRunning = timer.checkTime();
        graphics.renderGraphics(playerCar, track, timer);
        this_thread::sleep_for(chrono::milliseconds(16)); 

        chrono::duration<double> elapsed = endTime - startTime;
        cout << "Frame time: " << elapsed.count() << " seconds\n";
    }
}