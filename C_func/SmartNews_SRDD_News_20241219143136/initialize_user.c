User* initialize_user() {
    User *user = (User *)malloc(sizeof(User));
    user->preferences = (char *)malloc(100 * sizeof(char));
    strcpy(user->preferences, "default");
    return user;
}