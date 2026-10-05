void MainApplication::joinBookClub() {
    int userId, clubId;
    cout << "Enter your User ID: ";
    cin >> userId;
    if (users.find(userId) == users.end()) {
        cout << "User not found.\n";
        return;
    }
    cout << "Enter Book Club ID to join: ";
    cin >> clubId;
    if (bookClubs.find(clubId) == bookClubs.end()) {
        cout << "Book Club not found.\n";
        return;
    }
    users[userId].joinClub(bookClubs[clubId].getClubName());
    bookClubs[clubId].addMember(users[userId].getUsername());
}