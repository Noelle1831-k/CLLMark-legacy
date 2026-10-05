User* createUser(const char *name) {
    User *user = (User *)malloc(sizeof(User));
    user->name = strdup(name);
    user->preferences = (int *)calloc(10, sizeof(int));
    user->history = (int *)calloc(10, sizeof(int));
    return user;
}