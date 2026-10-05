void Family::addMember(User member) {
    members.push_back(member);
    cout << "Added " << member.getName() << " to " << familyName << endl;
}