void free_user(User *user) {
    if (user == NULL) return;
    free(user->name);
    if (user->preferences) {
        for (int i = 0; user->preferences[i] != NULL; i++) {
            free(user->preferences[i]);
        }
        free(user->preferences);
    }
    if (user->interests) {
        for (int i = 0; user->interests[i] != NULL; i++) {
            free(user->interests[i]);
        }
        free(user->interests);
    }
    free(user);
}