optional<User> Database::getUser(int userId) const {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == userId) {
            return users[i];
        }
    }
    return nullopt; 
}