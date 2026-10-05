void freeUser(User *user) {
    free(user->name);
    free(user->preferences);
    free(user->history);
    free(user);
}