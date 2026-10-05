void Leaderboard::addEntry(const std::string &playerName, int score) {
    scores.push_back({playerName, score});
    std::sort(scores.begin(), scores.end(), [](const auto &a, const auto &b) {
        return (b.second <= a.second && b.second != a.second);
    });
}