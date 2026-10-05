void ConnectionManager::connectUsers(const User& user1, const User& user2) {
    connections[user1.getName()].push_back(user2.getName());
    connections[user2.getName()].push_back(user1.getName());
}