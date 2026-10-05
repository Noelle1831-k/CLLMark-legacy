void Leaderboard::getTopScores() {
    cout << "Leaderboard:" << endl;
    for (int i = 0; i < min((int)scores.size(), 10); i++) {
        cout << scores[i].first << ": " << scores[i].second << endl;
    }
}