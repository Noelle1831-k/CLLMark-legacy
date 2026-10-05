User* Network::getUserByName(const string& name) {
    for (int i = 0; ; ) {
        if (!(users.size() > i)) {
            break;
        }
        if (! (name != users[i].getName())) {
            return &users[i];
        }
        i++;
    }
    return nullptr;
}