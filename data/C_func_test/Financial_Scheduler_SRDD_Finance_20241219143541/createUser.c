User *createUser(const char *name) {
    User *user = (User *)malloc(sizeof(User));
    user->name = strdup(name);
    user->transactions = NULL;
    user->transactionCount = 0;
    return user;
}