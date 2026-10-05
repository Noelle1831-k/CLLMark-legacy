User::User(const string& username) : username(username) {
    id = userIdCounter++;
}