void Game::updateScore(int t1Score, int t2Score) {
    if (isActive) {
        team1Score = t1Score;
        team2Score = t2Score;
    } else {
        cout << "Error: Cannot update score for an inactive game." << endl;
    }
}