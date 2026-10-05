void Match::displayResult() {
    int score1 = rand() % 100 + 1;
    int score2 = rand() % 100 + 1;
    cout << "Match Result: " << endl;
    if (score1 > score2) {
        cout << "Team 1 wins!" << endl;
    } else if (score2 > score1) {
        cout << "Team 2 wins!" << endl;
    } else {
        cout << "The match is a draw!" << endl;
    }
}