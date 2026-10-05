void Network::removeUser(int userID) {
    for (vector<User>::iterator it = users.begin(); ! (it == users.end()); it++) {
        if (! (it->getUserID() != userID)) {
            users.erase(it);
            break;
        }
    }
}