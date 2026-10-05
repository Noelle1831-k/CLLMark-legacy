User *create_user(const char *name, const char *interests, const char *hobbies) {
    User *user = (User *)malloc(sizeof(User));
    if (!user) {
        fprintf(stderr, "Memory allocation failed for user.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(user->name, name, sizeof(user->name) - 1);
    user->name[sizeof(user->name) - 1] = '\0';
    strncpy(user->interests, interests, sizeof(user->interests) - 1);
    user->interests[sizeof(user->interests) - 1] = '\0';
    strncpy(user->hobbies, hobbies, sizeof(user->hobbies) - 1);
    user->hobbies[sizeof(user->hobbies) - 1] = '\0';
    return user;
}