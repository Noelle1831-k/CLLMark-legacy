void SocialNetwork::addGroup(Group group) {
    groups.push_back(group);
    cout << "Group added: " << group.getName() << endl;
}