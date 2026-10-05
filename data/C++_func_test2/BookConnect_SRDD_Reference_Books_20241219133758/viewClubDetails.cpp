void BookClub::viewClubDetails() {
    cout << "Club ID: " << clubId << "\n";
    cout << "Club Name: " << clubName << "\n";
    cout << "Members: ";
    for (const auto &member : members) {
        cout << member << ", ";
    }
    cout << "\nDiscussion Threads: ";
    for (const auto &thread : discussionThreads) {
        cout << thread << ", ";
    }
    cout << "\n";
}