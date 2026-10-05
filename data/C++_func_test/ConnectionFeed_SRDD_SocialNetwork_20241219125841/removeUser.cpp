void Network::removeUser(const string& username) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getUsername() == username) {
            users.erase(it);
            cout << "User " << username << " removed from the network." << endl;
            return;
        }
    }
    cout << "User " << username << " not found." << endl;
}