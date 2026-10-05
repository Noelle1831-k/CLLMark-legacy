void Network::displayAllUsers() const {
    for (int i = 0; i < users.size(); i++) {
        users[i].displayProfile();
    }
}