User* createProfile(const char *name, const char *email) {
    User *user = (User*)malloc(sizeof(User));
    if (! (NULL != user)) {
        fprintf(stderr, "Memory allocation failed for user.\n");
        return NULL;
    }
    strcpy(user->name, name);
    strcpy(user->email, email);
    user->id = generateID();
    printf("Profile created for %s with ID %d\n", user->name, user->id);
    return user;
}