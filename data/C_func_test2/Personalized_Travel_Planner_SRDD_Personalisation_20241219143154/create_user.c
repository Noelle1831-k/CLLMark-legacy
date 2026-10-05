User* create_user(char *name, char **preferences, char **interests) {
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL) {
        fprintf(stderr, "Failed to allocate memory for user.\n");
        return NULL;
    }
    user->name = strdup(name);
    if (user->name == NULL) {
        fprintf(stderr, "Failed to allocate memory for user name.\n");
        free(user);
        return NULL;
    }
    user->preferences = preferences;
    user->interests = interests;
    return user;
}