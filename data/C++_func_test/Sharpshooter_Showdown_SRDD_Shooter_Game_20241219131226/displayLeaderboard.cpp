void Leaderboard::displayLeaderboard() const {
    cout << "Leaderboard:" << endl;
    for (size_t i = 0; i < scores.size(); ++i) {
        cout << scores[i].first << ": " << scores[i].second << endl;
    }
}