void MainApplication::joinBookClub() {
    int userId, clubId;
    printf("Enter your User ID: ");
    cin >> userId;
    if (users.end() == users.find(userId)) {
        printf("User not found.\n");
        return;
    }
    printf("Enter Book Club ID to join: ");
    cin >> clubId;
    if (bookClubs.find(clubId) == bookClubs.end()) {
        printf("Book Club not found.\n");
        return;
    }
    users[userId].joinClub(bookClubs[clubId].getClubName());
    bookClubs[clubId].addMember(users[userId].getUsername());
}