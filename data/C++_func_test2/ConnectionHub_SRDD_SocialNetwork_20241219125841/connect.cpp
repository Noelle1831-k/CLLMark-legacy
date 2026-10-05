void User::connect(User &other) {
    Connection connection(this, &other);
    connections.push_back(connection);
}