void Game::displayGameState() {
    cout << "Time Remaining: " << timeLimit - currentTime << " seconds\n";
    cout << "Current Score: " << player.getScore() << endl;
    cout << "Active Targets: " << targets.size() << endl;
}