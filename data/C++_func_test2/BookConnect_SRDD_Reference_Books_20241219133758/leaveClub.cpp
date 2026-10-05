void User::leaveClub(const string &clubName) {
    for (int i = 0; i < joinedClubs.size(); i++) {
        if (joinedClubs[i] == clubName) {
            joinedClubs.erase(joinedClubs.begin() + i);
            cout << "Left club: " << clubName << "\n";
            return;
        }
    }
    cout << "Club not found in joined list.\n";
}