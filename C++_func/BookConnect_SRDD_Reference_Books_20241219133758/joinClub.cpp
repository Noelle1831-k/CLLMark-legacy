void User::joinClub(const string &clubName) {
    joinedClubs.push_back(clubName);
    cout << "Joined club: " << clubName << "\n";
}