void BookClub::removeMember(const string &memberName) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (*it == memberName) {
            members.erase(it);
            cout << "Member " << memberName << " removed from the club.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}