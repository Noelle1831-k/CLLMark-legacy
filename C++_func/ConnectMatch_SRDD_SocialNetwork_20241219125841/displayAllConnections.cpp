void ConnectionManager::displayAllConnections() const {
    for (auto it = connections.begin(); it != connections.end(); ++it) {
        cout << "Connections for " << it->first << ":" << endl;
        for (int i = 0; i < it->second.size(); i++) {
            cout << "- " << it->second[i] << endl;
        }
        cout << "-------------------" << endl;
    }
}