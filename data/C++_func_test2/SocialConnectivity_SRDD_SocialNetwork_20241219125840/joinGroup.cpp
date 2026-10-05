void User::joinGroup(Group& group) {
    group.addMember(*this);
}