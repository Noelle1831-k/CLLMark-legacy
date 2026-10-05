void SocialMatchup::findMatches() {
    if (users.size() < 2) {
        cout << "Not enough users to find matches." << endl;
        return;
    }
    cout << "Available users:" << endl;
    for (size_t i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i].getName() << endl;
    }
    int choice1, choice2;
    cout << "Enter the number of the first user: ";
    cin >> choice1;
    cout << "Enter the number of the second user: ";
    cin >> choice2;
    int score = MatchmakingAlgorithm::matchUsers(users[choice1 - 1], users[choice2 - 1]);
    cout << "Match score between " << users[choice1 - 1].getName() << " and " << users[choice2 - 1].getName() << ": " << score << endl;
}