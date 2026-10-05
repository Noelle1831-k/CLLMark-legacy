void Game::endGame() {
    cout << "------------------------------------" << endl;
    cout << "Game over! Your final score: " << player.getScore() << endl;
    leaderboard.updateLeaderboard(player.getScore());
    leaderboard.displayLeaderboard();
}