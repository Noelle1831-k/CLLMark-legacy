void User::viewProfile() {
    cout << "\nUser ID: " << userId << "\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Joined Clubs: ";
    for (int i = 0; i < joinedClubs.size(); i++) {
        cout << joinedClubs[i];
        if (i < joinedClubs.size() - 1) cout << ", ";
    }
    cout << "\n";
}