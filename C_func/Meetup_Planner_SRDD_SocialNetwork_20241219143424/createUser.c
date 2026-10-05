User* createUser(const char *name, const char *email) {
    User *user = (User *)malloc(sizeof(User));
    user->name = strdup(name);
    user->email = strdup(email);
    user->events = NULL;
    return user;
}