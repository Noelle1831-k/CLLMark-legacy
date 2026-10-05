void Game::gameLoop() {
    cout << "Starting the game..." << endl;
    for (int i = 0; i < 10; ++i) { 
        for (size_t j = 0; j < targets.size(); ++j) {
            targets[j].spawnTarget();
            this_thread::sleep_for(chrono::milliseconds(500)); 
            targets[j].moveTarget();
            if (rand() % 2 == 0) { 
                player.updateScore(10);
                cout << "Hit! Score: " << player.getScore() << endl;
            } else {
                cout << "Miss!" << endl;
            }
        }
    }
}