void Leaderboard::displayLeaderboard() {
    cout << "==========================" << endl;
    cout << "         Leaderboard      " << endl;
    cout << "==========================" << endl;
    for (size_t i = 0; i < scores.size(); i++) {
        cout << i + 1 << ". " << scores[i] << endl;
    }
}