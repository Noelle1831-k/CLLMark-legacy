void save_user(const User *user) {
    if (user == NULL) return;
    printf("Saving user: %s (ID: %d)\n", user->name, user->id);
}