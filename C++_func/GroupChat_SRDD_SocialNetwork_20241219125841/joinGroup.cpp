void User::joinGroup(Group* group) {
    groups.push_back(group);
    group->addUser(this);
}