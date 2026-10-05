User* Network::findUserByID(int userID) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserID() == userID) {
            return &users[i];
        }
    }
    return nullptr;
}