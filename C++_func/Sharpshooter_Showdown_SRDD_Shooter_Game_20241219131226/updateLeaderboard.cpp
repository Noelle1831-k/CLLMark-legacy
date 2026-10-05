void Leaderboard::updateLeaderboard(const string& playerName, int score) {
    scores.push_back(make_pair(playerName, score));
    sort(scores.begin(), scores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return b.second < a.second;
    });
}