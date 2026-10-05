void GroupChatApp::registerUser(const string& username) {
    User* newUser = new User(username);
    users.push_back(newUser);
}