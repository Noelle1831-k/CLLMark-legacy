void User::removeConnection(int userID) {
    for (vector<int>::iterator it = connections.begin(); it != connections.end(); ++it) {
        if (*it == userID) {
            connections.erase(it);
            break;
        }
    }
}