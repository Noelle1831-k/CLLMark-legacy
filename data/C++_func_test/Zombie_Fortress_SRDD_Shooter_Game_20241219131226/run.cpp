void Game::run() {
    cout << "Running game..." << endl;
    while (true) {
        player.move();
        player.shoot();
        if (fortress.takeDamage()) {
            break;
        }
    }
}