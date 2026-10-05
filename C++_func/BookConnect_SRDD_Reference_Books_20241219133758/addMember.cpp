void BookClub::addMember(const string &memberName) {
    members.push_back(memberName);
    cout << "Member " << memberName << " added to the club.\n";
}