void freeUserProfile(UserProfile *user) {
    if (user) {
        free(user->name);
        free(user->email);
        free(user);
    }
}