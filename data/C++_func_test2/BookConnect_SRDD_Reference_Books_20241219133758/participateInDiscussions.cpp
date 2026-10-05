void MainApplication::participateInDiscussions() {
    int clubId;
    string topic;
    cout << "Enter Book Club ID to start a discussion: ";
    cin >> clubId;
    if (bookClubs.find(clubId) == bookClubs.end()) {
        cout << "Book Club not found.\n";
        return;
    }
    cout << "Enter discussion topic: ";
    cin.ignore();
    getline(cin, topic);
    bookClubs[clubId].startDiscussion(topic);
}