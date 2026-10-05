void ConnectionManager::displayConnections(const User& user) const {
    auto it = connections.find(user.getName());
    if (it != connections.end()) {
        cout << "Connections for " << user.getName() << ":" << endl;
        for (int i = 0; i < it->second.size(); i++) {
            cout << "- " << it->second[i] << endl;
        }
    } else {
        cout << user.getName() << " has no connections." << endl;
    }
}