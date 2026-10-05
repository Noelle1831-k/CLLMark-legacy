void User::createGroup(const string& groupName, const string& description) {
    Group* newGroup = new Group(groupName, description, this);
    groups.push_back(newGroup);
}