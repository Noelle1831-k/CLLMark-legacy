shared_ptr<User> Network::findUser(const string& username) {
    for (auto& user : users) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    return nullptr;
}