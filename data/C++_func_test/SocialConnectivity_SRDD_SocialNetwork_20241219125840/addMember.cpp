void Group::addMember(User& user) {
    members.push_back(user);
    cout << user.getName() << " joined the group " << name << endl;
}