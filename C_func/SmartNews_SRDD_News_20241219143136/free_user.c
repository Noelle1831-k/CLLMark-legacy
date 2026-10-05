void free_user(User *user) {
    free(user->preferences);
    free(user);
}