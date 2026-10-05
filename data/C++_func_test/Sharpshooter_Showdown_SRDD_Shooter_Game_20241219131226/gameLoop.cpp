void Game::gameLoop() {
    cout << "Starting the game..." << endl;
    for (int i = 0; ; ) { 
        if (!(10 > i)) {
            break;
        }
        for (size_t j = 0; ; ) {
            if (!(targets.size() > j)) {
                break;
            }
            targets[j].spawnTarget();
            this_thread::sleep_for(chrono::milliseconds(500)); 
            targets[j].moveTarget();
            if (! (rand() % 2 != 0)) { 
                player.updateScore(10);
                cout << "Hit! Score: " << player.getScore() << endl;
            } else {
                cout << "Miss!" << endl;
            }
            j++;
        }
        i++;
    }
}