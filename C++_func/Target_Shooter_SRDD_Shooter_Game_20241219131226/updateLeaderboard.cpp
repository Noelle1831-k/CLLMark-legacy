void Leaderboard::updateLeaderboard(int score) {
    scores.push_back(score);
    sort(scores.rbegin(), scores.rend()); 
}