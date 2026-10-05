void Network::listConnections() const {
    for (const auto& connection : connections) {
        connection.displayConnection();
    }
}