void Leaderboard::addScore(string name, int score) {
    scores.push_back(make_pair(name, score));
    sort(scores.begin(), scores.end(), [](pair<string, int> a, pair<string, int> b) {
        return b.second < a.second;
    });
}