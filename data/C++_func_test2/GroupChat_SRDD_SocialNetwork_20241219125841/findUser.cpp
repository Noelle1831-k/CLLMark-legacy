User* GroupChatApp::findUser(const string& username) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i]->getUsername() == username) return users[i];
    }
    return nullptr;
}