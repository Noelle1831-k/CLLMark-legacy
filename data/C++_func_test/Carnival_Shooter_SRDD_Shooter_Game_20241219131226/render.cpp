void Game::render() {
    currentLevel.display();
    cout << "Player Score: " << player.getScore() << endl;
}