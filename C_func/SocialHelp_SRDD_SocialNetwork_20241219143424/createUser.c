User* createUser(const char *username) {
    User *user = (User *)malloc(sizeof(User));
    strcpy(user->username, username);
    user->skillCount = 0;
    user->requestCount = 0;
    return user;
}