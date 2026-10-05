User* Network::getUserByName(const string& name) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getName() == name) {
            return &users[i];
        }
    }
    return nullptr;
}