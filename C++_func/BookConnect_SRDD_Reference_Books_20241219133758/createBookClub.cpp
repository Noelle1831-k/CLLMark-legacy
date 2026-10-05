void MainApplication::createBookClub() {
    string clubName;
    cout << "Enter Book Club name: ";
    cin >> clubName;
    BookClub newClub(clubIdCounter++, clubName);
    bookClubs[newClub.getClubId()] = newClub;
    cout << "Book Club created successfully!\n";
}