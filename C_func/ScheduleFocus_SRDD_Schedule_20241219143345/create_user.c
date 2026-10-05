User *create_user(const char *name) {
    User *user = (User *)malloc(sizeof(User));
    strcpy(user->name, name);
    user->focus_interval = 25;
    return user;
}