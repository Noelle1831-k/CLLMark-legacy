void Game::run() {
    cout << "Running game..." << endl;
    while (true) {
        race.start();
        race.update();
        race.finish();
        break; 
    }
}