void Network::viewConnections() {
    cout << "Viewing connections..." << endl;
    cout << "Connections: " << endl;
    for (int i = 0; i < connections.size(); i++) {
        cout << "- " << connections[i] << endl;
    }
}