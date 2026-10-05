User* create_user(const char *username, const char *email, const char *password) {
    User *user = (User*)malloc(sizeof(User));
    user->username = strdup(username);
    user->email = strdup(email);
    user->password = strdup(password);
    return user;
}