void Game::shutdown() {
    enemies.clear();
    weapons.clear();
    powerUps.clear();
    cout << "Game resources have been cleaned up." << endl;
}