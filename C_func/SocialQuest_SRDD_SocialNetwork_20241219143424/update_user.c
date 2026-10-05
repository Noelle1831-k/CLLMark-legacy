void update_user(User *user, const char *username, const char *email, const char *password) {
    free(user->username);
    free(user->email);
    free(user->password);
    user->username = strdup(username);
    user->email = strdup(email);
    user->password = strdup(password);
}