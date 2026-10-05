void MainApplication::shareBookRecommendations() {
    int userId;
    string recommendation;
    cout << "Enter your User ID: ";
    cin >> userId;
    if (users.find(userId) == users.end()) {
        cout << "User not found.\n";
        return;
    }
    cout << "Enter your book recommendation: ";
    cin.ignore();
    getline(cin, recommendation);
    cout << "User " << users[userId].getUsername() << " recommends: " << recommendation << "\n";
}