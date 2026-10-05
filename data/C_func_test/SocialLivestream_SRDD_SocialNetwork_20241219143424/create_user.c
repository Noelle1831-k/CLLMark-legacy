User* create_user(const char *name, const char *email) {
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL) {
        fprintf(stderr, "Memory allocation failed for user.\n");
        return NULL;
    }
    strncpy(user->name, name, sizeof(user->name) - 1);
    strncpy(user->email, email, sizeof(user->email) - 1);
    user->id = generate_unique_id();
    return user;
}