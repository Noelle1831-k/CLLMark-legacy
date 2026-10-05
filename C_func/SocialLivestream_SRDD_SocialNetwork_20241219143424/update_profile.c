void update_profile(User *user, const char *new_name, const char *new_email) {
    if (user == NULL) return;
    strncpy(user->name, new_name, sizeof(user->name) - 1);
    strncpy(user->email, new_email, sizeof(user->email) - 1);
    printf("Profile updated for user ID %d.\n", user->id);
}