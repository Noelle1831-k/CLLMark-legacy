void addRequestToUser(Database *db, const char *username, Request *request) {
    User *user = findUser(db, username);
    if (user) {
        addRequest(user, request);
    }
}