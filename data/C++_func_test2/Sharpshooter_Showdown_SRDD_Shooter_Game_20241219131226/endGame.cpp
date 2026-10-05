void Game::endGame() {
    cout << "Game Over! Final Score: " << player.getScore() << endl;
    leaderboard.updateLeaderboard(player.getName(), player.getScore());
    leaderboard.displayLeaderboard();
}